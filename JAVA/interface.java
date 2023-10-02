// Parent interface
interface Animal {
    void sound();
}

// Child interface inheriting from the parent interface
interface Pet extends Animal {
    void play();
}

// Concrete class implementing the Pet interface
class Dog implements Pet {
    @Override
    public void sound() {
        System.out.println("Dog barks");
    }

    @Override
    public void play() {
        System.out.println("Dog plays fetch");
    }
}

public class InterfaceInheritanceExample {
    public static void main(String[] args) {
        Pet myPet = new Dog();

        // Call methods defined in the Pet interface
        myPet.sound();
        myPet.play();
    }
}
