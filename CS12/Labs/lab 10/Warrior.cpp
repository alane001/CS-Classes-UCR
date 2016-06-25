#include <iostream>
#include <string>
#include "Character.h"
#include "Warrior.h"

using namespace std;

//This can be changed to just use the character constructor : Character(something), this way you don't have
//to do the section where this->type = warrior, etc....
//must include the : Character() portion or else it causes major problems
Warrior::Warrior(const string& name, double health, double strength, const string& allegiance) : Character(type, name, health, attackStrength)
{
    this -> type = WARRIOR;
    this -> name = name;
    this -> health = health;
    this -> attackStrength = strength;
    this -> allegiance = allegiance;

    return;
}


void Warrior::attack(Character & opponent)
{
    //must store the damage and new health after an attack
    double damage = 0;
    double newHealth = 0;

    //DONT PUT OUTSIDE OF CASE WHERE OPPONENT IS A WARRIOR
    //this dynamically casts the opponent as a warrior object to check alligence if the type is a warrior
    //Warrior &opp = dynamic_cast<Warrior &>(opponent);

    if(opponent.getType() == ELF)
    {
        if(opponent.isAlive())
        {
            //The damage done by the warrior is the percentage of the warrior's health remaining
            //(health / MAX_HEALTH) multiplied by the warrior's attack strength.
            damage = (health/MAX_HEALTH) * attackStrength;

            cout << "Warrior " << getName() << " attacks " << opponent.getName() << " --- SLASH!!" << endl;
            cout << opponent.getName() << " takes " << damage << " damage." << endl;

            //set opponents new health
            newHealth = opponent.getHealth() - damage;
            opponent.setHealth(newHealth);
        }
        else
        {
            cout << "Opponent is dead!!" << endl;
        }

    }
    else if(opponent.getType() == WIZARD)
    {
        if(opponent.isAlive())
        {
            //The damage done by the warrior is the percentage of the warrior's health
            //remaining (health / MAX_HEALTH) multiplied by the warrior's attack strength.
            damage = (health/MAX_HEALTH) * attackStrength;

            cout << "Warrior " << getName() << " attacks " << opponent.getName() << " --- SLASH!!" << endl;
            cout << opponent.getName() << " takes " << damage << " damage." << endl;

            //set opponents new health
            newHealth = opponent.getHealth() - damage;
            opponent.setHealth(newHealth);
        }
        else
        {
            cout << "Opponent is dead!!" << endl;
        }

    }
    else if(opponent.getType() == WARRIOR)
    {
        //this dynamically casts the opponent as a warrior object to check alligence if the type is a warrior
        //only put in here, not outside of this statement
        Warrior &opp = dynamic_cast<Warrior &>(opponent);
        if(opponent.isAlive())
        {
            //NOTICE THE OPP instead of opponent! VERY IMPORTANT or can't check allegiance!
            //warriors don't attack other warriors of the same family
            if(opp.allegiance == allegiance)
            {
                cout << "Warrior " << getName() << " does not attack Warrior " << opponent.getName() << ".";
                cout << endl << "They share an allegiance with " << allegiance << "." << endl;
            }
            else
            {
                //The damage done by the warrior is the percentage of the warrior's health remaining
                //(health / MAX_HEALTH) multiplied by the warrior's attack strength.
                damage = (health/MAX_HEALTH) * attackStrength;

                cout << "Warrior " << getName() << " attacks " << opponent.getName() << " --- SLASH!!" << endl;
                cout << opponent.getName() << " takes " << damage << " damage." << endl;

                //set opponents new health
                newHealth = opponent.getHealth() - damage;
                opponent.setHealth(newHealth);

            }
        }
        else
        {
            cout << "Opponent is dead!" << endl;
        }
    }

    return;
}







