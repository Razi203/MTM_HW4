

g++ --std=c++11 -o mtmchkin -Wall -pedantic-errors -Werror -DNDEBUG *.cpp Cards/*.cpp Players/*.cpp -I. -I./Players -I./Cards

rm -f out.txt

valgrind --leak-check=full ./mtmchkin "OfficialTests/invalid_players/deck.txt" "OfficialTests/invalid_players/players.txt" > out.txt

diff out.txt "OfficialTests/invalid_players/output.txt"