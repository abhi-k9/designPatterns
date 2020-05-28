/** @file  : AbsFactory.cpp
  * @author: Abhijit Kale  
  * @date  : 27th May 2020
  */

# include <iostream>
# include <string>

using namespace std;

/// @brief Base Door class
class Door {
public:
    Door(){}
    virtual void Open() = 0;

};

/// @brief Concrete Door class
class GasCarDoor : public Door {
public:

    GasCarDoor() {
        cout << "Making a door for a gas car." << endl;
    }

    void Open() override {
        cout << "Opening *Click*" << endl;
    }

};

/// @brief Concrete Door class
class ElectricCarDoor : public Door {
public:

    ElectricCarDoor() {
        cout << "Making a door for a electric car." << endl;
    }

    void Open() override {
        cout << "Opening *shhhhh*" << endl;
    }

};

/// @brief Base Engine class
class Engine {
protected:
    string _sound;

public:
    Engine(string s): _sound(s){}
    virtual void Run() = 0;

};

/// @brief Concrete Engine class
class GasEngine : public Engine {
public:

    GasEngine(): Engine("*VROOM*") {
        cout << "Making an engine for a gas car." << endl;
    }

    void Run() override {
        cout << _sound << endl;
    }

};


/// @brief Concrete Engine class
class ElectricEngine : public Engine {
public:

    ElectricEngine(): Engine("*SHHHH*") {
        cout << "Making an engine for a electric car." << endl;
    }

    void Run() override {
        cout << _sound << endl;
    }

};

/// @brief Abstract CarFactory
class CarFactory {
public:
    virtual Door* buildDoor() = 0;
    virtual Engine* buildEngine() = 0;
};

/// @brief Concrete gas car factory
class GasCarFactory: public CarFactory {
public:
    Door* buildDoor() override{
        return new GasCarDoor();
    }

    Engine* buildEngine() override{
        return new GasEngine();
    }

};

/// @brief Concrete electric car factory
class ElectricCarFactory: public CarFactory {
public:
    Door* buildDoor() override{
        return new ElectricCarDoor();
    }

    Engine* buildEngine() override{
        return new ElectricEngine();
    }

};

int main(){

    CarFactory *car_plant;
    int choice = 0;

    cout << "Select a car type:\n"
        << "1: Gasoline\n" << "2: Electric\n"
        << "Selection: " << flush;

    cin >> choice;
    cout << endl;

    switch(choice) {

        case 1:
            car_plant = new GasCarFactory();
            break;

        case 2:
            car_plant = new ElectricCarFactory();
            break;

        default:
            cout << "Invalid Selection!" << endl;
            car_plant = nullptr;

    }

    if(car_plant) {

        Door *myDoor = car_plant->buildDoor();
        Engine *myEngine = car_plant->buildEngine();

        myDoor->Open();
        myEngine->Run();

    }
}