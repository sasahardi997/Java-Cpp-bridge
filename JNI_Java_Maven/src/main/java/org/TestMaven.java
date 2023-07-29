package org;
public class TestMaven {
    
    static {
        System.setProperty(
                "java.library.path",
                "/Users/aleksandarhardi/Desktop/JNI/JNI_Cpp/dist/Debug/GNU-MacOSX");
        System.loadLibrary("JNI_Cpp");
    }

    public static native double multiply(double x, double y);

    public static void main(String[] args) {
        double result = multiply(1.1, 2.2);
        System.out.println(result);
    }
}