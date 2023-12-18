#include <iostream>
#include <string>

class Animal {
public:
    std::string name;
    std::string type; 
    int age;
    std::string sound;

    Animal(std::string name, std::string type, int age, std::string sound) : 
        name(name), type(type), age(age), sound(sound) {}

    void makeSound() {
        std::cout << name << ' ' << sound << std::endl;
    }

    void sleep() {
        std::cout << name << " the " << type << " is sleeping Zzz" << std::endl;
    }

    void eat() {
        std::cout << name << " the " << type << " is eating" << std::endl;
    }

    virtual void showInfo() {
        std::cout << "Type: " << type << std::endl; 
        std::cout << "Name: " << name << std::endl;
        std::cout << "Age: " << age << std::endl;
        std::cout << "Sound: " << sound << std::endl;
    }

    virtual ~Animal() {}
};


class Elephant : public Animal {
public:
    float tuskLength;
    bool isAfrican;
    std::string color;

    Elephant(std::string name, int age, std::string color, float tuskLength, bool isAfrican) : 
        Animal(name, "Elephant", age, "trumpets"), tuskLength(tuskLength), isAfrican(isAfrican), color(color) {}

    void sprayWater() {
        std::cout << name << " the " << type << " is spraying water" << std::endl;
    }

    void flapEars() {
        std::cout << name << " the " << type << " is flapping ears" << std::endl;
    }

    void showInfo() override {
        Animal::showInfo();
        std::cout << "Tusk Length: " << tuskLength << " meters" << std::endl;
        std::cout << "African: " << (isAfrican ? "Yes" : "No") << std::endl;
        std::cout << "Color: " << color << std::endl;
    }

    ~Elephant() override {
        std::cout << name << " the " << type << " left the zoo" << std::endl;
    }
};

class Lion : public Animal {
public:
    bool isMale;
    int maneSize;

    Lion(std::string name, int age, bool isMale, int maneSize) : 
        Animal(name, "Lion", age, "roars"), isMale(isMale), maneSize(maneSize) {}

    void roar() {
        std::cout << name << " the " << type << " is roaring" << std::endl;
    }

    void hunt() {
        std::cout << name << " the " << type << " is hunting" << std::endl;
    }

    void showInfo() override {
        Animal::showInfo();
        std::cout << "Gender: " << (isMale ? "Male" : "Female") << std::endl;
        std::cout << "Size: " << maneSize << " meters" << std::endl;
    }

    ~Lion() override {
        std::cout << name << " the " << type << " left the zoo" << std::endl;
    }
};

class Monkey : public Animal {
public:
    std::string color;
    bool canClimb;

    Monkey(std::string name, int age, std::string color, bool canClimb) : 
        Animal(name, "Monkey", age, "chatters"), color(color), canClimb(canClimb) {}

    void swing() {
        std::cout << name << " the " << type << " is swinging in the trees" << std::endl;
    }

    void play() {
        std::cout << name << " the " << type << " is playing with a friend" << std::endl;
    }

    void showInfo() override {
        Animal::showInfo();
        std::cout << "Color: " << color << std::endl;
        std::cout << "Can Climb: " << (canClimb ? "Yes" : "No") << std::endl;
    }

    ~Monkey() override {
        std::cout << name << " the " << type << " left the zoo" << std::endl;
    }
};

int main() {
    Animal* zoo[3];
    zoo[0] = new Elephant("Dumbo", 7, "grey", 2.5, false);
    zoo[1] = new Lion("Simba", 5, true, 10);
    zoo[2] = new Monkey("Peter", 4, "brown", true);

    for (int i = 0; i < 3; ++i) {
        zoo[i]->showInfo();
        zoo[i]->makeSound();
        zoo[i]->eat();
        zoo[i]->sleep();
     
        if (Elephant* ele = dynamic_cast<Elephant*>(zoo[i])) {
            ele->sprayWater();
            ele->flapEars();
        } else if (Lion* lion = dynamic_cast<Lion*>(zoo[i])) {
            lion->roar();
            lion->hunt();
        } else if (Monkey* monkey = dynamic_cast<Monkey*>(zoo[i])) {
            monkey->swing();
            monkey->play();
        }
        std::cout << std::endl;
    }
    for (int i = 0; i < 3; ++i) {
        delete zoo[i];
    }

    return 0;
}
