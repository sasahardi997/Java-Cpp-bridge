package test;

/**
 *
 * @author aleksandarhardi
 */
public class Test1 {
    
    static {
        System.loadLibrary("JNI_Cpp");
    }
    
    private static native double multiply(double a, double b);
    
    public static void main(String[] args) {
        double result = multiply(1.1, 2.2);
        System.out.println(result);
    }

}

