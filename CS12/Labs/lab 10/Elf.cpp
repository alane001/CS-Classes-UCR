#include <iostream>
#include <string>
#include "Character.h"
#include "Elf.h"

using namespace std;

Elf::Elf(const string& name, double health, double strength, const string& family) : Character(type, name, health, attackStrength)
{
    this -> type = ELF;
    this -> name = name;
    this -> health = health;
    this -> attackStrength = strength;
    this -> family = family;
    
    return;
}


void Elf::attack(Character & opponent)
{
    double damage = 0;
    double newHealth = 0;
    
    //DONT PUT THIS OUTSIDE OF THE CASE WHERE THE OPPONENT IS AN ELF, CAUSES BAD_CAST ERROR
    //this dynamically casts the opponent as an elf so that family can be accessed
    //Elf &opp = dynamic_cast<Elf &>(opponent);
    
    if(opponent.getType() == ELF)
    {
        if(opponent.isAlive())
        {
            //this allows access to family name, must be put here
            Elf &opp = dynamic_cast<Elf &>(opponent);
            
            //NOTICE THE OPP instead of opponent! VERY IMPORTANT or can't check allegiance!
            //Elf does not attack another elf with the same family
            if(opp.family == family)
            {
                cout << "Elf " << getName() << " does not attack Elf " << opponent.getName() << ".";
                cout << endl << "They are both members of the " << family << " family." << endl;
            }
            else
            {
                //The damage done by the elf is the percentage of the elf's health remaining
                //(health / MAX_HEALTH) multiplied by the elf's attack strength.
                damage = (health/MAX_HEALTH) * attackStrength;
                
                cout << "Elf " << getName() << " shoots an arrow at " << opponent.getName() << " --- TWANG!!" << endl;
                cout << opponent.getName() << " takes " << damage << " damage." << endl;
            
                //set opponents new health
                newHealth = opponent.getHealth() - damage;
                opponent.setHealth(newHealth);
            }
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
            //The damage done by the elf is the percentage of the elf's health remaining
            //(health / MAX_HEALTH) multiplied by the elf's attack strength.
            damage = (health/MAX_HEALTH) * attackStrength;
                
            cout << "Elf " << getName() << " shoots an arrow at " << opponent.getName() << " --- TWANG!!" << endl;
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
        if(opponent.isAlive())
        {
            //The damage done by the elf is the percentage of the elf's health remaining 
            //(health / MAX_HEALTH) multiplied by the elf's attack strength.
            damage = (health/MAX_HEALTH) * attackStrength;
                
            cout << "Elf " << getName() << " shoots an arrow at " << opponent.getName() << " --- TWANG!!" << endl;
            cout << opponent.getName() << " takes " << damage << " damage." << endl;
            
            //set opponents new health
            newHealth = opponent.getHealth() - damage;
            opponent.setHealth(newHealth);
        }
        else
        {
            cout << "Opponent is dead!" << endl;
        }
    }
    
    return;
}