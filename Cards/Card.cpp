#include "Card.h"
#include "Player.h"
#include "Types.h"


string describeEncounter(const Encounter *card){
    string description = card->getName() + " (power " + std::to_string(card->getPower()) + ", loot "
     + std::to_string(card->getLoot()) + ", damage " + std::to_string(card->getDamage()) + ")";
     return description;
}

void Card::addMember(const string name){
    return;
}

void Card::playCard(Player& player) const{
    return;
}

Encounter::Encounter(string name, int combatPower, int loot, int damage):
        name(name), combatPower(combatPower), loot(loot), damage(damage){};

string Encounter::getName() const{
    return this->name;
}

int Encounter::getDamage() const{
    return this->damage;
}

int Encounter::getLoot() const{
    return this->loot;
}

int Encounter::getPower() const{
    return this->combatPower;
}

string Encounter::getDescription() const{
    return describeEncounter(this);
}

Goblin::Goblin():
        Encounter(GOBLIN, Goblin_POWER, Goblin_LOOT, Goblin_DAMAGE){};


Giant::Giant():
        Encounter(GIANT, GIANT_POWER,GIANT_LOOT,GIANT_DAMAGE){};

Dragon::Dragon():
        Encounter(DRAGON, DRAGON_POWER,DRAGON_LOOT,DRAGON_DAMAGE){};

Gang::Gang():
        Encounter(GANG, EMPTY, EMPTY, EMPTY), size(EMPTY){};

Gang::~Gang(){
    for(const Encounter* ptr : this->members){
        delete ptr;
    }
}

void Gang::addMember(const string name){
    Encounter* new_member;
    if (name == GOBLIN){
        new_member = new Goblin();
    } else if (name == GIANT){
        new_member = new Giant();
    } else if (name == DRAGON){
        new_member = new Dragon();
    }
    this->members.push_back(new_member);
    this->loot += new_member->getLoot();
    this->damage += new_member->getDamage();
    this->combatPower += new_member->getPower();
    this->size++;
}


string Gang::getName() const{
    string name = "Gang of " + std::to_string(this->size) + " members";
    return name;
}



string SolarEclipse::getDescription() const{
    return SOLARECLIPSE;
}

void SolarEclipse::playCard(Player& player) const{
    player.m_job->solarBuff(player);
}


string PotionsMerchant::getDescription() const{
    return POTIONSMERCHANT;
}

void PotionsMerchant::playCard(Player& player) const{
    player.m_personality->buyPotions(player);
}





