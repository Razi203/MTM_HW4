#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <memory>
#include <cctype>

#include "./Players/Player.h"
#include "./Cards/Card.h"
#include "Files.h"
#include "./Players/Types.h"

using namespace std;


#include <string>
#include <iostream>

#include "Mtmchkin.h"

using namespace std;

static const int REQUIRED_PARAMS_COUNT = 3;
static const int DECK_PATH_INDEX = 1;
static const int PLAYERS_PATH_INDEX = 2;


// int main(){
    
//     Goblin go = Goblin();
//     unique_ptr<Card> pointer = unique_ptr<Goblin>(new Goblin());
//     cout << (*pointer).getDescription() << endl;
//     string sourceFileName = "test.txt";
//     ifstream source(sourceFileName);
//     string line;
//     while (source >> line) {
//         cout << line << "#";
//     }
//     return 0;
// }


int main(int argc, char** argv) {
    if (argc != REQUIRED_PARAMS_COUNT) {
        cout << "Invalid number of arguments" << endl;
        cout << "Usage: mtmchkin <deck_file_path> <players_file_path>" << endl;
    }
    string deckPath = argv[DECK_PATH_INDEX];
    string playersPath = argv[PLAYERS_PATH_INDEX];
    
    vector<Player> players;
    playerFiles(players, playersPath);

    for (Player& player : players) {
        cout << player.getDescription() << endl;
    }
    
    cout << endl << endl;
    vector<unique_ptr<Card>> cards;
    cardFiles(cards, deckPath);
    
    for (long unsigned int i = 0; i < cards.size(); i++) {
        cout << cards.at(i)->getDescription() << endl;
    }
    
    return 0;
}
