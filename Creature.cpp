//
// Created by Maks on 19.05.2022.
//
#include <iostream>
#include "Creature.h"

int Creature::attack(Creature &enemy) {
    switch (Creature::type) {
        case 1:
            switch (enemy.type) {
                case 1:
                    notEffectiveAttack(enemy.currentHitPoints);
                    break;
                case 2:
                    superEffectiveAttack(enemy.currentHitPoints);
                    break;
                case 3:
                    normalAttack(enemy.currentHitPoints);
                    break;
                case 4:
                    superEffectiveAttack(enemy.currentHitPoints);
                    break;
                case 5:
                    normalAttack(enemy.currentHitPoints);
                    break;
                case 6:
                    normalAttack(enemy.currentHitPoints);
                    break;
            }
            break;
        case 2:
            switch (enemy.type){
                case 1:
                    normalAttack(enemy.currentHitPoints);
                    break;
                case 2:
                    normalAttack(enemy.currentHitPoints);
                    break;
                case 3:
                    notEffectiveAttack(enemy.currentHitPoints);
                    break;
                case 4:
                    superEffectiveAttack(enemy.currentHitPoints);
                    break;
                case 5:
                    superEffectiveAttack(enemy.currentHitPoints);
                    break;
                case 6:
                    superEffectiveAttack(enemy.currentHitPoints);
                    break;
            }
            break;
        case 3:
            switch (enemy.type){
                case 1:
                    normalAttack(enemy.currentHitPoints);
                    break;
                case 2:
                    notEffectiveAttack(enemy.currentHitPoints);
                    break;
                case 3:
                    normalAttack(enemy.currentHitPoints);
                    break;
                case 4:
                    normalAttack(enemy.currentHitPoints);
                    break;
                case 5:
                    superEffectiveAttack(enemy.currentHitPoints);
                    break;
                case 6:
                    notEffectiveAttack(enemy.currentHitPoints);
                    break;
            }
            break;
        case 4:
            switch (enemy.type) {
                case 1:
                    notEffectiveAttack(enemy.currentHitPoints);
                    break;
                case 2:
                    notEffectiveAttack(enemy.currentHitPoints);
                    break;
                case 3:
                    normalAttack(enemy.currentHitPoints);
                    break;
                case 4:
                    normalAttack(enemy.currentHitPoints);
                    break;
                case 5:
                    superEffectiveAttack(enemy.currentHitPoints);
                    break;
                case 6:
                    superEffectiveAttack(enemy.currentHitPoints);
                    break;
            }
            break;
        case 5:
            switch (enemy.type) {
                case 1:
                    notEffectiveAttack(enemy.currentHitPoints);
                    break;
                case 2:
                    superEffectiveAttack(enemy.currentHitPoints);
                    break;
                case 3:
                    normalAttack(enemy.currentHitPoints);
                    break;
                case 4:
                    notEffectiveAttack(enemy.currentHitPoints);
                    break;
                case 5:
                    notEffectiveAttack(enemy.currentHitPoints);
                    break;
                case 6:
                    normalAttack(enemy.currentHitPoints);
                    break;
            }
            break;
        case 6:
            switch (enemy.type) {
                case 1:
                    superEffectiveAttack(enemy.currentHitPoints);
                    break;
                case 2:
                    normalAttack(enemy.currentHitPoints);
                    break;
                case 3:
                    superEffectiveAttack(enemy.currentHitPoints);
                    break;
                case 4:
                    notEffectiveAttack(enemy.currentHitPoints);
                    break;
                case 5:
                    normalAttack( enemy.currentHitPoints);
                    break;
                case 6:
                    notEffectiveAttack(enemy.currentHitPoints);
                    break;
            }
            break;
    }
    Creature::specialAttackStack++;
    if(Creature::specialAttackStack>=3)
    {
        specialAttackStack=3;
    }
    return 0;
}

int Creature::useUltimate(Creature& enemy) {
    if(Creature::specialAttackStack==3) {
        Creature::attack(enemy);
        Creature::attack(enemy);
        Creature::specialAttackStack = 0;
    }else{
        std::cout<<"Twoje stworzenie nie ma wystarczajaco ladunkow aby uzyc superumiejetnosci" << std::endl;
    }
    return 0;
}

int Creature::evolve(Creature& evolvoingCreature) {
    std::cout << "evolucja";
    return 0;
}

Creature::Creature( char *name, int strength, int agility, int maxHitPoints, int expPoints, int type) {
    Creature::name = name;
    Creature::strength = strength;
    Creature::agility = agility;
    Creature::maxHitPoints = maxHitPoints;
    Creature::currentHitPoints = maxHitPoints;
    Creature::expPoints = expPoints;
    Creature::type = type;
    Creature::level = 1;
    Creature::currentExp = 0;
    Creature::specialAttackStack=0;
}

int Creature::superEffectiveAttack(int &enemyHP) {
    enemyHP = enemyHP - (Creature::strength * 2);
    return 0;
}

int Creature::notEffectiveAttack(int &enemyHP) {
    enemyHP = enemyHP - (Creature::strength /2);
    return 0;
}

int Creature::normalAttack(int &enemyHP) {
    enemyHP = enemyHP - Creature::strength;
    return 0;
}

