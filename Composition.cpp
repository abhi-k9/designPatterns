/** @file : Composition.cpp
  * @author: Abhijit Kale
  * @date: 27th May 2020
  */

#include <iostream>
#include <string>

using namespace std;

/// @brief Base Entree class
class Entree {

protected:
    string _entree;

public:
    const string getEntree(){
        return _entree;
    }

};

/// @brief Base Side class
class Side {

protected:
    string _side;

public:
    string getSide() {
        return _side;
    }

};

/// @brief Drink class
class Drink {

protected:
    string _drink;

public:
    /// Constructor
    Drink() : _drink("soda") {
        cout << "\n Fill cup with soda" << endl;
    }

    string getDrink() {
        return _drink;
    }

};

class MealCombo {

private:
    Entree *entree;
    Side *side;
    Drink *drink;
    string _bag;

public:
    MealCombo(string type): _bag( ("\n " + type) + " meal combo:" ) {
    }

    void setEntree(Entree *e){
        entree = e;
    }

    void setSide(Side *s){
        side = s;
    }
    
    void setDrink(Drink *d){
        drink = d;
    }

    string openMealBag(){
        return _bag + entree->getEntree() + side->getSide() + drink->getDrink();
    }
};