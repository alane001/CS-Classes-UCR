#include <iostream>
#include <string>
#include "Character.h"

using namespace std;


//Constructor of a character
Character::Character(CharType type, const string &name, double health, double attackStrength)
{
    //use this to make sure it is the data member, since they are the same name
    this -> type = type;
    this -> name = name;
    this -> health = health;
    this -> attackStrength = attackStrength;
    
}

CharType Character::getType() const
{
    return type;
}

const string & Character::getName() const
{
    return name;
}

/* Returns the whole number of the health value (static_cast to int). */
int Character::getHealth() const
{
    return static_cast<int>(health);
}

void Character::setHealth(double h)
{
    health = h;
}

/* Returns true if getHealth() returns an integer greater than 0, otherwise false */
bool Character::isAlive() const
{
    return getHealth() > 0;
}

//DON'T DECLARE THIS HERE
//virtual void Character::attack(Character & newChar) = 0;






