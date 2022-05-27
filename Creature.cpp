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
                    notEffectiveAttack(enemy.hitPoints);
                    break;
                case 2:
                    superEffectiveAttack(enemy.hitPoints);
                    break;
                case 3:
                    normalAttack(enemy.hitPoints);
                    break;
                case 4:
                    superEffectiveAttack(enemy.hitPoints);
                    break;
                case 5:
                    normalAttack(enemy.hitPoints);
                    break;
                case 6:
                    normalAttack(enemy.hitPoints);
                    break;
            }
            break;
        case 2:
            switch (enemy.type){
                case 1:
                    normalAttack(enemy.hitPoints);
                    break;
                case 2:
                    normalAttack(enemy.hitPoints);
                    break;
                case 3:
                    notEffectiveAttack(enemy.hitPoints);
                    break;
                case 4:
                    superEffectiveAttack(enemy.hitPoints);
                    break;
                case 5:
                    superEffectiveAttack(enemy.hitPoints);
                    break;
                case 6:
                    superEffectiveAttack(enemy.hitPoints);
                    break;
            }
                break;
        case 3:
            switch (enemy.type){
                case 1:
                    normalAttack(enemy.hitPoints);
                    break;
                case 2:
                    notEffectiveAttack(enemy.hitPoints);
                    break;
                case 3:
                    normalAttack(enemy.hitPoints);
                    break;
                case 4:
                    normalAttack(enemy.hitPoints);
                    break;
                case 5:
                    superEffectiveAttack(enemy.hitPoints);
                    break;
                case 6:
                    notEffectiveAttack(enemy.hitPoints);
                    break;
            }
            break;
        case 4:
            switch (enemy.type) {
                case 1:
                    notEffectiveAttack(enemy.hitPoints);
                    break;
                case 2:
                    notEffectiveAttack(enemy.hitPoints);
                    break;
                case 3:
                    normalAttack(enemy.hitPoints);
                    break;
                case 4:
                    normalAttack(enemy.hitPoints);
                    break;
                case 5:
                    superEffectiveAttack(enemy.hitPoints);
                    break;
                case 6:
                    superEffectiveAttack(enemy.hitPoints);
                    break;
            }
            break;
        case 5:
            switch (enemy.type) {
                case 1:
                    notEffectiveAttack(enemy.hitPoints);
                    break;
                case 2:
                    superEffectiveAttack(enemy.hitPoints);
                    break;
                case 3:
                    normalAttack(enemy.hitPoints);
                    break;
                case 4:
                    notEffectiveAttack(enemy.hitPoints);
                    break;
                case 5:
                    notEffectiveAttack(enemy.hitPoints);
                    break;
                case 6:
                    normalAttack(enemy.hitPoints);
                    break;
            }
            break;
        case 6:
            switch (enemy.type) {
                case 1:
                    superEffectiveAttack(enemy.hitPoints);
                    break;
                case 2:
                    normalAttack(enemy.hitPoints);
                    break;
                case 3:
                    superEffectiveAttack(enemy.hitPoints);
                    break;
                case 4:
                    notEffectiveAttack(enemy.hitPoints);
                    break;
                case 5:
                    normalAttack(enemy.hitPoints);
                    break;
                case 6:
                    notEffectiveAttack(enemy.hitPoints);
                    break;
            }
            break;

            return 0;

    }
}

int Creature::useUltimate() {
    std::cout << "R";

    return 0;
}

int Creature::evolve() {
    std::cout << "evolucja";
    return 0;
}

Creature::Creature( char *name, int strength, int agility, int hitPoints, int ultimate, int expPoints, int type) {
    Creature::name = name;
    Creature::strength = strength;
    Creature::agility = agility;
    Creature::hitPoints = hitPoints;
    Creature::ultimate = ultimate;
    Creature::expPoints = expPoints;
    Creature::type = type;
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


