#include "Types.h"
#include "Player.h"


void Job::solarBuff(Player& player){
    int force = player.getForce() - 1;
    force = (force < 0) ? 0 : force;
    player.setForce(force);
}


void Sorcerer::solarBuff(Player& player){
    player.setForce(player.getForce() + 1);
}

string Warrior::getJob() const{
    return WARRIOR;
}


string Sorcerer::getJob() const{
    return SORCERER;
}



void Personality::buyPotions(Player& player){
    return;
}

void Responsible::buyPotions(Player& player){
    while (!player.HPIsFull() && player.getCoins() >= POTION_PRICE){
        player.heal(POTION_HEALTH);
        player.payCoins(POTION_PRICE);
    }
}

void RiskTaking::buyPotions(Player& player){
    if (player.getHealthPoints() < HP_THRESHHOLD && player.getCoins() >= POTION_PRICE){
        player.heal(POTION_HEALTH);
        player.payCoins(POTION_PRICE);
    }
}







string Responsible::getPersonality(){
    return RESPONSIBLE;
}


string RiskTaking::getPersonality(){
    return RISKTAKING;
}