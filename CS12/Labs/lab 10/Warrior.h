#ifndef WARRIOR_H
#define WARRIOR_H

#include <iostream>
#include <string>
#include "Character.h"

using namespace std;


class Warrior : public Character
{
    public:
        Warrior(const string& name, double health, double strength, const string& allegiance);
        void attack(Character &);
        
    private:
        string allegiance;
};

#endif