package test;

@FunctionalInterface
public interface MathFunction {

    //Only one abstract method
    double value(double x);

    default double valueScaled(double x) {
        return value(x) * 5.0;
    }

    static MathFunction functionScaled(MathFunction func) {
        return x -> func.value(x) * 5.0;
    }
}
