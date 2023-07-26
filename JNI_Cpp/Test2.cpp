// Native methods implementation of
// /Users/aleksandarhardi/Desktop/JNI/JNI_Java/src/test/test2/Test2.java

#include "Test2.h"

jdouble JNICALL Java_test_test2_Test2_avg
  (JNIEnv * env, jobject object, jdouble param1, jdouble param2) {
    return (param1 + param2) / 2;
}
