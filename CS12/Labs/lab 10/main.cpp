//----------------------------------------------------------------------------------------------
//DESCRIPTION

//BASE CLASS is the character.cpp and character.h files



//Derived Classes


//Warrior

//Stores the warrior's allegiance as a string.

//The warrior does not attack warriors that have the same allegiance.

//The damage done by the warrior is the percentage of the warrior's health remaining
//(health / MAX_HEALTH) multiplied by the warrior's attack strength.


//Elf

//Stores the elf's family name as a string.

//The elf does not attack elf's from its own family.

//The damage done by the elf is the percentage of the elf's health remaining
//(health / MAX_HEALTH) multiplied by the elf's attack strength.


//Wizard

//Stores the wizard's rank as an int.

//When a wizard attacks another wizard, the damage done is the wizard's attack strength multiplied by the
//ratio of the attacking wizard's rank over the defending wizard's rank.

//The damage done to non-wizards is just the attack strength. The wizard's health is not taken into consideration.



//Dynamic casting type of Character in attack function

//In order to access the Warrior data field allegiance using the Character reference passed in to the
//attack function, you will need to dynamic cast the Character reference to a Warrior reference.

//Here's an example of dynamic casting a Character reference named opponent to a Warrior reference
//named opp: Warrior &opp = dynamic_cast<Warrior &>(opponent);

//You will need to do the same for the Wizard and Elf attack functions, only dynamic casting to Wizard
//or Elf reference instead.


//CharType

//Notice the enum declaration above the Character class declaration. This creates a special type called
//CharType that has the values, WARRIOR, ELF, and WIZARD. Those are the values you store in a variable of
//type CharType. For example, you can initialize a variable of type CharType and set it to the value of WARRIOR
// like this: CharType type = WARRIOR;
//You can compare a variable named t of type CharType to one of the CharType values like this:

//if (t == WARRIOR) {
   // do something based on t being a warrior
//}


//Example main function

//This shows you what your attack function should do in all situations. Look below this to find the main function you will need to pass the zyBook tests.

//#include <iostream>

//using namespace std;

//#include "Warrior.h"
//#include "Elf.h"
//#include "Wizard.h"

//int main() {

//   Warrior w1("Arthur", 100, 5, "King George");
//    Warrior w2("Jane", 100, 6, "King George");
//    Warrior w3("Bob", 100, 4, "Queen Emily");
//    Elf e1("Raegron", 100, 4, "Sylvarian");
//    Elf e2("Cereasstar", 100, 3, "Sylvarian");
//    Elf e3("Melimion", 100, 4, "Valinorian");
//    Wizard wz1("Merlin", 100, 5, 10);
//    Wizard wz2("Adali", 100, 5, 8);
//    Wizard wz3("Vrydore", 100, 4, 6);
//   e1.attack(w1);
//    cout << endl;
//    e1.attack(e2);
//    cout << endl;
//    w2.attack(w1);
//    cout << endl;
//    w3.attack(w1);
//    cout << endl;
//    wz1.attack(wz2);
//    cout << endl;
//    wz1.attack(wz3);
//    cout << endl;

//    return 0;
//}

//The output of this main function will look like this:

//Elf Raegron shoots an arrow at Arthur --- TWANG!!
//Arthur takes 4 damage.

//Elf Raegron does not attack Elf Cereasstar.
//They are both members of the Sylvarian family.

//Warrior Jane does not attack Warrior Arthur.
//They share an allegiance with King George.

//Warrior Bob attacks Arthur --- SLASH!!
//Arthur takes 4 damage.

//Wizard Merlin attacks Adali --- POOF!!
//Adali takes 6.25 damage.

//Wizard Merlin attacks Vrydore --- POOF!!
//Vrydore takes 8.33333 damage.

//----------------------------------------------------------------------------------------------




#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

#include "Character.h"
#include "Warrior.h"
#include "Elf.h"
#include "Wizard.h"

int main() {
    int seed;
    cout << "Enter seed value: ";
    cin >> seed;
    cout << endl;

    srand(seed);

    vector<Character *> adventurers;
    adventurers.push_back(new Warrior("Arthur", MAX_HEALTH, 5, "King George"));
    adventurers.push_back(new Warrior("Jane", MAX_HEALTH, 6, "King George"));
    adventurers.push_back(new Warrior("Bob", MAX_HEALTH, 4, "Queen Emily"));
    adventurers.push_back(new Elf("Raegron", MAX_HEALTH, 4, "Sylvarian"));
    adventurers.push_back(new Elf("Cereasstar", MAX_HEALTH, 3, "Sylvarian"));
    adventurers.push_back(new Elf("Melimion", MAX_HEALTH, 4, "Valinorian"));
    adventurers.push_back(new Wizard("Merlin", MAX_HEALTH, 5, 10));
    adventurers.push_back(new Wizard("Adali", MAX_HEALTH, 5, 8));
    adventurers.push_back(new Wizard("Vrydore", MAX_HEALTH, 4, 6));

    unsigned numAttacks = 10 + rand() % 11;
    unsigned attacker, defender;
    for (unsigned i = 0; i < numAttacks; ++i) {
        attacker = rand() % adventurers.size();
        do {
            defender = rand() % adventurers.size();
        } while (defender == attacker);

        adventurers.at(attacker)->attack(*adventurers.at(defender));
        cout << endl;
    }
    cout << "-----Health Remaining-----" << endl;
    for (unsigned i = 0; i < adventurers.size(); ++i) {
        cout << adventurers.at(i)->getName() << ": "
            << adventurers.at(i)->getHealth() << endl;
    }
    return 0;
}
