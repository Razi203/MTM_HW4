
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
    virtual void solarBuff(Player& player);
};


class Warrior : public Job{
public:
    string getJob() const override;
};


class Sorcerer : public Job{
public:
    string getJob() const override;
    virtual void solarBuff(Player& player) override;
};




class Personality{
public:
    virtual string getPersonality() = 0;
    virtual void buyPotions(Player& player);
};


class Responsible : public Personality{
public:
    string getPersonality() override;
    void buyPotions(Player& player) override;
};


class RiskTaking : public Personality{
public:
    static const int HP_THRESHHOLD = 50;
    string getPersonality() override;
    void buyPotions(Player& player) override;
};


