#ifndef WIZARD_H
#define WIZARD_H

#include <iostream>
#include <string>
#include "Character.h"

using namespace std;


class Wizard : public Character
{
    public:
        Wizard(const string& name, double health, double strength, const int& rank);
        void attack(Character &);
        
    private:
        int rank;
};

#endif