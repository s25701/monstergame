
#ifndef UNTITLED4_MONSTER_H
#define UNTITLED4_MONSTER_H
#include <string>
#include "action.h"
#include <iostream>
using namespace std;
class monster
{
public:
    monster(std::string,int,int);//NAME,TYPE,LEVEL exp
    void setLevel(int);
    void setEXP(double);
    void setName(std::string);
    void setHealth_point(double);
    void setStrength();
    void setMaxHealth_point();

    void setType();

    double getHealth_point();
    int getStrength();
    std::string getName();
    std::string getType();
    int getLevel();
    void setEXP(int);
    int getEXPReq();
    double getMaxHealth_point();
    void setEXPReq();
    int getEXP();


private:
    std::string allyType;
    int allyStrength;
    double allyHealth_point;
    int EXP;
    std::string allyName;

    double allyMaxHealth_point;
    int EXPReq;
    int allyLevel;



};




#endif //UNTITLED4_MONSTER_H
