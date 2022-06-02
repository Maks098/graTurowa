//
// Created by Maks on 19.05.2022.
//
#include <iostream>
#include "Creature.h"

int Creature::attack(Creature &enemy) {
    int playerAgility = rand() % Creature::agility;
    int enemyAgility = rand() % enemy.agility;
    int enemyStartHp = enemy.currentHitPoints;
    if (playerAgility >= enemyAgility) {
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
                switch (enemy.type) {
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
                switch (enemy.type) {
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
                        normalAttack(enemy.currentHitPoints);
                        break;
                    case 6:
                        notEffectiveAttack(enemy.currentHitPoints);
                        break;
                }
                break;
        }
        std::cout << "Stworzenie " << enemy.name << " otrzymalo " << enemyStartHp - enemy.currentHitPoints << " obrazen"
                  << std::endl;
        Creature::specialAttackStack++;
        if (Creature::specialAttackStack >= 3) {
            specialAttackStack = 3;
        }
    } else
        std::cout << "Stworzenie " << enemy.name << " uniknelo ciosu!" << std::endl;
    return 0;
}

int Creature::useUltimate(Creature &enemy) {
    if (Creature::specialAttackStack == 3) {
        Creature::superEffectiveAttack(enemy.currentHitPoints);
        Creature::specialAttackStack = 0;
    } else {
        std::cout << "Twoje stworzenie nie ma wystarczajaco ladunkow aby uzyc superumiejetnosci" << std::endl;
    }
    return 0;
}

int Creature::evolve() {
    int upgrdChoose = 0;
    bool upgrdOn = true;
    if (Creature::currentExp >= 100 * Creature::level) {
        Creature::currentExp = Creature::currentExp - (100 * Creature::level);
        for (int i = 1; i < 3; ++i) {
            std::cout << "Wybierz " << i << ". statystyke ktora chcesz zwiekszyc: " << std::endl <<
                      "1. Punkty sily: " << Creature::strength << std::endl <<
                      "2. Punkty zwinnosci " << Creature::agility << std::endl <<
                      "3. Maksymalna ilosc punktow zycia: " << Creature::maxHitPoints << std::endl;
            std::cin >> upgrdChoose;
            std::cout << "dziala1" << std::endl;
            while (upgrdOn) {
                std::cout << "dziala2" << std::endl;
                switch (upgrdChoose) {
                    case 1:
                        Creature::strength = (Creature::strength + 1);
                        upgrdOn = false;
                        break;
                    case 2:
                        Creature::agility = (Creature::agility + 1);
                        upgrdOn = false;
                        break;
                    case 3:
                        Creature::maxHitPoints = (Creature::maxHitPoints + 1);
                        upgrdOn = false;
                        break;
                    default:
                        std::cout << "Podano nieodpowiednie rzadanie. Wprowadz liczbe jeszcze raz";
                }
            }
            if (i != 2) {
                upgrdOn = true;
            }
        }
    }
    Creature::level = Creature::level + 1;
    Creature::currentHitPoints = Creature::maxHitPoints;
    return 0;
}


Creature::Creature(std::string name, int strength, int agility, int maxHitPoints, int expPoints, int type) {
    Creature::name = name;
    Creature::strength = strength;
    Creature::agility = agility;
    Creature::maxHitPoints = maxHitPoints;
    Creature::currentHitPoints = maxHitPoints;
    Creature::expPoints = expPoints;
    Creature::type = type;
    Creature::level = 1;
    Creature::currentExp = 0;
    Creature::specialAttackStack = 0;
}

int Creature::superEffectiveAttack(int &enemyHP) {
    enemyHP = enemyHP - (Creature::strength * 2);
    return 0;
}

int Creature::notEffectiveAttack(int &enemyHP) {
    enemyHP = enemyHP - (Creature::strength / 2);
    return 0;
}

int Creature::normalAttack(int &enemyHP) {
    enemyHP = enemyHP - Creature::strength;
    return 0;
}