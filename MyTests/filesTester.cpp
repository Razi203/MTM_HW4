#include <string>
#include <vector>
#include "Player.h"
#include "Card.h"
#include "Files.h"
#include "Types.h"
using namespace std;

int main()
{   
    //unique_ptr<Card> card(new Goblin());
    //cout << card->getDescription();
    string file1 = "players.txt";
    string file2 = "deck.txt";
    vector<Player> players = playerFiles(file1);
    
    for (Player& player : players) {
        cout << "Description: " << player.getDescription() << endl;
    }


    vector<shared_ptr<Card>> cards = cardFiles(file2);
    
    for (int i = 0; i < cards.size(); i++) {
        cout << "Description: " << cards.at(i)->getDescription() << endl;
    }
    


    return 0;
}
