#include "Player.h"
#include "Types.h"

#include <string>

using std::string;




Player::Player(const string name, const string job, const string personality) : 
        name(name), level(STARTING_LEVEL), force(STARTING_FORCE), HP(MAX_HP), coins(STARTING_COINS),
        m_personality(NULL), m_job(NULL){
    setPersonality(personality);
    setJob(job);
}

Player::~Player(){
    delete m_job;
    delete m_personality;
}

Player::Player(const Player& player) : 
        name(player.getName()), level(player.getLevel()), force(player.getForce()), HP(player.getHealthPoints()),
        coins(player.getCoins()), m_personality(NULL), m_job(NULL){
    setPersonality(player.m_personality->getPersonality());
    setJob(player.m_job->getJob());
}

void Player::setPersonality(const string personality){
    Personality *new_personality;
    if (personality == RESPONSIBLE){
        new_personality = new Responsible();
    } else if (personality == RISKTAKING){
        new_personality = new RiskTaking();
    }
    delete this->m_personality;
    m_personality = new_personality;
}


void Player::setJob(const string job){
    Job *new_job;
    if (job == WARRIOR){
        new_job = new Warrior();
    } else if (job == SORCERER){
        new_job = new Sorcerer();
    }
    delete this->m_job;
    m_job = new_job;
}


string Player::getDescription() const{
    return this->getName() + ", " + this->m_job->getJob() + " with " + this->m_personality->getPersonality()
        + " behavior (level " + std::to_string(this->getLevel()) + ", " + "force "
        + std::to_string(this->getForce()) + ")";
    
}


string Player::getName() const{
    return name;
}

int Player::getLevel() const{
    return level;
}

int Player::getForce() const{
    return force;
}

int Player::getHealthPoints() const{
    return HP;
}

int Player::getCoins() const{
    return coins;
}



void Player::setForce(const int force){
    this->force = force;
}

bool Player::HPIsFull() const{
    return HP == MAX_HP;
}

void Player::levelUp(){
    if (level < MAX_LEVEL){
        level++;
    }
}

void Player::payCoins(const int price){
    if (price > this->coins) return;
    this->coins -= price;
}

void Player::buff(int force){
    if (force < 0){
        return;
    }
    this->force += force;
}

void Player::damage(const int damage){
    if (damage < 0){
        return;
    }
    this->HP -= damage;
    if (this->HP < 0){
        this->HP = 0;
    } 
}


bool Player::isKnockedOut() const{
    return (this->HP == 0);
}

void Player::heal(int addedHP){
    if(addedHP > 0){
        this->HP += addedHP;
        if (this->HP > this->MAX_HP){
            this->HP = this->MAX_HP;
        }
    }
}



