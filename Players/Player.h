
#pragma once

#include <string>
#include <memory>
using std::shared_ptr;
using std::string;

class Job;
class Personality;


class Player {
public:

    Player(const string name, const string job, const string personality);
    Player(const Player& player);

    void setPersonality(const string personality);
    void setJob(const string job);

    void setForce(const int force);
    bool HPIsFull() const;
    void payCoins(const int price);
    void earnCoins(const int coins);
    void levelUp();
    void buff(const int force);
    void heal(const int addedHP);
    void damage(const int damage);
    bool isKnockedOut() const;

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



    shared_ptr<Personality> m_personality;
    shared_ptr<Job> m_job;

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





