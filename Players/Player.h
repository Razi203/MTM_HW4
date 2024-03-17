
#pragma once

#include <string>

using std::string;

class Player {
public:
    /**
     * Gets the description of the player
     * 
     * @return - description of the player
    */
    string getDescription() const;

    /**
     * Gets the name of the player
     * 
     * @return - name of the player
    */
    string getName() const;

    /**
     * Gets the current level of the player
     * 
     * @return - level of the player
    */
    int getLevel() const;

    /**
     * Gets the of force the player has
     * 
     * @return - force points of the player
    */
    int getForce() const;

    /**
     * Gets the amount of health points the player currently has
     * 
     * @return - health points of the player
    */
    int getHealthPoints() const;

    /**
     * Gets the amount of coins the player has
     * 
     * @return - coins of the player
    */
    int getCoins() const;



private:
    string name;
    int level;
    int force;
    int HP;
    int coins;
    static const int MAX_LEVEL = 10;
    static const int MAX_HP = 100;
    static const int STARTING_FORCE = 5;
    static const int STARTING_COINS = 10;
    static const int STARTING_LEVEL = 1;

};


class Warrior : public Player{
public:
    Warrior(string name);

    
};


class Sorcerer : public Player{
public:
    Sorcerer(string name);
};


class Behavior{
public:
    virtual int makeChoice() = 0; // Place Holder, Need to be changed!


};


class Responsible : public Behavior{
public:
    int makeChoice() override;
};


class RiskTaker : public Behavior{
public:
    int makeChoice() override;
};