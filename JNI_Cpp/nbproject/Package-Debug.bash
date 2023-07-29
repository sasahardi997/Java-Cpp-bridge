#!/bin/bash -x

#
# Generated - do not edit!
#

# Macros
TOP=`pwd`
CND_PLATFORM=GNU-MacOSX
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build
CND_DLIB_EXT=dylib
NBTMPDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tmp-packaging
TMPDIRNAME=tmp-packaging
OUTPUT_PATH=${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libJNI_Cpp.${CND_DLIB_EXT}
OUTPUT_BASENAME=libJNI_Cpp.${CND_DLIB_EXT}
PACKAGE_TOP_DIR=libJNICpp.dylib/

# Functions
function checkReturnCode
{
    rc=$?
    if [ $rc != 0 ]
    then
        exit $rc
    fi
}
function makeDirectory
# $1 directory path
# $2 permission (optional)
{
    mkdir -p "$1"
    checkReturnCode
    if [ "$2" != "" ]
    then
      chmod $2 "$1"
      checkReturnCode
    fi
}
function copyFileToTmpDir
# $1 from-file path
# $2 to-file path
# $3 permission
{
    cp "$1" "$2"
    checkReturnCode
    if [ "$3" != "" ]
    then
        chmod $3 "$2"
        checkReturnCode
    fi
}

# Setup
cd "${TOP}"
mkdir -p /Users/aleksandarhardi/Desktop/JNI/JNI_Java_Maven/src/main/resources
rm -rf ${NBTMPDIR}
mkdir -p ${NBTMPDIR}

# Copy files and create directories and links
cd "${TOP}"
makeDirectory "${NBTMPDIR}/libJNICpp.dylib/lib"
copyFileToTmpDir "/Users/aleksandarhardi/Desktop/JNI/JNI_Java_Maven/src/main/resources/libJNICpp.dylib" "${NBTMPDIR}/libJNICpp.dylib/lib/libJNI_Cpp.dylib" 0644

cd "${TOP}"
makeDirectory "${NBTMPDIR}/libJNICpp.dylib/lib"
copyFileToTmpDir "${OUTPUT_PATH}" "${NBTMPDIR}/${PACKAGE_TOP_DIR}lib/${OUTPUT_BASENAME}" 0644

cd "${TOP}"
makeDirectory "${NBTMPDIR}/libJNICpp.dylib/lib"
copyFileToTmpDir "${OUTPUT_PATH}" "${NBTMPDIR}/${PACKAGE_TOP_DIR}lib/${OUTPUT_BASENAME}" 0644


# Generate tar file
cd "${TOP}"
rm -f /Users/aleksandarhardi/Desktop/JNI/JNI_Java_Maven/src/main/resources/libJNICpp.dylib.tar
cd ${NBTMPDIR}
tar -vcf /Users/aleksandarhardi/Desktop/JNI/JNI_Java_Maven/src/main/resources/libJNICpp.dylib.tar *
checkReturnCode

# Cleanup
cd "${TOP}"
rm -rf ${NBTMPDIR}
