// Native methods implementation of
// /Users/aleksandarhardi/Desktop/JNI/JNI_Java/src/test/TestDynamic.java

#include "TestDynamic.h"
#include <string>
#include <iostream>

//*************** MULTIPLY ***************
jdouble JNICALL Java_test_TestDynamic_multiply
  (JNIEnv * env, jclass object, jdouble param1, jdouble param2) {
    return param1 * param2;
}

//*************** SUM ***************
jdouble JNICALL Java_test_TestDynamic_sum__DD
  (JNIEnv * env, jclass object, jdouble param1, jdouble param2) {
    return param1 + param2;
}

//*************** SUM 3 PARAMETERS ***************
jdouble JNICALL Java_test_TestDynamic_sum__DDD
  (JNIEnv * env, jclass object, jdouble param1, jdouble param2, jdouble param3) {
    return param1 + param2 + param3;
}

//*************** DIVIDE ***************
jdouble JNICALL Java_test_TestDynamic_divide
  (JNIEnv * env, jclass object, jdouble param1, jdouble param2) {
    return param1 / param2;
}

//*************** REVERSE ***************
jboolean JNICALL Java_test_TestDynamic_reverse__Z
  (JNIEnv * env, jclass object, jboolean param1) {
    return !param1;
}      

//*************** EQUALS ***************
jboolean JNICALL Java_test_TestDynamic_reverse__ZZ
  (JNIEnv * env, jclass object, jboolean param1, jboolean param2) {
    return !(param1 == param2);
} 

//*************** CREATE STRING IN CPP ***************
jstring JNICALL Java_test_TestDynamic_speak
  (JNIEnv * env, jclass object) {
    return env -> NewStringUTF("Aleksandree!");
}   

//*************** DOUBLE[] ***************
JNIEXPORT jdoubleArray JNICALL Java_test_TestDynamic_doubleArray
  (JNIEnv * env, jclass object) {
    jdouble cppArray[5];

    for (int i = 0; i < 5; i++) {
        cppArray[i] = i + 1; // Start from 1 to match the original intent
    }

    // Create a Java array
    jdoubleArray javaArray = env -> NewDoubleArray(5);
    
    //(java array, start from index, num of elements, cpp array)
    env->SetDoubleArrayRegion(javaArray, 0, 5, cppArray);
    return javaArray;
  }

//*************** ACCESS INSTANCE AND STATIC FIELD ***************
void JNICALL Java_test_TestDynamic_printPerson
    (JNIEnv * env, jobject clazz, jobject person) {

    //find class
    jclass personClass = env -> FindClass("test/Person");

    //find fieldID
    jfieldID fieldID = env -> GetFieldID(personClass, "name", "Ljava/lang/String;");

    //get field
    jobject nameObject = env -> GetObjectField(person, fieldID);

    //cast type
    jstring name = (jstring) nameObject;

    //print
    const char* name_array = env -> GetStringUTFChars(name, 0);
    printf("%s\n", name_array);
    
    //use setter to change the value
    jstring newName = env -> NewStringUTF("Aleksandar!");
    env -> SetObjectField(person, fieldID, newName);
    
    //Release the native heap(clean the memory)
    env -> ReleaseStringUTFChars(name, name_array);
   
        
// Find fieldID for "address" (since it's a static field)
    jfieldID addressFieldID = env -> GetStaticFieldID(personClass, "address", "Ljava/lang/String;");

    // Get the value of the "address" field (since it's static)
    jstring addressObject = (jstring )env -> GetStaticObjectField(personClass, addressFieldID);
    const char* address = env->GetStringUTFChars(addressObject, NULL);
    printf("Address: %s\n", address);

    // Release the native heap (clean the memory)
    env->ReleaseStringUTFChars(addressObject, address);
 }

 //*************** ACCESS INSTANCE METHOD ***************
void JNICALL Java_test_TestDynamic_printPersonName
    (JNIEnv * env, jobject clazz, jobject person) {
    
    //if we have instance of class (person f.e.)
    static jclass person_class = env -> GetObjectClass(person);
   
//    //If we don't have object, we can use the standard approach to find class
//    jclass personClass = env -> FindClass("test/Person");
    
    //Get method id
    jmethodID getNameID = env -> GetMethodID(person_class, "getName", "()Ljava/lang/String;");
    
    //get return value (Object)
    jobject obj = env -> CallObjectMethod(person, getNameID);
    
    //cast object to string
    jstring name = (jstring) obj;
    
    //print
    const char* name_array = env -> GetStringUTFChars(name, 0);
    printf("%s\n", name_array);
    
    //Release the native heap(cleanup the memory)
    env -> ReleaseStringUTFChars(name, name_array);
}

//*************** ACCESS INSTANCE METHOD ***************
void JNICALL Java_test_TestDynamic_printPersonInfo
    (JNIEnv * env, jobject clazz, jobject person) {

        //if we have instance of class (person f.e.)
    static jclass person_class = env -> GetObjectClass(person);
    
    //Get method id
    //(int parameter) method signature
    jmethodID getInfoID = env -> GetMethodID(person_class, "getInfo", "(I)Ljava/lang/String;");
    
    //get return value (Object)
    jobject obj = env -> CallObjectMethod(person, getInfoID, 26);
    
    //cast object to string
    jstring name = (jstring) obj;
    
    //print
    const char* name_array = env -> GetStringUTFChars(name, 0);
    printf("%s\n", name_array);
    
    //Release the native heap(cleanup the memory)
    env -> ReleaseStringUTFChars(name, name_array);
}

//*************** ACCESS STATIC METHOD ***************
void JNICALL Java_test_TestDynamic_printPersonInfoStatic    
    (JNIEnv * env, jobject clazz, jstring name, jint age) {

    //find class
    static jclass person_class = env -> FindClass("test/Person");
    
    jmethodID methodID = env -> GetStaticMethodID(person_class, "getInfo", "(Ljava/lang/String;I)Ljava/lang/String;");

    //get return value (Object)
    //set parameters to method(String as parameter, age set manually)
    jobject obj = env -> CallStaticObjectMethod(person_class, methodID, name, 39);
    
    //cast object to string
    jstring info = (jstring) obj;

    //print
    const char* info_array = env -> GetStringUTFChars(info, 0);
    printf("%s\n", info_array);

    // Release the native heap (clean the memory)
    env->ReleaseStringUTFChars(info, info_array);
}

//*************** ACCESS INTERFACE METHOD ***************
jdouble JNICALL Java_test_TestDynamic_callValue
    (JNIEnv * env, jclass clazz, jobject func, jdouble x) {
    
    //get the jclass of the interface
    jclass mathFunction_class = env -> FindClass("test/MathFunction");
    
    //get the method Id
    jmethodID methodID = env -> GetMethodID(mathFunction_class, "value", "(D)D");
    
    //call it
    jdouble result = env -> CallDoubleMethod(func, methodID, x);
    
    //return
    return result;
}   

//*************** ACCESS INTERFACE METHOD ***************
jdouble JNICALL Java_test_TestDynamic_callValueScaled
    (JNIEnv * env, jclass clazz, jobject func, jdouble x) {
    
    //get the jclass of the interface
    jclass mathFunction_class = env -> FindClass("test/MathFunction");
    
    //get the method Id
    jmethodID methodID = env -> GetMethodID(mathFunction_class, "valueScaled", "(D)D");
    
    //call it
    jdouble result = env -> CallDoubleMethod(func, methodID, x);
    
    //return
    return result;
} 

//*************** ACCESS INTERFACE METHOD ***************
jobject JNICALL Java_test_TestDynamic_callFunctionScaled
    (JNIEnv * env, jclass clazz, jobject func, jdouble x) {
    
    //get the jclass of the interface
    jclass mathFunction_class = env -> FindClass("test/MathFunction");
    
    //get the method Id
    jmethodID methodID = env -> GetStaticMethodID(mathFunction_class, "functionScaled", "(Ltest/MathFunction;)Ltest/MathFunction;");
    
    //call it
    jobject result = env -> CallStaticObjectMethod(mathFunction_class, methodID, func);
    
    //return
    return result;
} 

//*************** ACCESS CONSTRUCTOR AND CREATE OBJECT ***************
JNIEXPORT jobject JNICALL Java_test_TestDynamic_createPerson
    (JNIEnv * jvm, jclass clazz, jstring name, jint age) {
    
    //Find class of Person
    jclass personClass = jvm -> FindClass("test/Person");
    
    //Call constructor (special method, name of the constructor is always <init>)
    //L is used to specify that we are passing object (L:path)
    jmethodID constructorID = jvm -> GetMethodID(personClass, "<init>", "(Ljava/lang/String;I)V");
    
    //create new object
    jobject personObject = jvm -> NewObject(personClass, constructorID, name, age);
    return personObject;
}

//*************** RUN AUTOMATICALLY (Java Native Access) ***************
extern "C" JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved) {
    
    //It's printed in the first line (first run this method, and then the the rest)
    std::cout << "Hi from C++ with Java native access" << std::endl ;
    
    return JNI_VERSION_1_8;
}

//*************** USE THE CUSTOM JAR ***************
//The jar file must be added as modules(IntelliJ) and must be in RUNTIME to be available
//to the code outside of the project(Java_Jni)
//In apache netbeans it must be added to the classpath
JNIEXPORT void JNICALL Java_test_TestDynamic_triggerMethod
    (JNIEnv * jvm, jclass clazz) {
    
    //Get jclass
    jclass numberClass = jvm -> FindClass("org/example/Number");
    
    //Get methodID
    jmethodID findSmalletstNumberMethodID = jvm -> GetStaticMethodID(numberClass, "findSmallestNumber", "(DDD)D");
    
    //Create double values
    jdouble x = static_cast<jdouble>(3.14);
    jdouble y = static_cast<jdouble>(5.12);
    jdouble z = static_cast<jdouble>(3.11);
    
    //Call it
    jdouble smallestNumResult = jvm -> CallStaticDoubleMethod(numberClass, findSmalletstNumberMethodID, x, y, z);
    
    //Print
    std::cout << "The smallest number is: " << smallestNumResult << std::endl;
}
