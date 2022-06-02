#include <iostream>
#include <vector>
#include "Creature.h"
#include <ctime>
#include "Trainer.h"


int main() {
    srand(time(NULL));
    std::vector<Creature> chooseList;

    Creature kotor("Kotor", 5, 5, 10, 50, 1); // woda
    chooseList.push_back(kotor);
    Creature bellagoth("Bellagoth", 4, 4, 10, 50, 2); // ziemia
    chooseList.push_back(bellagoth);
    Creature dovahkiin("Dovahkiin", 5, 2, 10, 50, 3); // powietrze
    chooseList.push_back(dovahkiin);
    Creature diablo("Diablo", 4, 4, 10, 50, 4); //ogień
    chooseList.push_back(diablo);
    Creature miraak("Miraak", 5, 4, 8, 50, 5); //lód
    chooseList.push_back(miraak);
    Creature glados("GLaDOS", 4, 2, 16, 50, 6); //stal
    chooseList.push_back(glados);
    Creature tandi("Tandi", 7, 4, 6, 50, 1);
    chooseList.push_back(tandi);
    Creature mactavish("Mactavish", 4, 3, 12, 50, 3);
    chooseList.push_back(mactavish);
    Creature snake("Snake", 5, 2, 12, 50, 2);
    chooseList.push_back(snake);
    Creature zinyak("Zinyak", 7, 1, 10, 50, 6);
    chooseList.push_back(zinyak);
    Creature kenshi("Kenshi", 2, 6, 10, 50, 5);
    chooseList.push_back(kenshi);
    Creature clementine("Clementine", 6, 2, 10, 50, 4);
    chooseList.push_back(clementine);
    Creature shepard("Shepard", 5, 3, 10, 50, 6);
    chooseList.push_back(shepard);
    Creature artyom("Artyom", 4, 4, 10, 50, 2);
    chooseList.push_back(artyom);
    Creature strielok("Stierlok", 8, 3, 6, 50, 6);
    chooseList.push_back(strielok);
    Creature ezio("Ezio", 4, 8, 4, 50, 1); //16
    chooseList.push_back(ezio);
    Creature steve("Steve", 4, 2, 14, 50, 2);
    chooseList.push_back(steve);
    Creature bandicoot("Bandicoot", 4, 4, 10, 50, 3);
    chooseList.push_back(bandicoot);
    Creature alduin("Alduin", 2, 6, 10, 50, 5);
    chooseList.push_back(alduin);
    Creature kratos("Kratos", 3, 5, 10, 50, 1);
    chooseList.push_back(kratos);
    Creature doomguy("Doomguy", 5, 3, 10, 50, 5);
    chooseList.push_back(doomguy);
    Creature garrus("Garrus", 7, 1, 10, 50, 3);
    chooseList.push_back(garrus);

    //std::vector<Creature> enemyChooseList;
    //enemyChooseList.insert(enemyChooseList.end(), chooseList.begin(), chooseList.end());
    bool on = true;
    int creaChoose = 0;
    int creaConf = 0;
    std::vector<Creature> playerTeam;
    Trainer player(0, playerTeam);
    std::cout << "Witaj na arenie. " << std::endl;
    while (on) {
        std::cout << "Lista stworzen:" << std::endl;
        for (int i = 0; i < chooseList.size(); ++i) {
            std::cout << "Nr " << (i + 1) << " " << "Imie: " << chooseList.at(i).name <<
                      " Maksymalna ilosc punktow zdrowia: " << chooseList.at(i).maxHitPoints <<
                      " Punkty sily: " << chooseList.at(i).strength <<
                      " Punkty zwinnosci: " << chooseList.at(i).agility <<
                      " Typ: ";
            switch (chooseList.at(i).type) {
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
            player.creatures.push_back(chooseList.at(creaChoose));
            chooseList.erase(chooseList.begin() + creaChoose);
            std::cout << "Stworzenie zostalo dodane" << std::endl;
        } else {
            std::cout << "Anulowano wybor";
        }
        if (player.creatures.size() == 6) {
            std::cout << "Oto twoja druzyna:" << std::endl;
            player.showCreatureList();
            on = false;
        }
    }
    int enemyCreatureSelect;
    std::vector<Creature> enemyTeam1;
    for (int i = 0; i < 4; ++i) {
        enemyCreatureSelect = (std::rand() % chooseList.size());
        enemyTeam1.push_back(chooseList.at(enemyCreatureSelect));
        chooseList.erase(chooseList.begin() + enemyCreatureSelect);
    }
    Trainer enemy1(1, enemyTeam1);
    std::vector<Creature> enemyPlayerTeam2;
    for (int i = 0; i < 4; ++i) {
        enemyCreatureSelect = (std::rand() % chooseList.size());
        enemyPlayerTeam2.push_back(chooseList.at(enemyCreatureSelect));
        chooseList.erase(chooseList.begin() + enemyCreatureSelect);
    }
    Trainer enemy2(2, enemyPlayerTeam2);
    std::vector<Creature> enemyPlayerTeam3;
    for (int i = 0; i < 4; ++i) {
        enemyCreatureSelect = (std::rand() % chooseList.size());
        enemyPlayerTeam3.push_back(chooseList.at(enemyCreatureSelect));
        chooseList.erase(chooseList.begin() + enemyCreatureSelect);
    }
    Trainer enemy3(3, enemyPlayerTeam3);
    player.fight(enemy1);
    player.resetHp();
    enemy2.diffScaling(2);
    player.fight(enemy2);
    player.resetHp();
    enemy3.diffScaling(3);
    player.fight(enemy3);
    return 0;
}