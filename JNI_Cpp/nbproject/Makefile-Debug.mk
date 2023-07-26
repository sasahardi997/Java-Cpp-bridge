#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-MacOSX
CND_DLIB_EXT=dylib
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/9071aebf/Test1.o \
	${OBJECTDIR}/_ext/9071aebf/Test2.o


# C Compiler Flags
CFLAGS=-m64

# CC Compiler Flags
CCFLAGS=-m64
CXXFLAGS=-m64

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libJNI_Cpp.${CND_DLIB_EXT}

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libJNI_Cpp.${CND_DLIB_EXT}: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libJNI_Cpp.${CND_DLIB_EXT} ${OBJECTFILES} ${LDLIBSOPTIONS} -dynamiclib -install_name libJNI_Cpp.${CND_DLIB_EXT} -fPIC

${OBJECTDIR}/_ext/9071aebf/Test1.o: /Users/aleksandarhardi/Desktop/JNI/JNI_Cpp/Test1.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/9071aebf
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../../Library/Java/JavaVirtualMachines/azul-1.8.0_372/Contents/Home/include -I../../../Library/Java/JavaVirtualMachines/azul-1.8.0_372/Contents/Home/include/darwin -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/9071aebf/Test1.o /Users/aleksandarhardi/Desktop/JNI/JNI_Cpp/Test1.cpp

${OBJECTDIR}/_ext/9071aebf/Test2.o: /Users/aleksandarhardi/Desktop/JNI/JNI_Cpp/Test2.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/9071aebf
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../../Library/Java/JavaVirtualMachines/azul-1.8.0_372/Contents/Home/include -I../../../Library/Java/JavaVirtualMachines/azul-1.8.0_372/Contents/Home/include/darwin -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/9071aebf/Test2.o /Users/aleksandarhardi/Desktop/JNI/JNI_Cpp/Test2.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
