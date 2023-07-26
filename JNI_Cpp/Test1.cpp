// Native methods implementation of
// /Users/aleksandarhardi/Desktop/JNI/JNI_Java/src/test/Test1.java

#include "Test1.h"

jdouble JNICALL Java_test_Test1_multiply
  (JNIEnv * env, jclass object, jdouble param1, jdouble param2) {
    return param1 * param2;
}
