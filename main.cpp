#include <iostream>
#include <cstring>

class Animal{
protected:
    char _hairColor[10];
    int _hairLength, _tail, _weight, _height, _age;
    int _intelligence, _stubbornness, _agressiveness;

public:
    virtual Animal *clone() = 0;

    void setHairColor(const char * color) { strcpy(_hairColor, color); }
    void setHairLength(int val) { _hairLength = val; }
    void setTail(int val) { _tail = val; }
    void setWeight(int val) { _weight = val; }
    void setHeight(int val) { _height = val; }
    void setAge(int val) { _age = val; }
    void setIntelligence(int val) { _intelligence = val; }
    void setStubbornness(int val) { _stubbornness = val; }
    void setAgressiveness(int val) { _agressiveness = val; }

    const char* getHairColor() { return _hairColor; }
    int getHairLength() { return _hairLength; }
    int getTail() { return _tail; }
    int getWeight() { return _weight; }
    int getHeight() { return _height; }
    int getAge() { return _age; }
    int getIntelligence() { return _intelligence; }
    int getStubbornness() { return _stubbornness; }
    int getAgressiveness() { return _agressiveness; }

};

class Sheep : public Animal {
public:
    Sheep(){
        _hairLength = 5;
        _stubbornness = 3;
        _agressiveness = 2;
        _intelligence = 7;
    }
    Sheep* clone() { return new Sheep(*this); }
    void sheering(){ _hairLength -= 2; }
};

class Cow : public Animal {
public:
    Cow(){
        _stubbornness = 3;
        _agressiveness = 2;
        _intelligence = 7;
    }
    Cow* clone() { return new Cow(*this); }
};

int main(){
    Sheep* sheep0 = new Sheep;
    sheep0->setHairColor("white");
    sheep0->setTail(5);
    sheep0->setWeight(90);
    sheep0->setHeight(1);
    sheep0->setAge(5);

    Cow* cow0 = new Cow;
    cow0->setHairColor("white");
    cow0->setTail(5);
    cow0->setWeight(90);
    cow0->setHeight(1);
    cow0->setAge(5);

    Animal *farm[3];
    farm[0] = sheep0->clone();
    farm[1] = cow0->clone();
    farm[1]->setWeight(100);
    sheep0->sheering();
    farm[2] = sheep0->clone();

    std::cout << "Done\n";
    return 0;
}


// #include <iostream>
// #include <string>
// #include <unordered_map>

// using namespace std;

// enum Type {
//   PROTOTYPE_1 = 0,
//   PROTOTYPE_2
// };

// class Prototype
// {
//   protected:
//   string prototype_name_;
//   float prototype_field_;

//   public:
//   Prototype() {}
//   Prototype(string prototype_name)
//   :prototype_name_(prototype_name) {}
//   virtual ~Prototype() {}

//   virtual Prototype *Clone() const = 0;
//   virtual void Method(float prototype_field) {
//       this->prototype_field_ = prototype_field;
//       cout<<"Call Method from " <<prototype_name_
//       <<" with field : " << prototype_field <<endl;
//   }
// };

// class ConcretePrototype1: public Prototype
// {
//     private:
//     float concrete_prototype_field1_;

//     public:
//     ConcretePrototype1(string prototype_name, 
//         float concrete_prototype_field): 
//         Prototype(prototype_name), 
//         concrete_prototype_field1_(concrete_prototype_field) {}

//     Prototype *Clone() const override {
//         return new ConcretePrototype1(*this);
//     }
// };

// class ConcretePrototype2: public Prototype
// {
//     private:
//     float concrete_prototype_field2_;

//     public:
//     ConcretePrototype2(string prototype_name,
//     float concrete_prototype_field)
//     : Prototype(prototype_name), concrete_prototype_field2_(concrete_prototype_field){}

//     Prototype *Clone() const override {
//         return new ConcretePrototype2(*this);
//     }

// };

// class PrototypeFactory 
// {
//     private:
//     unordered_map<Type, Prototype *, hash<int>> prototypes_;

//     public:
//     PrototypeFactory() {
//         prototypes_[Type::PROTOTYPE_1] = 
//             new ConcretePrototype1("PROTOTYPE_1 ", 50.f);
//         prototypes_[Type::PROTOTYPE_2] = 
//             new ConcretePrototype2("PROTOTYPE_2 ", 60.f);
//     }

//     ~PrototypeFactory() {
//         delete prototypes_[Type::PROTOTYPE_1];
//         delete prototypes_[Type::PROTOTYPE_2];
//     }

//     Prototype *CreatePrototype(Type type) {
//         return prototypes_[type]->Clone();
//     }
// };

// void Client(PrototypeFactory &prototype_factory)
// {
//     cout << "Let's create a Prototype 1\n";

//     Prototype *prototype = 
//         prototype_factory.CreatePrototype(Type::PROTOTYPE_1);
//     prototype->Method(90);

//     cout << endl;
//     cout << "Let's create a Prototype 2 \n";
    
//     prototype = 
//         prototype_factory.CreatePrototype(Type::PROTOTYPE_2);
//     prototype->Method(10);

//     delete prototype;
// }

// int main()
// {
//     PrototypeFactory *prototype_factory =
//         new PrototypeFactory();
    
//     Client(*prototype_factory);
//     delete prototype_factory;
    
//     return 0;
// }
