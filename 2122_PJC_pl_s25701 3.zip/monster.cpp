
#include "monster.h"
#include <string>
#include "monster.h"
#include <iostream>
using namespace std;
monster::monster(std::string name,int level = 1,int EXP = 0)
{
    setName(name);
    setLevel(level);
    setEXP(EXP);
    setMaxHealth_point();
    setHealth_point(allyMaxHealth_point);
    setStrength();
    setEXPReq();
    setType();
}

void monster::setName(std::string name)
{
   allyName = name;
}
void monster::setType()
{
    srand(time(0));
    int mix = rand() % (6 - 1 + 1 ) + 1;
    switch (mix) {
        case 1:
            allyType = "water";
            break;
        case 2:
            allyType = "earth";
            break;
        case 3:
            allyType = "air";
            break;
        case 4:
            allyType = "fire";
            break;
        case 5:
            allyType = "ice";
            break;
        case 6:
            allyType = "steel";
            break;
    }
}
std::string monster::getType(){
    if(allyType=="water"){
        return "water";
    }
    else if(allyType=="earth"){
        return "earth";
    }
    else if(allyType=="air"){
        return "air";
    }
    else if(allyType=="fire"){
        return "fire";
    }
    else if(allyType=="ice"){
        return "ice";
    }
    else if(allyType=="steel"){
        return "steel";
    }
}



void monster::setLevel(int level)
{
    allyLevel = level;
}
void monster::setHealth_point(double health)
{
    allyHealth_point = health;
}
void monster::setMaxHealth_point()
{
    allyMaxHealth_point = (100 * getLevel());
}
void monster::setStrength()
{
    allyStrength = (30 * getLevel());
}

std::string monster::getName()
{
    return allyName;
}


int monster::getLevel()
{
    return allyLevel;
}
double monster::getHealth_point()
{
    return allyHealth_point;
}
double monster::getMaxHealth_point()
{
    return allyMaxHealth_point;
}
int monster::getStrength()
{
    return allyStrength;
}

int monster::getEXP()
{
    return EXP;
}
void monster::setEXP(int _EXP)
{
    EXP = _EXP;
}
int monster::getEXPReq()
{
    return EXPReq;
}
void monster::setEXPReq()
{
    EXPReq = 70+((getLevel()*getLevel())*35);
}