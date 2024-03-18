#include <string>
#include <vector>
#include "Player.h"
#include "Card.h"
#include "Files.h"
#include "Types.h"
using namespace std;


#include <string>
#include <iostream>

#include "Mtmchkin.h"

using namespace std;

static const int REQUIRED_PARAMS_COUNT = 3;
static const int DECK_PATH_INDEX = 1;
static const int PLAYERS_PATH_INDEX = 2;

int main(int argc, char** argv) {
    if (argc != REQUIRED_PARAMS_COUNT) {
        cout << "Invalid number of arguments" << endl;
        cout << "Usage: mtmchkin <deck_file_path> <players_file_path>" << endl;
    }
    string deckPath = argv[DECK_PATH_INDEX];
    string playersPath = argv[PLAYERS_PATH_INDEX];
    
    vector<Player> players = playerFiles(playersPath);

    for (Player& player : players) {
        cout << player.getDescription() << endl;
    }

    cout << endl << endl;
    vector<shared_ptr<Card>> cards = cardFiles(deckPath);
    
    for (long unsigned int i = 0; i < cards.size(); i++) {
        cout << cards.at(i)->getDescription() << endl;
    }
    
    return 0;
}
