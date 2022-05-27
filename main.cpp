#include <iostream>
#include <vector>
#include "Creature.h"

void clear(){
    std::system( "cls");
}


int main() {
    std::vector<Creature> chooseList;

    Creature kotor("Kotor", 1, 1, 1, 1, 1, 1); // woda
    chooseList.push_back(kotor);
    Creature bellagoth("Bellagoth", 1, 1, 1, 1, 1, 2); // ziemia
    chooseList.push_back(bellagoth);
    Creature dovahkiin("Dovahkiin", 5, 3, 10, 2, 1, 3); // powietrze
    chooseList.push_back(dovahkiin);
    Creature diablo("Diablo", 1, 1, 1, 1, 1, 4); //ogień
    chooseList.push_back(diablo);
    Creature miraak("Miraak", 1, 1, 1, 1, 1, 5); //lód
    chooseList.push_back(miraak);
    Creature glados("GLaDOS", 4, 12, 12, 12, 1, 6); //stal
    chooseList.push_back(glados);
    Creature tandi("Tandi", 1, 1, 1, 1, 1, 1);
    chooseList.push_back(tandi);
    Creature mactavish("Mactavish", 1, 1, 1, 1, 1, 1);
    chooseList.push_back(mactavish);
    Creature snake("Snake", 1, 1, 1, 1, 1, 1);
    chooseList.push_back(snake);
    Creature zinyak("Zinyak", 1, 1, 1, 1, 1, 1);
    chooseList.push_back(zinyak);
    Creature kenshi("Kenshi", 1, 1, 1, 1, 1, 1);
    chooseList.push_back(kenshi);
    Creature clementine("Clementine", 1, 1, 1, 1, 1, 1);
    chooseList.push_back(clementine);
    Creature shepard("Shepard", 1, 1, 1, 1, 1, 1);
    chooseList.push_back(shepard);
    Creature artyom("Artyom", 1, 1, 1, 1, 1, 1);
    chooseList.push_back(artyom);
    Creature strielok("Stierlok", 1, 1, 1, 1, 1, 1);
    chooseList.push_back(strielok);
    Creature ezio("Ezio", 1, 1, 1, 1, 1, 1);
    chooseList.push_back(ezio);
    bool on = true;
    int creaChoose = 0;
    int creaConf=0;
    std::vector<Creature> playerTeam;
    std::cout << "Witaj na arenie. Wybierz stworzenia z ktorych chcesz stworzyc druzyne:" << std::endl;
    while (on) {
        std::cin >> creaChoose;
        std::cout<<"Czy napewno chcesz wybrac dane stworzenie? Wpisz 1 aby powtwierdzic. Wpisz dowolna inna liczbe,zeby anulowac wybor:"<<std::endl;
        std::cout<<chooseList.at(creaChoose).name<<std::endl;
        std::cin >> creaConf;
        if(creaConf==1){
            playerTeam.push_back(chooseList.at(creaChoose));
            chooseList.erase(chooseList.begin()+creaChoose);
            std::cout<<"Stworzenie zostalo dodane" << std::endl;
        }else
            std::cout<<"Anulowano wybór";

        if (playerTeam.size()==6){

            on=false;
        }
    }

    return 0;
}