#include "Player.h"

#include <string>

using std::string;

static const string RESPONSIBLE = "Responsible";
static const string RISKTAKING = "RiskTaking";
static const string WARRIOR = "Warrior";
static const string SORCERER = "Sorcerer";

Player::Player(const string name, const string job, const string personality) : name(name){
    setPersonality(personality);
    setJob(job);
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



void Player::makeChoice(){

}

string Player::getDescription() const{
    return this->getName() + ", " + this->m_job->getJob() + " with " + this->m_personality->getPersonality()
        + "behavior (level " + std::to_string(this->getLevel()) + ", " + "force "
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






string Warrior::getJob(){
    return WARRIOR;
}

string Sorcerer::getJob(){
    return SORCERER;
}




string Responsible::getPersonality(){
    return RESPONSIBLE;
}

int Responsible::makeChoice(){

}

string RiskTaking::getPersonality(){
    return RISKTAKING;
}

int RiskTaking::makeChoice(){

}