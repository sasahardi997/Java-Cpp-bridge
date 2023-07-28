package test;

import java.lang.reflect.Constructor;
import java.lang.reflect.Field;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;

public class PersonReflectionTest {

    public static void main(String[] args) throws NoSuchFieldException, IllegalAccessException, InvocationTargetException, NoSuchMethodException, InstantiationException {
        testObject();
        testStaticField();
        testMethod();
        createPerson();
    }

    private static void createPerson() throws NoSuchMethodException, InvocationTargetException, InstantiationException, IllegalAccessException {
        Constructor<Person> constructor = Person.class.getDeclaredConstructor(String.class, int.class);
        Person person = constructor.newInstance("Marks", 49);
        System.out.println(person);
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
//        Person.address = "Nikole Tesle 82a";

        Class<?> clazz = person.getClass();

        Field staticField = clazz.getDeclaredField("address");
        System.out.println(staticField.get(clazz));
    }

    private static void testMethod() throws NoSuchMethodException, InvocationTargetException, IllegalAccessException {
        Person person = new Person("Aleksandar");

        Class<?> clazz = person.getClass();

        //Without params
        Method getNameMethod = clazz.getMethod("getName");
        Object obj = getNameMethod.invoke(person);
        String name = (String) obj;
        System.out.println(name);

        //With params (int age)
        Method getInfoMethod = clazz.getMethod("getInfo", int.class);
        Object getInfoObject = getInfoMethod.invoke(person, 26);
        String info = (String) getInfoObject;
        System.out.println(info);
    }
}
