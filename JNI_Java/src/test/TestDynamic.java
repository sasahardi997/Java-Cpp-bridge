package test;

import java.util.Arrays;

/**
 *
 * @author aleksandarhardi
 * @run java -Djava.library.path=/Users/aleksandarhardi/Desktop/JNI/CppNative/dist/Debug/GNU-MacOSX -jar TestDynamic.jar
 */
public class TestDynamic extends SubClass{

    //To run jar, use: java -Djava.library.path=/Users/aleksandarhardi/Desktop/JNI/CppNative/dist/Debug/GNU-MacOSX -jar TestDynamic.jar
    
    public static final String OS = System.getProperty("os.name").toLowerCase();
    
    static {
        System.loadLibrary("CppNative");
    }
    
    //Basic example
    private static native double multiply(double a, double b);
    
    //Overloading
    private static native double sum(double a, double b);
    
    private static native double sum(double a, double b, double c);

    //Overriding
    @Override
    public native double divide(double a, double b);
    
    //String
    private static native String speak();
    
    //Boolean
    private static native boolean reverse(boolean a);
    
    private static native boolean reverse(boolean a, boolean b);
    
    //Primitive array
    private static native double[] doubleArray();

    //Objects
    private static native void printPerson(Person person);
    
    public static void main(String[] args) {
        TestDynamic testDynamic = new TestDynamic();
        if(isMac()) {
            System.out.println("This is Mac operating system");
        } else if(isWindows()) {
            System.out.println("This is windows operating system");
        } else {
            System.out.println("Operating system is not supported");
        }

        double mResult = multiply(5, 1.5);
        System.out.println("multiply: " + mResult);
        
        double sResult = sum(5, 1.5);
        System.out.println("sum 2: " + sResult);
        
        double sResultThreeParams = sum(5, 1.5, 5);
        System.out.println("sum 3: " + sResultThreeParams);

        double divideResult = testDynamic.divide(10, 3);
        System.out.println("Divide: " + divideResult);
        
        System.out.println("String: " + speak());
        
        System.out.println("Boolean: " + reverse(false));
        
        System.out.println("Double array: " + Arrays.toString(doubleArray()));

        Person person = new Person("Bob");
        Person.address = "Nikole Teste 82a";
        printPerson(person);
        System.out.println("New name after the setter in cpp: " + person.getName());
        
    }

    private static boolean isMac() {
        return OS.contains("mac");
    }
    private static boolean isWindows() {
        return OS.contains("win");
    }
    
}
