#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <memory>
#include <cctype>

#include "Player.h"
#include "Card.h"
#include "Files.h"

using namespace std;

static const int MAX_NUMBER_OF_PLAYER = 6;
static const int MIN_NUMBER_OF_PLAYER = 2;
static const int MIN_NUMBER_OF_CARDS = 2;
static const int SHORTEST_NAME = 3;
static const int LONGEST_NAME = 15;
static const int MIN_NUMBER_OF_MONSTERS = 2;

void GangAdder(shared_ptr<Card> gang, stringstream& ss);
bool validName(string name);


vector<Player> playerFiles(const string sourceFileName){
    vector<Player> players;
    ifstream source(sourceFileName);
    if (!source) {
        throw PlayerErrors();
    }
    
    string line;
    try {
        while (getline(source, line)) {
            stringstream ss(line);

            string playerName;
            ss >> playerName;
            if(!validName(playerName)){
                throw PlayerErrors();
            }

            string playerJob;
            ss >> playerJob;
            if((playerJob != "Sorcerer") && (playerJob != "Warrior")){
                throw PlayerErrors();
            }

            string playerBehavior;
            ss >> playerBehavior;
            if((playerBehavior != "Responsible") && (playerBehavior != "RiskTaking")){
                throw PlayerErrors();
            }

            Player player(playerName, playerJob, playerBehavior);
            players.push_back(player);

            if (ss >> playerName) throw PlayerErrors();
        }

        if(players.size() > MAX_NUMBER_OF_PLAYER || players.size() < MIN_NUMBER_OF_PLAYER){
            throw PlayerErrors();
        }
    }
    catch (...) {
        throw PlayerErrors();
    }
    return players;
}



vector<shared_ptr<Card>> cardFiles(const string sourceFileName){
    vector<shared_ptr<Card>> Cards;

    ifstream source(sourceFileName);
    if (!source) {
        throw CardErrors();
    }
    string line;

    while (getline(source, line)) {
        stringstream ss(line);
        string cardName;
        ss >> cardName;

        if(cardName == GOBLIN){
            Cards.push_back(shared_ptr<Goblin>(new Goblin()));
        } 
        else if(cardName == DRAGON)
        {
            Cards.push_back(shared_ptr<Dragon>(new Dragon()));
        }
        else if(cardName == GIANT)
        {
            Cards.push_back(shared_ptr<Giant>(new Giant()));
        }
        else if (cardName == GANG)
        {
            shared_ptr<Gang> new_member = shared_ptr<Gang>(new Gang());
            Cards.push_back(new_member);
            GangAdder(new_member, ss);
        }
        else if (cardName == SOLARECLIPSE)
        {
            Cards.push_back(shared_ptr<SolarEclipse>(new SolarEclipse()));
        }
        else if (cardName == POTIONSMERCHANT)
        {
            Cards.push_back(shared_ptr<PotionsMerchant>(new PotionsMerchant()));
        }
        else{
            throw CardErrors();
        }
        
        if (ss >> cardName) throw CardErrors();
    }

    if(Cards.size() < MIN_NUMBER_OF_CARDS){
        throw CardErrors();
    }
    
    return Cards;
}



void GangAdder(shared_ptr<Card> gang, stringstream& ss){  
    string size;
    int gangSize;
    string cardName;

    
    ss >> size;
    try {
        gangSize = stoi(size);
    } 
    catch (...) {
        throw CardErrors();
    }

    if(gangSize < MIN_NUMBER_OF_MONSTERS){
        throw CardErrors();
    }

    for(int i = 0; i < gangSize; i++){
        try{
            ss >> cardName;
        }
        catch (...){
            throw CardErrors();
        }

        if((cardName != GOBLIN) && (cardName != DRAGON) && (cardName != GANG) && (cardName != GIANT)){
            throw CardErrors();
        }

        shared_ptr<Card> new_member = gang->addMember(cardName);
        if (cardName == GANG){
            GangAdder(new_member, ss);
        } 
    }
}


bool validName(string name){
    if (name.size() < SHORTEST_NAME || name.size() > LONGEST_NAME){
        return false;
    }
    for (char ch : name) {
        if (!isalpha(ch)) {
            return false;
        }
    }
    return true;
}