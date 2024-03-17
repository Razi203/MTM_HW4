using namespace std;
#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include "./Players/Player.h"
#include "./Cards/Card.h"


class PlayerErrors : public runtime_error {
public:
    PlayerErrors() : runtime_error("Invalid Players File") {}
};

class CardErrors : public runtime_error {
public:
    CardErrors() : runtime_error("Invalid Card File") {}
};

vector<Player> playerFiles(const string sourceFileName);

vector<unique_ptr<Card>> cardFiles(const string sourceFileName);