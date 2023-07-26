/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package test.test2;

/**
 *
 * @author aleksandarhardi
 */
public class Test2 {
    
    static {
        System.loadLibrary("JNI_Cpp");
    }
    
    public native double avg(double a, double b);
    
    public static void main(String[] args) {
        Test2 test = new Test2();
        
        double result = test.avg(2,3);
        System.out.println(result);
    }
    
}
