package org.example;

import java.util.Arrays;

public class Number {

    public static double findSmallestNumber(double param1, double param2, double param3) {
        double[] doubleArray = {param1, param2, param3};
        Arrays.sort(doubleArray);
        return doubleArray[doubleArray.length - 1];
    }

    public static void main(String[] args) {

    }
}