
#pragma once

#include <string>
using std::string;
class Player;

static const string RESPONSIBLE = "Responsible";
static const string RISKTAKING = "RiskTaking";
static const string WARRIOR = "Warrior";
static const string SORCERER = "Sorcerer";
static const int POTION_PRICE = 5;
static const int POTION_HEALTH = 10;


class Job{
public:
    virtual string getJob() const = 0;
    virtual int solarBuff(Player& player);
    virtual int getCombatPower(Player& player);
};


class Warrior : public Job{
public:
    string getJob() const override;
    int getCombatPower(Player& player) override;
};


class Sorcerer : public Job{
public:
    string getJob() const override;
    int solarBuff(Player& player) override;
};




class Personality{
public:
    virtual string getPersonality() = 0;
    virtual int buyPotions(Player& player);
};


class Responsible : public Personality{
public:
    string getPersonality() override;
    int buyPotions(Player& player) override;
};


class RiskTaking : public Personality{
public:
    static const int HP_THRESHHOLD = 50;
    static const int BOUGHT = 1;
    static const int DID_NOT_BUY = 0;
    string getPersonality() override;
    int buyPotions(Player& player) override;
};


