package main.java.org;

public class TestMaven {

    public static native double multiply(double x, double y);

    public static void main(String[] args) {
        double result = multiply(1.1, 2.2);
        System.out.println(result);
    }
}