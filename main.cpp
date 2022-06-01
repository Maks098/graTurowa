#include <iostream>
#include <vector>
#include "Creature.h"
#include <ctime>

void showCreatureList(std::vector<Creature> creatureList) {
    for (int i = 0; i < creatureList.size(); ++i) {
        std::cout << "Nr " << (i + 1) << " " << "Imie: " << creatureList.at(i).name <<
                  " Maksymalna ilosc punktow zdrowia: " << creatureList.at(i).maxHitPoints <<
                  " Punkty sily: " << creatureList.at(i).strength <<
                  " Punkty zwinnosci: " << creatureList.at(i).agility <<
                  " Typ: ";
        switch (creatureList.at(i).type) {
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

void showCreatureListWithHitPoints(std::vector<Creature> playerTeam) {
    for (int i = 0; i < playerTeam.size(); ++i) {
        std::cout << "Nr " << (i + 1) << " " << "Imie: " << playerTeam.at(i).name <<
                  " Maksymalna ilosc punktow zdrowia: " << playerTeam.at(i).maxHitPoints <<
                  " Obecna ilosc punktow zdrowia: " << playerTeam.at(i).currentHitPoints;
        if (playerTeam.at(i).currentHitPoints == 0) {
            std::cout << " Omdlale ";
        }
        std::cout << " Punkty sily: " << playerTeam.at(i).strength <<
                  " Punkty zwinnosci: " << playerTeam.at(i).agility <<
                  " Typ: ";
        switch (playerTeam.at(i).type) {
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

void checkingIfWon(Creature &creature, bool &on, std::vector<Creature> team) {
    if (creature.currentHitPoints <= 0) {
        std::cout << "Stworzenie " << creature.name << " zemdlalo!" << std::endl;
        if (team.size() == 0) {
            //1
            // on = false;
            std::cout << "Przeciwnik zostal pokonany";
        }
    }
}

void fight(std::vector<Creature> playerTeam, std::vector<Creature> enemyTeam) {
    showCreatureListWithHitPoints(enemyTeam);
    int creatureChooseToFight;
    std::vector<Creature> enemyFaintedCreatures;
    std::cout << "RUNDA 1" << std::endl <<
              "Wybierz stworzenie, ktore wystawisz do walki:" << std::endl;
    std::cin >> creatureChooseToFight;
    Creature chosenToFight = playerTeam.at(creatureChooseToFight - 1);
    int randomEnemyCreature = std::rand() % enemyTeam.size() - 1;
    std::cout << "Dziala1" << std::endl;
    Creature chosenEnemyToFight = enemyTeam.at(randomEnemyCreature);
    std::cout << "Przeciwnik wybral " << chosenEnemyToFight.name << std::endl;
    bool fightOn = true;
    int playerAction = 0;
    int changeCreature = 0;
    int changeFaintedCreature = 0;
    bool changeFaintedCreatureOn = true;
    while (fightOn) {
        std::cout << "Ilosc punktow zdrowia Twojego stworzenia: " << chosenToFight.currentHitPoints << " / "
                  << chosenToFight.maxHitPoints << std::endl;
        std::cout << "Ilosc punktow zdrowia przeciwnika: " << chosenEnemyToFight.currentHitPoints << " / "
                  << chosenEnemyToFight.maxHitPoints << std::endl;
        std::cout << "Jaki chcesz wykonac ruch?:" << std::endl <<
                  "1. Atakuj!" << std::endl <<
                  "2. Wykonaj ruch specjalny(" << chosenToFight.specialAttackStack << "/3)" << std::endl <<
                  "3. Ewoluuj(" << chosenToFight.currentExp << "/" << chosenToFight.level * 100 << ")" << std::endl <<
                  "4. Wymien stworzenie" << std::endl;
        showCreatureList(enemyTeam);
        std::cin >> playerAction;
        switch (playerAction) {
            case 1:
                chosenToFight.attack(chosenEnemyToFight);
                break;
            case 2:
                chosenToFight.useUltimate(chosenEnemyToFight);
                break;
            case 3:
                chosenToFight.evolve(chosenToFight);
                break;
            case 4:
                playerTeam.erase(playerTeam.begin() + creatureChooseToFight - 1);
                playerTeam.insert(playerTeam.begin() + creatureChooseToFight - 1, chosenToFight);
                showCreatureListWithHitPoints(playerTeam);
                std::cout << "Wpisz nr stworzenia na ktore chcesz zamienic swojego aktualnego bojownika:" << std::endl;
                std::cin >> changeCreature;
                creatureChooseToFight = changeCreature;
                if (playerTeam.at(changeCreature - 1).name == chosenToFight.name) {
                    std::cout << "Wybrales stworzenie aktualnie znajdujace sie na arenie" << std::endl;
                } else {
                    chosenToFight = playerTeam.at(changeCreature - 1);
                    std::cout << "Stworzenie zostalo zmienione na " << chosenToFight.name << std::endl;
                }
                break;
        }
        //checkingIfWon(chosenEnemyToFight, fightOn, enemyTeam);
        if (enemyTeam.size() == 0) {
            std::cout << "Przeciwnik zostal pokonany";
        } else {
            if (chosenEnemyToFight.currentHitPoints <= 0) {
                enemyFaintedCreatures.push_back(enemyTeam.at(randomEnemyCreature));
                enemyTeam.erase(enemyTeam.begin() + randomEnemyCreature);
                if (enemyTeam.size() == 0) {
                    std::cout << "Przeciwnik zostal pokonany ez" << std::endl;
                    fightOn = false;
                } else if (enemyTeam.size() == 1) {
                    randomEnemyCreature = 0;
                } else {
                    randomEnemyCreature = std::rand() % (enemyTeam.size() - 1);
                }
                chosenEnemyToFight = enemyTeam.at(randomEnemyCreature);
                std::cout << "Przeciwnik wystawil " << chosenEnemyToFight.name << std::endl;

            } else if (fightOn) {
                if (chosenEnemyToFight.specialAttackStack == 3) {
                    chosenEnemyToFight.useUltimate(chosenToFight);

                } else {
                    chosenEnemyToFight.attack(chosenToFight);
                }
                //checkingIfWon(chosenToFight, fightOn, playerTeam);
            }
            if (chosenToFight.currentHitPoints <= 0) {
                playerTeam.erase(playerTeam.begin() + creatureChooseToFight - 1);
                playerTeam.insert(playerTeam.begin() + creatureChooseToFight - 1, chosenToFight);
                showCreatureListWithHitPoints(playerTeam);
                std::cout << "Twoje stworzenie zostalo pokonane, musisz wybrac inne" << std::endl;
                while (changeFaintedCreatureOn) {
                    std::cin >> changeFaintedCreature;
                    if (playerTeam.at(changeFaintedCreature - 1).currentHitPoints == 0) {
                        std::cout << "Nie mozesz wybrac tego stworzenia. Jest ono niezdolne do walki" << std::endl;
                    } else {
                        chosenToFight = playerTeam.at(changeFaintedCreature);
                        changeFaintedCreatureOn = false;
                    }
                }

            }
            //if(enemyTeam.size()==0){
            //  fightOn=false;
        }
    }
}


int main() {
    srand(time(NULL));
    std::vector<Creature> chooseList;

    Creature kotor("Kotor", 5, 1, 10, 1, 1); // woda
    chooseList.push_back(kotor);
    Creature bellagoth("Bellagoth", 2, 1, 10, 1, 2); // ziemia
    chooseList.push_back(bellagoth);
    Creature dovahkiin("Dovahkiin", 5, 3, 10, 2, 3); // powietrze
    chooseList.push_back(dovahkiin);
    Creature diablo("Diablo", 2, 1, 10, 1, 4); //ogień
    chooseList.push_back(diablo);
    Creature miraak("Miraak", 2, 1, 10, 1, 5); //lód
    chooseList.push_back(miraak);
    Creature glados("GLaDOS", 4, 12, 12, 12, 6); //stal
    chooseList.push_back(glados);
    Creature tandi("Tandi", 2, 1, 10, 1, 1);
    chooseList.push_back(tandi);
    Creature mactavish("Mactavish", 2, 1, 10, 1, 1);
    chooseList.push_back(mactavish);
    Creature snake("Snake", 2, 1, 10, 1, 1);
    chooseList.push_back(snake);
    Creature zinyak("Zinyak", 2, 1, 10, 1, 1);
    chooseList.push_back(zinyak);
    Creature kenshi("Kenshi", 2, 1, 10, 1, 1);
    chooseList.push_back(kenshi);
    Creature clementine("Clementine", 2, 1, 10, 1, 1);
    chooseList.push_back(clementine);
    Creature shepard("Shepard", 2, 1, 10, 1, 1);
    chooseList.push_back(shepard);
    Creature artyom("Artyom", 2, 1, 10, 1, 1);
    chooseList.push_back(artyom);
    Creature strielok("Stierlok", 2, 1, 10, 1, 1);
    chooseList.push_back(strielok);
    Creature ezio("Ezio", 2, 1, 10, 1, 1);
    chooseList.push_back(ezio);
    std::vector<Creature> enemyChooseList;
    enemyChooseList.insert(enemyChooseList.end(), chooseList.begin(), chooseList.end());
    bool on = true;
    int creaChoose = 0;
    int creaConf = 0;
    std::vector<Creature> playerTeam;
    std::cout << "Witaj na arenie. " << std::endl;
    while (on) {
        std::cout << "Lista stworzen:" << std::endl;
        showCreatureList(chooseList);
        std::cout << "Wybierz stworzenia z ktorych chcesz stworzyc druzyne" << std::endl;
        std::cin >> creaChoose;
        creaChoose = creaChoose - 1;
        std::cout
                << "Czy napewno chcesz wybrac dane stworzenie? Wpisz 1 aby powtwierdzic. Wpisz dowolna inna liczbe,zeby"
                << std::endl <<
                "anulowac wybor:" << std::endl;

        std::cout << "Imie: " << chooseList.at(creaChoose).name <<
                  " Maksymalna ilosc punktow zdrowia: " << chooseList.at(creaChoose).maxHitPoints <<
                  " Punkty sily: " << chooseList.at(creaChoose).strength <<
                  " Punkty zwinnosci: " << chooseList.at(creaChoose).agility <<
                  " Typ: ";
        switch (chooseList.at(creaChoose).type) {
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
            playerTeam.push_back(chooseList.at(creaChoose));
            chooseList.erase(chooseList.begin() + creaChoose);
            std::cout << "Stworzenie zostalo dodane" << std::endl;
        } else {
            std::cout << "Anulowano wybor";
        }
        if (playerTeam.size() == 6) {
            std::cout << "Oto twoja druzyna:" << std::endl;
            showCreatureList(playerTeam);
            on = false;
        }
    }
    int enemyCreatureSelect;
    std::vector<Creature> enemyPlayerTeam1;
    for (int i = 0; i < 4; ++i) {
        enemyCreatureSelect = (std::rand() % enemyChooseList.size());
        enemyPlayerTeam1.push_back(enemyChooseList.at(enemyCreatureSelect));
        enemyChooseList.erase(enemyChooseList.begin() + enemyCreatureSelect);
    }
    std::vector<Creature> enemyPlayerTeam2;
    for (int i = 0; i < 4; ++i) {
        enemyCreatureSelect = (std::rand() % enemyChooseList.size());
        enemyPlayerTeam2.push_back(enemyChooseList.at(enemyCreatureSelect));
        enemyChooseList.erase(enemyChooseList.begin() + enemyCreatureSelect);
    }
    std::vector<Creature> enemyPlayerTeam3;
    for (int i = 0; i < 4; ++i) {
        enemyCreatureSelect = (std::rand() % enemyChooseList.size());
        enemyPlayerTeam3.push_back(enemyChooseList.at(enemyCreatureSelect));
        enemyChooseList.erase(enemyChooseList.begin() + enemyCreatureSelect);
    }



/*
    int creatureChooseToFight;
    std::cout << "RUNDA 1" << std::endl <<
              "Wybierz stworzenie, ktore wystawisz do walki:" << std::endl;
    std::cin >> creatureChooseToFight;
    Creature chosenToFight = playerTeam.at(creatureChooseToFight - 1);
    int randomEnemyCreature = std::rand() % enemyPlayerTeam1.size();
    Creature chosenEnemyToFight = enemyPlayerTeam1.at(randomEnemyCreature);
    std::cout << "Przeciwnik wybral " << chosenEnemyToFight.name << std::endl;
    bool fightOn = true;
    int playerAction = 0;
    int changeCreature = 0;
    int changeFaintedCreature=0;
    bool changeFaintedCreatureOn=true;
    while (fightOn) {
        std::cout << "Ilosc punktow zdrowia Twojego stworzenia: " << chosenToFight.currentHitPoints << " / "
                  << chosenToFight.maxHitPoints << std::endl;
        std::cout << "Ilosc punktow zdrowia przeciwnika: " << chosenEnemyToFight.currentHitPoints << " / "
                  << chosenEnemyToFight.maxHitPoints << std::endl;
        std::cout << "Jaki chcesz wykonac ruch?:" << std::endl <<
                  "1. Atakuj!" << std::endl <<
                  "2. Wykonaj ruch specjalny(" << chosenToFight.specialAttackStack << "/3)" << std::endl <<
                  "3. Ewoluuj(" << chosenToFight.currentExp << "/" << chosenToFight.level * 100 << ")" << std::endl <<
                  "4. Wymien stworzenie" << std::endl;
        std::cin >> playerAction;
        switch (playerAction) {
            case 1:
                chosenToFight.attack(chosenEnemyToFight);
                break;
            case 2:
                chosenToFight.useUltimate(chosenEnemyToFight);
                break;
            case 3:
                chosenToFight.evolve(chosenToFight);
                break;
            case 4:
                playerTeam.erase(playerTeam.begin() + creatureChooseToFight - 1);
                playerTeam.insert(playerTeam.begin() + creatureChooseToFight - 1, chosenToFight);
                showCreatureListWithHitPoints(playerTeam);
                std::cout << "Wpisz nr stworzenia na ktore chcesz zamienic swojego aktualnego bojownika:" << std::endl;
                std::cin >> changeCreature;
                creatureChooseToFight=changeCreature;
                if (playerTeam.at(changeCreature-1).name == chosenToFight.name) {
                    std::cout << "Wybrales stworzenie aktualnie znajdujace sie na arenie" << std::endl;
                } else {
                    chosenToFight = playerTeam.at(changeCreature - 1);
                    std::cout << "Stworzenie zostalo zmienione na " << chosenToFight.name << std::endl;
                }
                break;
        }
        checkingIfWon(chosenEnemyToFight, fightOn, enemyPlayerTeam1);
        if (chosenEnemyToFight.currentHitPoints <= 0) {
            enemyPlayerTeam1.erase(enemyPlayerTeam1.begin() + randomEnemyCreature);
            randomEnemyCreature = std::rand() % enemyPlayerTeam1.size() - 1;
            chosenEnemyToFight = enemyPlayerTeam1.at(randomEnemyCreature);
            std::cout << "Przeciwnik wystawil " << chosenEnemyToFight.name << std::endl;
        } else if (fightOn) {
            if (chosenEnemyToFight.specialAttackStack == 3) {
                chosenEnemyToFight.useUltimate(chosenToFight);

            } else {
                chosenEnemyToFight.attack(chosenToFight);
            }
            checkingIfWon(chosenToFight, fightOn, playerTeam);
        }
        if (chosenToFight.currentHitPoints <= 0) {
            std::cout << "Twoje stworzenie zostalo pokonane, musisz wybrac inne" << std::endl;
            while(changeFaintedCreatureOn) {
                showCreatureListWithHitPoints(playerTeam);
                std::cin >> changeFaintedCreature;
                if (playerTeam.at(changeFaintedCreature).currentHitPoints <= 0) {
                    std::cout << "Nie mozesz wybrac tego stworzenia. Jest ono niezdolne do walki" << std::endl;
                } else
                    chosenToFight = playerTeam.at(changeFaintedCreature);
                changeFaintedCreatureOn=false;
            }
        }
    }
 */
    fight(playerTeam, enemyPlayerTeam1);
    return 0;
}