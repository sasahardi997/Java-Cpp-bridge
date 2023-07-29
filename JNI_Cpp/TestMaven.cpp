/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "TestMaven.h"
#include <string>

JNIEXPORT jdouble JNICALL Java_org_TestMaven_multiply
  (JNIEnv * jvm, jclass clazz, jdouble param1, jdouble param2) {
    return param1 * param2;
}