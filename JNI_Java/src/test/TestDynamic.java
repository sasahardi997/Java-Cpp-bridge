package test;

import java.util.Arrays;
import org.example.Number;

/**
 *
 * @author aleksandarhardi
 * @run java -Djava.library.path=/Users/aleksandarhardi/Desktop/JNI/CppNative/dist/Debug/GNU-MacOSX -jar TestDynamic.jar
 */
public class TestDynamic extends SubClass{

    //To run jar, use: java -Djava.library.path=/Users/aleksandarhardi/Desktop/JNI/CppNative/dist/Debug/GNU-MacOSX -jar TestDynamic.jar
    
    public static final String OS = System.getProperty("os.name").toLowerCase();
    
    static {
        System.setProperty("java.library.path", "/Users/aleksandarhardi/Desktop/JNI/CppNative/dist/Debug/GNU-MacOSX");
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

    private static native void printPersonName(Person person);

    private static native void printPersonInfo(Person person);
    
    private static native void printPersonInfoStatic(String name, int age);
    
    //Interfaes
    private static native double callValue(MathFunction mathFunction, double x);
    
    private static native double callValueScaled(MathFunction mathFunction, double x);

    private static native MathFunction callFunctionScaled(MathFunction mathFunction, double x);
    
    //Constructor
    private static native Person createPerson(String name, int age);
    
    //Use custom jars
    private static native void triggerMethod();

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

        //Call methods
        Person alex = new Person("Alex");
        printPersonName(alex);
        printPersonInfo(alex);
        
        //Call static method
        printPersonInfoStatic("Baki Hanma", 33);

        //Interface
        MathFunction fun1 = x -> Math.sin(x);
        double javaResult = fun1.value(2.1);
        System.out.println("Java result: " + javaResult);

        double cppResult = callValue(fun1, 2.1);
        System.out.println("Cpp result: " + cppResult);
        
        double cppResult2 = callValueScaled(fun1, 2.1);
        System.out.println("Cpp call value scaled result: " + cppResult2);

        //Static interface
        fun1 = x -> 2.0 * x;
        MathFunction fun2 = MathFunction.functionScaled(fun1);
        System.out.println("Java result for fun2: " + fun2.value(2.1));

        MathFunction fun2Cpp = callFunctionScaled(fun1, 2.1);
        System.out.println("Cpp result  for fun2: " + fun2Cpp.value(2.1));
        
        //Constructor
        Person constructedPerson = createPerson("Muzan", 49);
        System.out.println(constructedPerson);
        
        //Use custom jars
        triggerMethod();
    }

    private static boolean isMac() {
        return OS.contains("mac");
    }
    private static boolean isWindows() {
        return OS.contains("win");
    }
    
}
