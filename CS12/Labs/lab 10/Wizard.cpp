#include <iostream>
#include <string>
#include "Character.h"
#include "Wizard.h"

using namespace std;

Wizard::Wizard(const string& name, double health, double strength, const int& rank) : Character(type, name, health, attackStrength)
{
    this -> type = WIZARD;
    this -> name = name;
    this -> health = health;
    this -> attackStrength = strength;
    this -> rank = rank;
    
    return;
}


void Wizard::attack(Character & opponent)
{
    double damage = 0;
    double newHealth = 0;
    
    //this dynamically casts the opponent as an elf so that family can be accessed
    //Elf &opp = dynamic_cast<Elf &>(opponent);
    
    if(opponent.getType() == ELF)
    {
        if(opponent.isAlive())
        {
            //The damage done to non-wizards is just the attack strength. The wizard's health is not taken into consideration.
            damage = attackStrength;
                
            cout << "Wizard " << getName() << " attacks " << opponent.getName() << " --- POOF!!" << endl;
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
        //ONLY put this here when the opponent is a wizard
        Wizard &opp = dynamic_cast<Wizard &>(opponent);
        if(opponent.isAlive())
        {
            //the damage of the wizard depends on:
            //When a wizard attacks another wizard, the damage done is the wizard's attack strength
            //multiplied by the ratio of the attacking wizard's rank over the defending wizard's rank.
            //NOTICE opp not opponent
            damage = (static_cast<double>(rank)/opp.rank) * attackStrength;
                
            cout << "Wizard " << getName() << " attacks " << opponent.getName() << " --- POOF!!" << endl;
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
            //The damage done to non-wizards is just the attack strength. The wizard's health is not taken into consideration.
            damage = attackStrength;
                
            cout << "Wizard " << getName() << " attacks " << opponent.getName() << " --- POOF!!" << endl;
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