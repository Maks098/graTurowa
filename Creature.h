//
// Created by Maks on 19.05.2022.
//

#ifndef UNTITLED1_CREATURE_H
#define UNTITLED1_CREATURE_H


class Creature {
public:
    Creature(char *name, int strength, int agility, int hitPoints, int ultimate, int expPoints, int type);
    char* name;
    int strength;
    int agility;
    int hitPoints;
    int ultimate;
    int expPoints;
    /*1=woda,2=ziemia,3=powietrze,4=ogień,5=lód,6=stal*/
    int type;
    int attack(Creature& enemy);
    int useUltimate();
    int evolve();
    int superEffectiveAttack(int& enemyHP);
    int notEffectiveAttack(int& enemyHP);
    int normalAttack(int& enemyHP);
};





#endif //UNTITLED1_CREATURE_H
