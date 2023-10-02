// Parent class
class Animal {
    void sound() {
        System.out.println("Animal makes a sound");
    }
}

// Subclass 1
class Dog extends Animal {
    @Override
    void sound() {
        System.out.println("Dog barks");
    }
}

// Subclass 2
class Cat extends Animal {
    @Override
    void sound() {
        System.out.println("Cat meows");
    }
}

public class PolymorphismExample {
    public static void main(String[] args) {
        // Create objects of different subclasses
        Animal animal1 = new Dog();
        Animal animal2 = new Cat();

        // Demonstrate polymorphism by calling the 'sound' method on both objects
        animal1.sound(); // This will call Dog's 'sound' method
        animal2.sound(); // This will call Cat's 'sound' method
    }
}
