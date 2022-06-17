//
// Created by Maks on 19.05.2022.
//

#ifndef UNTITLED1_CREATURE_H
#define UNTITLED1_CREATURE_H


#include <vector>

class Creature {
public:
    Creature(std::string  name, int strength, int agility, int maxHitPoints, int expPoints, int type, int specialInteraction);
    std::string name;
    int strength;
    int agility;
    int maxHitPoints;
    int currentHitPoints;
    int expPoints;
    /*1=woda,2=ziemia,3=powietrze,4=ogień,5=lód,6=stal*/
    int type;
    int level;
    int currentExp;
    int specialAttackStack;
    int specialInteraction;
    int attack(Creature& enemy);
    int useUltimate(Creature& enemy);
    int evolve();
    int superEffectiveAttack(int& enemyHP);
    int notEffectiveAttack(int& enemyHP);
    int normalAttack(int& enemyHP);

    Creature(const std::string &name, int strength, int agility, int maxHitPoints, int expPoints,
             int type, int level, int currentExp, int specialAttackStack, int specialInteraction);
};





#endif //UNTITLED1_CREATURE_H