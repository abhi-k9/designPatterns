/** @file : Composition.cpp
  * @author: Abhijit Kale  
  * @date: 27th May 2020
  */

#include <iostream>
#include <string>

using namespace std;

/// @brief Product from which concrete products will inherit
class Coffee {

protected:
    string _type;
 
public:
    
    Coffee(){};

    string getType(){
        return _type;
    }
};

/// @brief Espresso concrete class
class Espresso: public Coffee {

public:
    
    Espresso(): Coffee() {
        _type = "Espresso"; // TODO: Base should init its own members
        cout << "\n Making a cup of espresso\n";
        cout << "Grind and brew one scoop of espresso beans" << endl;
    }

};

/// @brief Cappuccino concrete class
class Cappuccino: public Coffee {

public:
    
    Cappuccino(): Coffee() {
        _type = "Cappuccino"; // TODO: Base should init its own members
        cout << "\nMaking a cup of cappuccino\n";
        cout << "Grind and brew one scoop of espresso beans\n"; 
        cout << "Heat and foam milk." << endl;
    }

};

class CoffeeMakerFactory{

private:
    Coffee *_coffee;

public:
    
    Coffee * GetCoffee(){

        int choice = 0;

        cout << "Select type of coffee to make: \n"
             << "1: Espresso\n" << "2: Cappuccino" << endl;

        cout << "Selection: " << flush;

        cin >> choice;

        // Replace with a map data structure. Editable at runtime.
        switch(choice){

            case 1:
                return new Espresso;
                break;

            case 2:
                return new Cappuccino;
                break;

            default:
                cout << "Invalid selecteion!" << endl;
                return nullptr;

        }

    }

};

int main(){

    CoffeeMakerFactory coffeeMachine;
    Coffee *cup;

    cup = coffeeMachine.GetCoffee();

    cout << "\nYou have asked for a(n) " << cup->getType() << endl;

}