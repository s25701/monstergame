
#ifndef UNTITLED4_ACTION_H
#define UNTITLED4_ACTION_H
#include <string>
using namespace std;
class action {


    public:
        action(std::string,int,int); // name,lvl,exp

        void setHealth_point(double);
        void setName(std::string);
    void setType();
        void setDifficulty(int);
        void setStrength();
        void setLevel(int);
        void setMaxHealth_point();
    std::string getType();
        std::string getName();

        int getStrength();
        int getLevel();
        double getMaxHealth_point();
        double getHealth_point();
        int getEXP();
        void setEXP();
        int getDifficulty();

    private:
    std::string  villainType;
        double villainHealth_point;
        std::string villainName;

        int villainDifficulty;
        int EXP;
        int villainLevel;
        double villainMaxHealth_point;
        int villainStrength;

    };




#endif //UNTITLED4_ACTION_H
