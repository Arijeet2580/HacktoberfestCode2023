// 1. Class Declaration
class Person {
    // 2. Instance Variables (Attributes)
    private String name;
    private int age;

    // 3. Constructor
    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    // 4. Encapsulation: Getters and Setters
    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        if (age >= 0) {
            this.age = age;
        }
    }

    // 5. Inheritance: Inheriting from Object class by default

    // 6. Method (Behavior)
    public void introduce() {
        System.out.println("Hello, my name is " + name + " and I am " + age + " years old.");
    }

    // 7. Polymorphism: Method Overriding
    @Override
    public String toString() {
        return "Person [name=" + name + ", age=" + age + "]";
    }

    // 8. Abstraction: Abstract Method
    public abstract void work();

    // 9. Interface Implementation
    public class Programmer extends Person implements Employee {
        private String programmingLanguage;

        public Programmer(String name, int age, String programmingLanguage) {
            super(name, age);
            this.programmingLanguage = programmingLanguage;
        }

        @Override
        public void work() {
            System.out.println("I am a programmer, and I code in " + programmingLanguage);
        }

        @Override
        public void getSalary() {
            System.out.println("I get paid for coding.");
        }
    }

    // 10. Interface Declaration
    interface Employee {
        void getSalary();
    }

    public static void main(String[] args) {
        // Creating an object
        Person person = new Person("Alice", 30);

        // Using methods and accessing attributes
        person.introduce();

        // Using toString method
        System.out.println(person);

        // Creating an object of the subclass
        Programmer programmer = new Programmer("Bob", 25, "Java");

        // Using method overridden from the superclass
        programmer.introduce();

        // Using method overridden from the interface
        programmer.work();
        programmer.getSalary();
    }
}
