#include "action.h"
#include "monster.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
monster battle(monster ally);
monster calcEXP(monster ally,action villain);
monster levelUp(monster ally);
void death();

int main()
{
    string name;
    int number;
    cout << "Welcome, please enter your name\n";
    cin >> name;

    monster ally(name,1,0);
    cout <<"\nWelcome "<<ally.getName() <<"\n let the show begin:)\n";
    while (1)
    {

        cout <<"write 1 to walk forward or 2 to walk left or 3 to walk right 4 to see the qualifications 5 for help \n";
        cin >> number;
        if (number >=1 && number <=3) {

            srand(time(NULL));
            if (rand() % 3 == number - 1) {
                ally = battle(ally);
            }

        }
        else if (number==4){
            cout<< "TYPE:"<< ally.getType()<<endl<<"NAME:"<<ally.getName()<<endl<<"LEVEL:"<<ally.getLevel()<<endl<<"EXP:"<<ally.getEXP()<<endl;
        }
        else if (number==5){
            cout<< "This game is about finding villains and fighting with them. In the middle of a forest trying to save the world in a spooky weather. The instructions of the game are given in menu"<<endl;
        }
        else{
            cout << "\n#@#Error#@# NO NO NO the number should be between 1 and 5\n\n";
            cin.clear();
            cin.ignore();
        }
    }
    return 0;

}




monster battle(monster ally) {

    string operation;
    string villains[2][8] = {{"arzuk", "gakkos", "vax",   "saadman", "chucky", "lawrick", "owe",   "cumi"},
                             {"arzus", "lori",   "beyza", "muti",    "sosa",   "jax",     "ledya", "caroline"}};

    srand(time(NULL));
    int ranV = (rand() % 8); //random villain
    int ranD = (rand() % 2) + 1; //random diff
    action villain(villains[ally.getLevel() - 1][ranV], ally.getLevel(), ranD);
    cout << "oh noo there is a villain " << villain.getName() << "show them who is the real king" << "\n";

    do {
        cout << "\n\n\n ######################################\nHP:" << ally.getHealth_point() << "                  "
             << villain.getName() << "HP:" << villain.getHealth_point() << " difficulty:" << villain.getDifficulty()
             << "\n";
        cout << " A for attack or R for run" << "\n";
        cin >> operation;
        srand(time(NULL));
        if (operation == "R" || operation == "r") {
            if ((rand() % 2) == 1) {
                cout << "run sucessfull" << "\n";
                villain.setHealth_point(0);
            } else {
                cout
                        << "you can't run boi, the monster get a free attack and you lose 5 health points already fight for your life!\n";
                ally.setHealth_point(ally.getHealth_point() - 5);
                operation = "A";
            }
        }


        if (operation == "A" || operation == "a") {
            int attack = rand() % (ally.getStrength());
            srand(time(NULL));
            string villainType= villain.getType();
            string allyType= ally.getType();
            int villainAttack = rand() % (villain.getStrength());
            villain.setHealth_point(villain.getHealth_point() - attack);
                ally.setHealth_point(ally.getHealth_point() - villainAttack);
            if (allyType == "water") {
                if ( villainType == "water") {

                    cout << "you attacked that weirdo with water " << attack * 0.5 << " damage\n";
                } else if (villainType == "earth") {

                    cout << "you attacked that weirdo with water " << attack * 1.5 << " damage\n";
                } else if (villainType == "air") {

                    cout << "you attacked that weirdo with water " << attack << " damage\n";
                } else if (villainType == "fire") {

                    cout << "you attacked that weirdo with water " << attack * 1.5 << " damage\n";
                } else if (villainType == "ice") {

                    cout << "you attacked that weirdo with water " << attack << " damage\n";
                } else if (villainType == "steel") {

                    cout << "you attacked that weirdo with water " << attack << " damage\n";
                }
            } else if (allyType == "earth") {
                if (villainType == "water") {

                    cout << "you attacked that weirdo with soil " << attack << " damage\n";
                } else if (villainType == "earth") {

                    cout << "you attacked that weirdo with soil " << attack << " damage\n";
                } else if (villainType == "air") {

                    cout << "you attacked that weirdo with soil " << attack * 0.5 << " damage\n";
                } else if (villainType == "fire") {

                    cout << "you attacked that weirdo with soil " << attack * 1.5 << " damage\n";
                } else if (villainType == "ice") {

                    cout << "you attacked that weirdo with soil " << attack * 1.5 << " damage\n";
                } else if (villainType == "steel") {
                    cout << "you attacked that weirdo with soil " << attack * 1.5 << " damage\n";
                }
            } else if (allyType == "air") {
                if (villainType == "water") {

                    cout << "you attacked that weirdo with air " << attack << " damage\n";
                } else if (villainType == "earth") {

                    cout << "you attacked that weirdo with air " << attack * 0.5 << " damage\n";
                } else if (villainType == "air") {

                    cout << "you attacked that weirdo with air " << attack << " damage\n";
                } else if (villainType == "fire") {

                    cout << "you attacked that weirdo with air " << attack << " damage\n";
                } else if (villainType == "ice") {

                    cout << "you attacked that weirdo with air " << attack * 1.5 << " damage\n";
                } else if (villainType == "steel") {
                    cout << "you attacked that weirdo with air " << attack * 0.5 << " damage\n";
                }
            } else if (allyType == "fire") {
                if (villainType == "water") {

                    cout << "you attacked that weirdo with fire " << attack * 0.5 << " damage\n";
                } else if (villainType == "earth") {

                    cout << "you attacked that weirdo with fire " << attack * 0.5 << " damage\n";
                } else if (villainType == "air") {

                    cout << "you attacked that weirdo with fire " << attack << " damage\n";
                } else if (villainType == "fire") {

                    cout << "you attacked that weirdo with fire " << attack << " damage\n";
                } else if (villainType == "ice") {

                    cout << "you attacked that weirdo with fire" << attack * 1.5 << " damage\n";
                } else if (villainType == "steel") {
                    cout << "you attacked that weirdo with fire " << attack * 1.5 << " damage\n";
                }
            } else if (allyType == "ice") {
                if (villainType == "water") {

                    cout << "you attacked that weirdo with ice " << attack * 0.5 << " damage\n";
                } else if (villainType == "earth") {

                    cout << "you attacked that weirdo with ice " << attack * 1.5 << " damage\n";
                } else if (villainType == "air") {

                    cout << "you attacked that weirdo with ice " << attack << " damage\n";
                } else if (villainType == "fire") {

                    cout << "you attacked that weirdo with ice " << attack * 0.5 << " damage\n";
                } else if (villainType == "ice") {

                    cout << "you attacked that weirdo with ice" << attack * 0.5 << " damage\n";
                } else if (villainType == "steel") {
                    cout << "you attacked that weirdo with ice " << attack * 1 << " damage\n";
                }
            } else if (allyType == "steel") {
                if (villainType == "water") {

                    cout << "you attacked that weirdo with ice " << attack * 1.5 << " damage\n";
                } else if (villainType == "earth") {

                    cout << "you attacked that weirdo with steel" << attack << " damage\n";
                } else if (villainType == "air") {

                    cout << "you attacked that weirdo with steel " << attack * 1.5 << " damage\n";
                } else if (villainType == "fire") {

                    cout << "you attacked that weirdo with steel " << attack * 0.5 << " damage\n";
                } else if (villainType == "ice") {

                    cout << "you attacked that weirdo with steel" << attack << " damage\n";
                } else if (villainType == "steel") {
                    cout << "you attacked that weirdo with steel " << attack * 0.5 << " damage\n";
                }
            }


            if (villainType == "water") {
                if (allyType == "water") {

                    cout << "the weirdo attacked you back with water" << villainAttack * 0.5 << " damage\n";
                } else if (allyType == "earth") {

                    cout << "the weirdo attacked you back with water " << villainAttack * 1.5 << " damage\n";
                } else if (allyType == "air") {

                    cout << "the weirdo attacked you back with water" << villainAttack << " damage\n";
                } else if (allyType == "fire") {

                    cout << "the weirdo attacked you back with water" << villainAttack * 1.5 << " damage\n";
                } else if (allyType == "ice") {

                    cout << "the weirdo attacked you back with water" << villainAttack << " damage\n";
                } else if (allyType == "steel") {

                    cout << "the weirdo attacked you back with water " << villainAttack << " damage\n";
                }
            } else if (villainType == "earth") {
                if (allyType == "water") {

                    cout << "the weirdo attacked you back with soil " << villainAttack << " damage\n";
                } else if (villainType == "earth") {

                    cout << "the weirdo attacked you back with soil" << villainAttack << " damage\n";
                } else if (villainType == "air") {

                    cout << "the weirdo attacked you back with soil" << villainAttack * 0.5 << " damage\n";
                } else if (villainType == "fire") {

                    cout << "the weirdo attacked you back with soil " << villainAttack * 1.5 << " damage\n";
                } else if (villainType == "ice") {

                    cout << "the weirdo attacked you back with soil " << villainAttack * 1.5 << " damage\n";
                } else if (villainType == "steel") {
                    cout << "the weirdo attacked you back with soil " << villainAttack * 1.5 << " damage\n";
                }
            } else if (villainType == "air") {
                if (allyType == "water") {

                    cout << "the weirdo attacked you back with air " << villainAttack << " damage\n";
                } else if (allyType == "earth") {

                    cout << "the weirdo attacked you back with air" << villainAttack * 0.5 << " damage\n";
                } else if (allyType == "air") {

                    cout << "the weirdo attacked you back with air " << villainAttack << " damage\n";
                } else if (allyType == "fire") {

                    cout << "the weirdo attacked you back with air " << villainAttack << " damage\n";
                } else if (allyType == "ice") {

                    cout << "the weirdo attacked you back with air " << villainAttack * 1.5 << " damage\n";
                } else if (allyType == "steel") {
                    cout << "the weirdo attacked you back with air " << villainAttack * 0.5 << " damage\n";
                }
            } else if (villainType == "fire") {
                if (allyType == "water") {

                    cout << "the weirdo attacked you back with fire " << villainAttack * 0.5 << " damage\n";
                } else if (allyType == "earth") {

                    cout << "the weirdo attacked you back with fire " << villainAttack * 0.5 << " damage\n";
                } else if (allyType == "air") {

                    cout << "the weirdo attacked you back with fire" << villainAttack << " damage\n";
                } else if (allyType == "fire") {

                    cout << "the weirdo attacked you back with fire" << villainAttack << " damage\n";
                } else if (allyType == "ice") {

                    cout << "the weirdo attacked you back with fire " << villainAttack * 1.5 << " damage\n";
                } else if (allyType == "steel") {
                    cout << "the weirdo attacked you back with fire " << villainAttack * 1.5 << " damage\n";
                }
            } else if (villainType == "ice") {
                if (allyType == "water") {

                    cout << "the weirdo attacked you back with ice " << villainAttack * 0.5 << " damage\n";
                } else if (allyType == "earth") {

                    cout << "the weirdo attacked you back with ice " << villainAttack * 1.5 << " damage\n";
                } else if (allyType == "air") {

                    cout << "the weirdo attacked you back with ice " << villainAttack << " damage\n";
                } else if (allyType == "fire") {

                    cout << "the weirdo attacked you back with ice " << villainAttack * 0.5 << " damage\n";
                } else if (allyType == "ice") {

                    cout << "the weirdo attacked you back with ice" << villainAttack * 0.5 << " damage\n";
                } else if (allyType == "steel") {
                    cout << "the weirdo attacked you back with ice " << villainAttack * 1 << " damage\n";
                }
            } else if (villainType == "steel") {
                if (allyType == "water") {

                    cout << "the weirdo attacked you back with steel " << villainAttack * 1.5 << " damage\n";
                } else if (allyType == "earth") {

                    cout << "the weirdo attacked you back with steel " << villainAttack << " damage\n";
                } else if (allyType == "air") {

                    cout << "the weirdo attacked you back with steel " << villainAttack * 1.5 << " damage\n";
                } else if (allyType == "fire") {

                    cout << "the weirdo attacked you back with steel " << villainAttack * 0.5 << " damage\n";
                } else if (allyType == "ice") {

                    cout << "the weirdo attacked you back with steel " << villainAttack << " damage\n";
                } else if (allyType == "steel") {
                    cout << "the weirdo attacked you back with steel " << villainAttack * 0.5 << " damage\n";
                }
            }


        }}
        while (villain.getHealth_point() > 0 && ally.getHealth_point() > 0);
        cout << "\n###########\nHP:" << villain.getName() << "Health_Point:" << villain.getHealth_point() << "    "
             << villain.getName() << "Health_Point:" << villain.getHealth_point() << " difficulty:"
             << villain.getDifficulty() << "\n";
        if (ally.getHealth_point() <= 0) {
            death();
            exit(0);
        }
        ally = calcEXP(ally, villain);
        return ally;
    }


    void death() {
        cout << "You died get well soon <3\n";
    }

    monster calcEXP(monster ally, action villain) {
        cout << "#########\ncalculating EXP\n#########\n";

        ally.setEXP(ally.getEXP() + villain.getEXP());
        cout << "EXP: " << ally.getEXP() << "/" << ally.getEXPReq() << "\n";
        if (ally.getEXP() >= ally.getEXPReq()) {
            levelUp(ally);
        }
        return ally;
    }

    monster levelUp(monster ally) {
        ally.setLevel(ally.getLevel() + 1);
        ally.setEXPReq();
        ally.setMaxHealth_point();
        ally.setHealth_point(ally.getMaxHealth_point());
        cout << "Congrats ! you leveled up: " << ally.getLevel() << "!\n";
        return ally;

    }
