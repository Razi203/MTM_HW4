#include "./Players/Player.h"
#include "./Players/Types.h"
#include "./Cards/Card.h"

#include <iostream>

using namespace std;



int main(){
    vector<string> names;
    vector<string> jobs;
    vector<string> persona;
    vector<Player> players;

    names.push_back("Hiaz");
    jobs.push_back("Warrior");
    persona.push_back(RESPONSIBLE);

    names.push_back("fozii");
    jobs.push_back(WARRIOR);
    persona.push_back(RISKTAKING);

    names.push_back("pPototao");
    jobs.push_back(SORCERER);
    persona.push_back("Responsible");

    names.push_back("DODO");
    jobs.push_back("Sorcerer");
    persona.push_back("RiskTaking");

    for(int i = 0 ; i < names.size(); i++){
        players.push_back(Player(names.at(i), jobs.at(i), persona.at(i)));
    }
    
    for(int i = 0 ; i < names.size(); i++){
        cout << players.at(i).getDescription() << endl;
    }
    cout << endl << endl;
    
    vector<Card*> cards;
    cards.push_back(new Giant());
    cards.push_back(new Goblin());
    cards.push_back(new Dragon());
    cards.push_back(new Gang());
    cards.at(3)->addMember("Goblin");
    cards.at(3)->addMember("Dragon");
    cards.push_back(new SolarEclipse()); //4
    cards.push_back(new PotionsMerchant()); //5

    for(int i = 0 ; i < cards.size(); i++){
        cout << cards.at(i)->getDescription() << endl;
    }

    cout << endl << endl;

    for(int i = 0 ; i < names.size(); i++){
        cards.at(4)->playCard(players.at(i));
    }
    
    for(int i = 0 ; i < names.size(); i++){
        cout << players.at(i).getDescription() << endl;
    }
    cout << endl << endl;


    for(int i = 0 ; i < names.size(); i++){
        players.at(i).damage(70);
        cards.at(5)->playCard(players.at(i));
    }
    
    for(int i = 0 ; i < names.size(); i++){
        cout << players.at(i).getCoins() << "\t" << players.at(i).getHealthPoints() << endl;
    }
    cout << endl << endl;

    return 0;
}