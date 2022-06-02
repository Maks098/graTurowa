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
    void diffScaling(int scaling);
    void resetHp();
    void changeCreatureOption(Creature& chosenToFight,int& creatureChooseToFight);


};


#endif //UNTITLED1_TRAINER_H
