//
// Created by Maks on 01.06.2022.
//

#include <iostream>
#include <fstream>
#include "Trainer.h"

/**
 *
 * @param nr
 * @param creatures
 */
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
    int turn = 0;
    std::cout << "Druzyna przeciwnika: " << std::endl;
    enemy.showCreatureList();
    int creatureChooseToFight = 0;
    std::vector<Creature> enemyFaintedCreatures;
    std::cout << "RUNDA " << enemy.nr << std::endl <<
              "Wybierz stworzenie, ktore wystawisz do walki:" << std::endl;
    std::cin >> creatureChooseToFight;
    Creature chosenToFight = Trainer::creatures.at(creatureChooseToFight - 1);
    int randomEnemyCreature = std::rand() % (enemy.creatures.size() - 1);
    Creature chosenEnemyToFight = enemy.creatures.at(randomEnemyCreature);
    std::cout << "Przeciwnik wybral " << chosenEnemyToFight.name << std::endl;
    bool fightOn = true;
    int playerAction = 0;
    while (fightOn) {
        std::cout << "Ilosc punktow zdrowia Twojego stworzenia: " << chosenToFight.currentHitPoints << " / "
                  << chosenToFight.maxHitPoints << std::endl <<
                  "Ilosc punktow zdrowia przeciwnika: " << chosenEnemyToFight.currentHitPoints << " / "
                  << chosenEnemyToFight.maxHitPoints << std::endl <<
                  "Jaki chcesz wykonac ruch?:" << std::endl <<
                  "1. Atakuj!" << std::endl <<
                  "2. Wykonaj ruch specjalny(" << chosenToFight.specialAttackStack << "/3)";
        switch (chosenToFight.specialInteraction) {
            case 1:
                std::cout << " Leczniczy dotyk";
                break;
            case 2:
                std::cout << " Potezny cios";
                break;
        }
        std::cout << std::endl <<
                  "3. Ewoluuj(" << chosenToFight.currentExp << "/" << chosenToFight.level * 100 << ")" << std::endl <<
                  "4. Wymien stworzenie" << std::endl;
        std::cout << "Tura:" << turn << std::endl;
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
                std::cout << "Przeciwnik zostal pokonany" << std::endl;
                Trainer::creatures.erase(Trainer::creatures.begin() + creatureChooseToFight - 1);
                Trainer::creatures.insert(Trainer::creatures.begin() + creatureChooseToFight - 1, chosenToFight);
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
        turn = turn + 1;
    }
}

void Trainer::diffScaling(double scaling) {
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
    bool changeOn = true;
    Trainer::creatures.erase(Trainer::creatures.begin() + creatureChooseToFight - 1);
    Trainer::creatures.insert(Trainer::creatures.begin() + creatureChooseToFight - 1, chosenToFight);
    while (changeOn) {
        Trainer::showCreatureListWithHitPoints();
        std::cout << "Wpisz nr stworzenia na ktore chcesz zamienic swojego aktualnego bojownika:" << std::endl;
        std::cin >> changingCreature;
        creatureChooseToFight = changingCreature;
        if (Trainer::creatures.at(changingCreature - 1).currentHitPoints <= 0) {
            std::cout << "Nie mozesz wybrac tego stworzenia. Jest ono nieprzytomne" << std::endl;
        } else if (Trainer::creatures.at(changingCreature - 1).name == chosenToFight.name) {
            std::cout << "Wybrales stworzenie aktualnie znajdujace sie na arenie" << std::endl;
        } else {
            chosenToFight = Trainer::creatures.at(changingCreature - 1);
            std::cout << "Stworzenie zostalo zmienione na " << chosenToFight.name << std::endl;
            changeOn = false;
        }
    }
}


void Trainer::choosingTeam(std::vector<Creature> chooseList, std::vector<Creature> creaturesToChooseFrom) {
    std::cout << "Witaj na arenie. " << std::endl;
    bool on = true;
    std::string creatureChoose = "0";
    int creaConf = 0;
    while (on) {
        std::cout << "Lista stworzen:" << std::endl;
        for (int i = 0; i < creaturesToChooseFrom.size(); ++i) {
            std::cout << "Nr " << (i + 1) << " " << "Imie: " << creaturesToChooseFrom.at(i).name <<
                      " Maksymalna ilosc punktow zdrowia: " << creaturesToChooseFrom.at(i).maxHitPoints <<
                      " Punkty sily: " << creaturesToChooseFrom.at(i).strength <<
                      " Punkty zwinnosci: " << creaturesToChooseFrom.at(i).agility <<
                      " Typ: ";
            switch (creaturesToChooseFrom.at(i).type) {
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
        std::cout << "Wybierz stworzenia z ktorych chcesz stworzyc druzyne" << std::endl;

        std::cin >> creatureChoose;

        if (creatureChoose == "--help" || creatureChoose == "-h") {
            std::cout << "Wybierz liczbe porzadkowa stworzenia ktorego chcesz dodac do swojej druzyny" << std::endl;
        } else {
            int creaChoose = std::stoi(creatureChoose);
            creaChoose = creaChoose - 1;
            std::cout
                    << "Czy napewno chcesz wybrac dane stworzenie? Wpisz 1 aby powtwierdzic. Wpisz dowolna inna liczbe,zeby"
                    << std::endl <<
                    "anulowac wybor:" << std::endl;

            std::cout << "Imie: " << creaturesToChooseFrom.at(creaChoose).name <<
                      " Maksymalna ilosc punktow zdrowia: " << creaturesToChooseFrom.at(creaChoose).maxHitPoints <<
                      " Punkty sily: " << creaturesToChooseFrom.at(creaChoose).strength <<
                      " Punkty zwinnosci: " << creaturesToChooseFrom.at(creaChoose).agility <<
                      " Typ: ";
            switch (creaturesToChooseFrom.at(creaChoose).type) {
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
            std::cin >> creaConf;
            if (creaConf == 1) {
                Trainer::creatures.push_back(creaturesToChooseFrom.at(creaChoose));
                creaturesToChooseFrom.erase(creaturesToChooseFrom.begin() + creaChoose);
                std::cout << "Stworzenie zostalo dodane" << std::endl;
            } else {
                std::cout << "Anulowano wybor";
            }
            if (Trainer::creatures.size() == 6) {
                std::cout << "Oto twoja druzyna:" << std::endl;
                Trainer::showCreatureList();
                on = false;
            }
        }
    }
}

void Trainer::saveToFile(Trainer player, Trainer enemy1, Trainer enemy2, Trainer enemy3, Trainer enemy4) {
    std::cout << "Czy chcesz zapisac stan gry? Wpisz 1 aby zapisac, wpisz dowolna inna cyfra aby kontynowac rozgrywke"
              << std::endl;
    int saveChoose = 0;
    std::cin >> saveChoose;
    if (saveChoose == 1) {
        std::ofstream gameSave("C://Test//GameSave.txt", std::ofstream::out);
       // gameSave<< "player \n";
        for (int i = 0; i < player.creatures.size(); ++i) {
            gameSave << player.creatures.at(i).name << " ";
            gameSave << player.creatures.at(i).strength << " ";
            gameSave << player.creatures.at(i).agility << " ";
            gameSave << player.creatures.at(i).maxHitPoints << " ";
            gameSave << player.creatures.at(i).expPoints << " ";
            gameSave << player.creatures.at(i).type << " ";
            gameSave << player.creatures.at(i).level << " ";
            gameSave << player.creatures.at(i).currentExp << " ";
            gameSave << player.creatures.at(i).specialAttackStack << " ";
            gameSave << player.creatures.at(i).specialInteraction << "\n";
        }
       // gameSave<< "enemy1 \n";
        for (int i = 0; i < enemy1.creatures.size(); ++i) {
            gameSave << enemy1.creatures.at(i).name << " ";
            gameSave << enemy1.creatures.at(i).strength << " ";
            gameSave << enemy1.creatures.at(i).agility << " ";
            gameSave << enemy1.creatures.at(i).maxHitPoints << " ";
            gameSave << enemy1.creatures.at(i).expPoints << " ";
            gameSave << enemy1.creatures.at(i).type << " ";
            gameSave << enemy1.creatures.at(i).level << " ";
            gameSave << enemy1.creatures.at(i).currentExp << " ";
            gameSave << enemy1.creatures.at(i).specialAttackStack << " ";
            gameSave << enemy1.creatures.at(i).specialInteraction << "\n";
        }
      //  gameSave<< "enemy2 \n";
        for (int i = 0; i < enemy2.creatures.size(); ++i) {
            gameSave << enemy2.creatures.at(i).name << " ";
            gameSave << enemy2.creatures.at(i).strength << " ";
            gameSave << enemy2.creatures.at(i).agility << " ";
            gameSave << enemy2.creatures.at(i).maxHitPoints << " ";
            gameSave << enemy2.creatures.at(i).expPoints << " ";
            gameSave << enemy2.creatures.at(i).type << " ";
            gameSave << enemy2.creatures.at(i).level << " ";
            gameSave << enemy2.creatures.at(i).currentExp << " ";
            gameSave << enemy2.creatures.at(i).specialAttackStack << " ";
            gameSave << enemy2.creatures.at(i).specialInteraction << "\n";
        }
       // gameSave<< "enemy3 \n";
        for (int i = 0; i < enemy3.creatures.size(); ++i) {
            gameSave << enemy3.creatures.at(i).name << " ";
            gameSave << enemy3.creatures.at(i).strength << " ";
            gameSave << enemy3.creatures.at(i).agility << " ";
            gameSave << enemy3.creatures.at(i).maxHitPoints << " ";
            gameSave << enemy3.creatures.at(i).expPoints << " ";
            gameSave << enemy3.creatures.at(i).type << " ";
            gameSave << enemy3.creatures.at(i).level << " ";
            gameSave << enemy3.creatures.at(i).currentExp << " ";
            gameSave << enemy3.creatures.at(i).specialAttackStack << " ";
            gameSave << enemy3.creatures.at(i).specialInteraction << "\n";
        }
       // gameSave<< "enemy4 \n";
        for (int i = 0; i < enemy4.creatures.size(); ++i) {
            gameSave << enemy4.creatures.at(i).name << " ";
            gameSave << enemy4.creatures.at(i).strength << " ";
            gameSave << enemy4.creatures.at(i).agility << " ";
            gameSave << enemy4.creatures.at(i).maxHitPoints << " ";
            gameSave << enemy4.creatures.at(i).expPoints << " ";
            gameSave << enemy4.creatures.at(i).type << " ";
            gameSave << enemy4.creatures.at(i).level << " ";
            gameSave << enemy4.creatures.at(i).currentExp << " ";
            gameSave << enemy4.creatures.at(i).specialAttackStack << " ";
            gameSave << enemy4.creatures.at(i).specialInteraction << "\n";
        }
         gameSave.close();
        std::cout << "Pomyslnie zapisano stan gry" << std::endl;
    } else
        std::cout << "Rozgrywka wznowiona" << std::endl;
}




