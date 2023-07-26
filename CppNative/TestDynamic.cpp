// Native methods implementation of
// /Users/aleksandarhardi/Desktop/JNI/JNI_Java/src/test/TestDynamic.java

#include "TestDynamic.h"
#include <string>

jdouble JNICALL Java_test_TestDynamic_multiply
  (JNIEnv * env, jclass object, jdouble param1, jdouble param2) {
    return param1 * param2;
}

jdouble JNICALL Java_test_TestDynamic_sum__DD
  (JNIEnv * env, jclass object, jdouble param1, jdouble param2) {
    return param1 + param2;
}

jdouble JNICALL Java_test_TestDynamic_sum__DDD
  (JNIEnv * env, jclass object, jdouble param1, jdouble param2, jdouble param3) {
    return param1 + param2 + param3;
}

jdouble JNICALL Java_test_TestDynamic_divide
  (JNIEnv * env, jclass object, jdouble param1, jdouble param2) {
    return param1 / param2;
}

jboolean JNICALL Java_test_TestDynamic_reverse__Z
  (JNIEnv * env, jclass object, jboolean param1) {
    return !param1;
}      

jboolean JNICALL Java_test_TestDynamic_reverse__ZZ
  (JNIEnv * env, jclass object, jboolean param1, jboolean param2) {
    return !(param1 == param2);
} 

jstring JNICALL Java_test_TestDynamic_speak
  (JNIEnv * env, jclass object) {
    return env -> NewStringUTF("Aleksandree!");
}   

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

