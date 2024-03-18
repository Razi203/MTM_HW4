#include "Card.h"
#include "utilities.h"
#include "../Players/Player.h"
#include "../Players/Types.h"
#include <memory>
using std::shared_ptr;

string describeEncounter(const Encounter *card){
    string description = card->getName() + " (power " + std::to_string(card->getPower()) + ", loot "
     + std::to_string(card->getLoot()) + ", damage " + std::to_string(card->getDamage()) + ")";
     return description;
}

void Card::addMember(const string name){
    return;
}

string Card::playCard(Player& player) const{
    return "";
}

Encounter::Encounter(string name, int combatPower, int loot, int damage):
        combatPower(combatPower), loot(loot), damage(damage), name(name){};

string Encounter::playCard(Player& player) const{
    if (player.m_job->getCombatPower(player) > combatPower){
         player.levelUp();
         player.earnCoins(loot);
         return getEncounterWonMessage(player, loot);
    } else {
        player.damage(damage);
        return getEncounterLostMessage(player, damage);
    }
}


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



void Gang::addMember(const string name){
    shared_ptr<Encounter> new_member;
    if (name == GOBLIN){
        new_member = shared_ptr<Goblin>(new Goblin());
    } else if (name == GIANT){
        new_member = shared_ptr<Giant>(new Giant());
    } else if (name == DRAGON){
        new_member = shared_ptr<Dragon>(new Dragon());
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

string SolarEclipse::playCard(Player& player) const{
    int effect = player.m_job->solarBuff(player);
    return getSolarEclipseMessage(player, effect);
}


string PotionsMerchant::getDescription() const{
    return POTIONSMERCHANT;
}

string PotionsMerchant::playCard(Player& player) const{
    int amount = player.m_personality->buyPotions(player);
    return getPotionsPurchaseMessage(player, amount);
}





