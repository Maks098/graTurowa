//
// Created by Maks on 01.06.2022.
//

#ifndef UNTITLED1_TRAINER_H
#define UNTITLED1_TRAINER_H
#include <vector>
#include "Creature.h"

class Trainer {
public:
    Trainer(int nr, const std::vector<Creature> &creatures);
    int nr;
    std::vector<Creature> creatures;
    void fight(Trainer enemy);
    void showCreatureList();
    void showCreatureListWithHitPoints();
    void diffScaling(double scaling);
    void resetHp();
    void changeCreatureOption(Creature& chosenToFight,int& creatureChooseToFight);
    void choosingTeam(std::vector<Creature> chooseList,std::vector<Creature> creaturesToChooseFrom);
    void saveToFile(Trainer player,Trainer enemy1,Trainer enemy2,Trainer enemy3,Trainer enemy4);
    void loadSave(Trainer player,Trainer enemy1,Trainer enemy2,Trainer enemy3,Trainer enemy4);

};


#endif //UNTITLED1_TRAINER_H
