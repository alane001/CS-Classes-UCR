#ifndef ELF_H
#define ELF_H

#include <iostream>
#include <string>
#include "Character.h"

using namespace std;


class Elf : public Character
{
    public:
        Elf(const string& name, double health, double strength, const string& family);
        void attack(Character &);
        
    private:
        string family;
};

#endif