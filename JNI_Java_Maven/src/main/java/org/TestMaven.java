package org;
public class TestMaven {
    
    static {
        System.setProperty(
                "java.library.path",
                "/Users/aleksandarhardi/Desktop/JNI/JNI_Java_Maven/src/main/resources");
        System.out.println(System.getProperty("java.library.path"));
        System.loadLibrary("JNI_Cpp");
    }

//    public static native double multiply(double x, double y);

    public static void main(String[] args) {
//        double result = multiply(1.1, 2.2);
//        System.out.println(result);
        System.out.println("Hello World");
    }
}