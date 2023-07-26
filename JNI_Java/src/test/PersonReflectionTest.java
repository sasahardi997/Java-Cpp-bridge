package test;

import java.lang.reflect.Field;

public class PersonReflectionTest {

    public static void main(String[] args) throws NoSuchFieldException, IllegalAccessException {
        testObject();
        testStaticField();
    }

    public static void testObject() throws NoSuchFieldException, IllegalAccessException {
        Person person = new Person("Bob");

        Class<?> clazz = person.getClass();

        //Default field
        Field defaultField = clazz.getDeclaredField("name");
        System.out.println(defaultField.get(person));
        defaultField.set(person, "Aleks");
        System.out.println("Changed name: " + defaultField.get(person));

        //Private field
        Field privateField = clazz.getDeclaredField("age");
        privateField.setAccessible(true);
        System.out.println(privateField.get(person));
    }

    public static  void testStaticField() throws NoSuchFieldException, IllegalAccessException {
        Person person = new Person("Aleks");
        Person.address = "Nikole Tesle 82a";

        Class<?> clazz = person.getClass();

        Field staticField = clazz.getDeclaredField("address");
        System.out.println(staticField.get(clazz));
    }
}
