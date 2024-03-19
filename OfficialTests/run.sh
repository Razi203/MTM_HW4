

g++ --std=c++11 -o mtmchkin -Wall -pedantic-errors -Werror -DNDEBUG *.cpp Cards/*.cpp Players/*.cpp -I. -I./Players -I./Cards

rm -f out.txt

valgrind --leak-check=full ./mtmchkin "OfficialTests/extra_example/deck.txt" "OfficialTests/extra_example/players.txt" > out.txt

diff out.txt "OfficialTests/extra_example/output.txt"