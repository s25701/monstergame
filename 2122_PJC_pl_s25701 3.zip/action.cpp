
#include "action.h"
#include <string>
#include <iostream>
using namespace std;
action::action(std::string name, int lvl,int difficulty)
{
    setType();
    setName(name);

    setLevel(lvl);
    setDifficulty(difficulty);
    setStrength();
    setMaxHealth_point();
    setHealth_point(villainMaxHealth_point);
    setEXP();
}

void action::setName(std::string name)
{
   villainName = name ;
}
void action::setType()
{
    srand(time(0));
    int mix = rand() % (6 - 1 + 1 ) + 1;
    switch (mix) {
        case 1:
            villainType = "water";
            break;
        case 2:
            villainType = "earth";
            break;
        case 3:
            villainType = "air";
            break;
        case 4:
            villainType = "fire";
            break;
        case 5:
            villainType = "ice";
            break;
        case 6:
            villainType= "steel";
            break;
    }
}
std::string action::getType(){
    if(villainType=="water"){
        return "water";
    }
    else if(villainType=="earth"){
       return "earth";
    }
    else if(villainType=="air"){
       return "air";
    }
    else if(villainType=="fire"){
        return "fire";
    }
    else if(villainType=="ice"){
        return "ice";
    }
    else if(villainType=="steel"){
       return "steel";
    }
}



void action::setLevel(int level)
{
    villainLevel = level;
}


void action::setDifficulty(int difficulty)
{
    villainDifficulty = difficulty;
}

void action::setStrength()
{
   villainStrength = (3 *( getLevel())+((getDifficulty()*getLevel())/2));
}

void action::setHealth_point(double health)
{
   villainHealth_point = health;
}
void action::setMaxHealth_point()
{
    villainMaxHealth_point = (15 *(getDifficulty() + getLevel()));
}
std::string action::getName()
{
    return villainName;
}

int action::getLevel()
{
    return villainLevel;
}
int action::getDifficulty()
{
    return villainDifficulty;
}
int action::getStrength()
{
    return villainStrength;
}
double action::getHealth_point()
{
    return villainHealth_point;
}
double action::getMaxHealth_point()
{
    return villainMaxHealth_point;
}

int action::getEXP()
{
    return EXP;
}

void action::setEXP()
{
    EXP = (getLevel() * 35);
}