Communication between C++ and Java using JNI (Java native interface).

Example:

//*************** ACCESS STATIC METHOD ***************
void JNICALL Java_test_TestDynamic_printPersonInfoStatic    
    (JNIEnv * env, jobject clazz, jstring name, jint age) {

    //find a class
    static jclass person_class = env -> FindClass("test/Person");
    
    jmethodID methodID = env -> GetStaticMethodID(person_class, "getInfo", "(Ljava/lang/String;I)Ljava/lang/String;");

    //get the return value (Object)
    //set the method params(String as parameter, age set manually)
    jobject obj = env -> CallStaticObjectMethod(person_class, methodID, name, 39);
    
    //cast the object (to string type_
    jstring info = (jstring) obj;

    //print
    const char* info_array = env -> GetStringUTFChars(info, 0);
    printf("%s\n", info_array);

    // Release the native heap (clean the memory)
    env->ReleaseStringUTFChars(info, info_array);
}

--------------------

private static void testMethod() throws NoSuchMethodException, InvocationTargetException, IllegalAccessException {
    Person person = new Person("Aleksandar");

    Class<?> clazz = person.getClass();

    //Without params
    Method getNameMethod = clazz.getMethod("getName");
    Object obj = getNameMethod.invoke(person);
    String name = (String) obj;
    System.out.println(name);

    //With params (int age)
    Method getInfoMethod = clazz.getMethod("getInfo", int.class);
    Object getInfoObject = getInfoMethod.invoke(person, 26);
    String info = (String) getInfoObject;
    System.out.println(info);
}
