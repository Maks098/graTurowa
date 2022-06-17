#include <iostream>
#include <vector>
#include "Creature.h"
#include <ctime>
#include <fstream>
#include <sstream>
#include "Trainer.h"


int main() {
    srand(time(NULL));
    std::vector<Creature> chooseList;

    Creature kotor("Kotor", 50, 50, 10, 50, 1, 1); // woda
    chooseList.push_back(kotor);
    Creature bellagoth("Bellagoth", 4, 4, 10, 50, 2, 2); // ziemia
    chooseList.push_back(bellagoth);
    Creature dovahkiin("Dovahkiin", 5, 2, 10, 50, 3, 1); // powietrze
    chooseList.push_back(dovahkiin);
    Creature diablo("Diablo", 4, 4, 10, 50, 4, 2); //ogień
    chooseList.push_back(diablo);
    Creature miraak("Miraak", 5, 4, 8, 50, 5, 1); //lód
    chooseList.push_back(miraak);
    Creature glados("GLaDOS", 4, 2, 16, 50, 6, 2); //stal
    chooseList.push_back(glados);
    Creature tandi("Tandi", 7, 4, 6, 50, 1, 1);
    chooseList.push_back(tandi);
    Creature mactavish("Mactavish", 4, 3, 12, 50, 3, 1);
    chooseList.push_back(mactavish);
    Creature snake("Snake", 5, 2, 12, 50, 2, 2);
    chooseList.push_back(snake);
    Creature zinyak("Zinyak", 7, 1, 10, 50, 6, 2);
    chooseList.push_back(zinyak);
    Creature kenshi("Kenshi", 2, 6, 10, 50, 5, 1);
    chooseList.push_back(kenshi);
    Creature clementine("Clementine", 6, 2, 10, 50, 4, 2);
    chooseList.push_back(clementine);
    Creature shepard("Shepard", 5, 3, 10, 50, 6, 1);
    chooseList.push_back(shepard);
    Creature artyom("Artyom", 4, 4, 10, 50, 2, 1);
    chooseList.push_back(artyom);
    Creature strielok("Stierlok", 8, 3, 6, 50, 6, 2);
    chooseList.push_back(strielok);
    Creature ezio("Ezio", 4, 8, 4, 50, 1, 2); //16
    chooseList.push_back(ezio);
    Creature steve("Steve", 4, 2, 14, 50, 2, 1);
    chooseList.push_back(steve);
    Creature bandicoot("Bandicoot", 4, 4, 10, 50, 3, 2);
    chooseList.push_back(bandicoot);
    Creature alduin("Alduin", 2, 6, 10, 50, 5, 1);
    chooseList.push_back(alduin);
    Creature kratos("Kratos", 3, 5, 10, 50, 1, 1);
    chooseList.push_back(kratos);
    Creature doomguy("Doomguy", 5, 3, 10, 50, 5, 2);
    chooseList.push_back(doomguy);
    Creature garrus("Garrus", 7, 1, 10, 50, 3, 2);
    chooseList.push_back(garrus);
    Creature tiyanki("Tiyanki", 4, 4, 10, 50, 1, 1);
    chooseList.push_back(tiyanki);
    Creature mrHouse("Mr. House", 2, 5, 12, 50, 6, 1);
    chooseList.push_back(mrHouse);
    Creature johnnyGat("Johhny gat", 3, 3, 14, 50, 2, 2);
    chooseList.push_back(johnnyGat);
    Creature mason("Mason", 2, 5, 12, 50, 3, 1);
    chooseList.push_back(mason);

    std::cout << "Czy chcesz wczytac zapis? Wpisz 1 aby wczytac, wpisz dowolna inna cyfre aby rozpoczac nowa gre"
              << std::endl;
    int load=0;
    std::cin>>load;
    if(load==1){
//        std::ifstream a("GameSave.txt");
//        std::string line;
//        std::string name;
//        std::string parts[10];
//        while(std::getline(a,line)){
//            int i=0;
//            std::istringstream iss(line);
//
//            std::string delimiter=";";
//            std::string token = line.substr(0, line.find(delimiter));
//            parts[i] = token;
//            i=i+1;
//
//        }
//        Creature newCreature(parts[0],std::stoi(parts[1]),std::stoi(parts[2]),std::stoi(parts[3]),std::stoi(parts[4]),std::stoi(parts[5]),std::stoi(parts[6])
//                ,std::stoi(parts[7]),std::stoi(parts[8]),std::stoi(parts[9]));
//        std::cout<<newCreature.name<<newCreature.strength;

    }else {

        std::vector<Creature> playerTeam;
        Trainer player(0, playerTeam);
        player.choosingTeam(playerTeam, chooseList);
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
        std::vector<Creature> enemyPlayerTeam4;
        for (int i = 0; i < 4; ++i) {
            enemyCreatureSelect = (std::rand() % chooseList.size());
            enemyPlayerTeam4.push_back(chooseList.at(enemyCreatureSelect));
            chooseList.erase(chooseList.begin() + enemyCreatureSelect);
        }
        Trainer enemy4(4, enemyPlayerTeam4);

        player.fight(enemy1);
        player.resetHp();
        player.saveToFile(player, enemy1, enemy2, enemy3, enemy4);
        enemy2.diffScaling(1.5);
        player.fight(enemy2);
        player.resetHp();
        player.saveToFile(player, enemy1, enemy2, enemy3, enemy4);
        enemy3.diffScaling(2);
        player.fight(enemy3);
        player.resetHp();
        player.saveToFile(player, enemy1, enemy2, enemy3, enemy4);
        enemy4.diffScaling(2.5);
        player.fight(enemy4);
    }
    return 0;
}