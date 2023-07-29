/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.h to edit this template
 */

#include <jni.h>

/* 
 * File:   TestMaven.h
 * Author: aleksandarhardi
 *
 * Created on July 28, 2023, 3:54 PM
 */

#ifndef TESTMAVEN_H
#define TESTMAVEN_H

#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT jdouble JNICALL Java_org_TestMaven_multiply
  (JNIEnv *, jclass, jdouble, jdouble);


#ifdef __cplusplus
}
#endif

#endif /* TESTMAVEN_H */

