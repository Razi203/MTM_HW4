#pragma once

#include "../Players/Player.h"

#include <string>
#include <vector>
using std::string;


static const string GOBLIN = "Goblin";
static const string GIANT = "Giant";
static const string DRAGON = "Dragon";
static const string GANG = "Gang";
static const string SOLARECLIPSE = "SolarEclipse";
static const string POTIONSMERCHANT = "PotionsMerchant";


class Card{
public:
    /**
     * Gets the description of the card
     *
     * @return - the description of the card
    */
    virtual string getDescription() const = 0;
    
    virtual void addMember(const string name);
    virtual void playCard(Player& player) const;

};


class Encounter : public Card{
public:

    virtual string getName() const;
    virtual int getPower() const;
    virtual int getLoot() const;
    virtual int getDamage() const;
    string getDescription() const;
    Encounter(string name, int combatPower, int loot, int damage);

protected:
    int combatPower;
    int loot;
    int damage;
    string name;
};


class Goblin :public Encounter{
public:
    Goblin();

private:
    static const int Goblin_POWER = 5;
    static const int Goblin_LOOT = 12;
    static const int Goblin_DAMAGE = 10;

};

class Giant :public Encounter {
public:
    Giant();

private:
    static const int GIANT_POWER = 12;
    static const int GIANT_LOOT = 5;
    static const int GIANT_DAMAGE = 25;
};

class Dragon :public Encounter {
public:
    Dragon();

private:
    static const int DRAGON_POWER = 17;
    static const int DRAGON_LOOT = 100;
    static const int DRAGON_DAMAGE = 9001;

};

class Gang :public Encounter{
public:
    Gang();
    ~Gang();

    void addMember(const string name) override;
    string getName() const override;

private:
    std::vector<Encounter*> members;
    int size;
    static const int EMPTY = 0;
};






class Event: public Card{
public:
    virtual string getDescription() const = 0;
    virtual void playCard(Player& player) const = 0;

};

class SolarEclipse: public Event{
public:
    string getDescription() const override;
    void playCard(Player& player) const override;
};

class PotionsMerchant: public Event{
public:
    string getDescription() const override;
    void playCard(Player& player) const override;
};