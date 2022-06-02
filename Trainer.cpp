//
// Created by Maks on 01.06.2022.
//

#include <iostream>
#include "Trainer.h"

Trainer::Trainer(int nr, const std::vector<Creature> &creatures) : nr(nr), creatures(creatures) {}

void Trainer::showCreatureList() {
    for (int i = 0; i < Trainer::creatures.size(); ++i) {
        std::cout << "Nr " << (i + 1) << " " << "Imie: " << Trainer::creatures.at(i).name <<
                  " Maksymalna ilosc punktow zdrowia: " << Trainer::creatures.at(i).maxHitPoints <<
                  " Punkty sily: " << Trainer::creatures.at(i).strength <<
                  " Punkty zwinnosci: " << Trainer::creatures.at(i).agility <<
                  " Typ: ";
        switch (Trainer::creatures.at(i).type) {
            case 1:
                std::cout << "Wodny" << std::endl;
                break;
            case 2:
                std::cout << "Ziemisty" << std::endl;
                break;
            case 3:
                std::cout << "Powietrzny" << std::endl;
                break;
            case 4:
                std::cout << "Ognisty" << std::endl;
                break;
            case 5:
                std::cout << "Lodowy" << std::endl;
                break;
            case 6:
                std::cout << "Stalowy" << std::endl;
                break;
        }
    }
}

void Trainer::showCreatureListWithHitPoints() {
    for (int i = 0; i < Trainer::creatures.size(); ++i) {
        std::cout << "Nr " << (i + 1) << " " << "Imie: " << Trainer::creatures.at(i).name <<
                  " Maksymalna ilosc punktow zdrowia: " << Trainer::creatures.at(i).maxHitPoints <<
                  " Obecna ilosc punktow zdrowia: " << Trainer::creatures.at(i).currentHitPoints;
        if (Trainer::creatures.at(i).currentHitPoints == 0) {
            std::cout << " Omdlale ";
        }
        std::cout << " Punkty sily: " << Trainer::creatures.at(i).strength <<
                  " Punkty zwinnosci: " << Trainer::creatures.at(i).agility <<
                  " Typ: ";
        switch (Trainer::creatures.at(i).type) {
            case 1:
                std::cout << "Wodny" << std::endl;
                break;
            case 2:
                std::cout << "Ziemisty" << std::endl;
                break;
            case 3:
                std::cout << "Powietrzny" << std::endl;
                break;
            case 4:
                std::cout << "Ognisty" << std::endl;
                break;
            case 5:
                std::cout << "Lodowy" << std::endl;
                break;
            case 6:
                std::cout << "Stalowy" << std::endl;
                break;
        }
    }
}

void Trainer::fight(Trainer enemy) {
    std::cout << "Druzyna przeciwnika: " << std::endl;
    enemy.showCreatureList();
    int creatureChooseToFight = 0;
    std::vector<Creature> enemyFaintedCreatures;
    std::cout << "RUNDA 1" << std::endl <<
              "Wybierz stworzenie, ktore wystawisz do walki:" << std::endl;
    std::cin >> creatureChooseToFight;
    Creature chosenToFight = Trainer::creatures.at(creatureChooseToFight - 1);
    int randomEnemyCreature = std::rand() % (enemy.creatures.size() - 1);
    Creature chosenEnemyToFight = enemy.creatures.at(randomEnemyCreature);
    std::cout << "Przeciwnik wybral " << chosenEnemyToFight.name << std::endl;
    bool fightOn = true;
    int playerAction = 0;
    int changeCreature = 0;
    int changeFaintedCreature = 0;
    bool changeFaintedCreatureOn = true;
    while (fightOn) {
        std::cout << "Ilosc punktow zdrowia Twojego stworzenia: " << chosenToFight.currentHitPoints << " / "
                  << chosenToFight.maxHitPoints << std::endl <<
                  "Ilosc punktow zdrowia przeciwnika: " << chosenEnemyToFight.currentHitPoints << " / "
                  << chosenEnemyToFight.maxHitPoints << std::endl <<
                  "Jaki chcesz wykonac ruch?:" << std::endl <<
                  "1. Atakuj!" << std::endl <<
                  "2. Wykonaj ruch specjalny(" << chosenToFight.specialAttackStack << "/3)" << std::endl <<
                  "3. Ewoluuj(" << chosenToFight.currentExp << "/" << chosenToFight.level * 100 << ")" << std::endl <<
                  "4. Wymien stworzenie" << std::endl;
        enemy.showCreatureList();
        std::cin >> playerAction;
        switch (playerAction) {
            case 1:
                chosenToFight.attack(chosenEnemyToFight);
                break;
            case 2:
                chosenToFight.useUltimate(chosenEnemyToFight);
                break;
            case 3:
                chosenToFight.evolve();
                std::cout << "Sila" << chosenToFight.strength << std::endl;
                break;
            case 4:
                Trainer::changeCreatureOption(chosenToFight, creatureChooseToFight);
                break;
        }
        if (chosenEnemyToFight.currentHitPoints <= 0) {
            chosenToFight.currentExp = chosenToFight.currentExp + chosenEnemyToFight.expPoints;
            enemyFaintedCreatures.push_back(enemy.creatures.at(randomEnemyCreature));
            enemy.creatures.erase(enemy.creatures.begin() + randomEnemyCreature);
            if (enemy.creatures.size() == 0) {
                std::cout << "Przeciwnik zostal pokonany ez" << std::endl;
                fightOn = false;
            } else if (enemy.creatures.size() == 1) {
                randomEnemyCreature = 0;
                chosenEnemyToFight = enemy.creatures.at(randomEnemyCreature);
                std::cout << "Przeciwnik wystawil " << chosenEnemyToFight.name << std::endl;
            } else if (fightOn) {
                randomEnemyCreature = std::rand() % (enemy.creatures.size() - 1);
                chosenEnemyToFight = enemy.creatures.at(randomEnemyCreature);
                std::cout << "Przeciwnik wystawil " << chosenEnemyToFight.name << std::endl;
            }
        } else if (fightOn) {
            if (chosenEnemyToFight.specialAttackStack == 3) {
                chosenEnemyToFight.useUltimate(chosenToFight);
            } else {
                chosenEnemyToFight.attack(chosenToFight);
            }
        }
        if (chosenToFight.currentHitPoints <= 0) {
            chosenToFight.currentHitPoints = 0;
            std::cout << "Twoje stworzenie zostalo pokonane, musisz wybrac inne" << std::endl;
            changeCreatureOption(chosenToFight, creatureChooseToFight);
        }
    }
}

void Trainer::diffScaling(int scaling) {
    for (int i = 0; i < Trainer::creatures.size(); ++i) {
        Trainer::creatures.at(i).maxHitPoints = Trainer::creatures.at(i).maxHitPoints * scaling;
        Trainer::creatures.at(i).strength = Trainer::creatures.at(i).strength * scaling;
        Trainer::creatures.at(i).agility = Trainer::creatures.at(i).agility * scaling;
        Trainer::creatures.at(i).expPoints = Trainer::creatures.at(i).expPoints * scaling * 2;
        Trainer::creatures.at(i).currentHitPoints = Trainer::creatures.at(i).maxHitPoints;
    }
}

void Trainer::resetHp() {
    for (int i = 0; i < Trainer::creatures.size(); ++i) {
        Trainer::creatures.at(i).currentHitPoints = Trainer::creatures.at(i).maxHitPoints;
    }
}

void Trainer::changeCreatureOption(Creature &chosenToFight, int &creatureChooseToFight) {
    int changingCreature = 0;
    Trainer::creatures.erase(Trainer::creatures.begin() + creatureChooseToFight - 1);
    Trainer::creatures.insert(Trainer::creatures.begin() + creatureChooseToFight - 1, chosenToFight);
    Trainer::showCreatureListWithHitPoints();
    std::cout << "Wpisz nr stworzenia na ktore chcesz zamienic swojego aktualnego bojownika:" << std::endl;
    std::cin >> changingCreature;
    creatureChooseToFight = changingCreature;
    if (Trainer::creatures.at(changingCreature - 1).name == chosenToFight.name) {
        std::cout << "Wybrales stworzenie aktualnie znajdujace sie na arenie" << std::endl;
    } else {
        chosenToFight = Trainer::creatures.at(changingCreature - 1);
        std::cout << "Stworzenie zostalo zmienione na " << chosenToFight.name << std::endl;
    }
}