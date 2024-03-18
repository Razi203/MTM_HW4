

g++ --std=c++11 -o mtmchkin -Wall -pedantic-errors -Werror -DNDEBUG *.cpp Cards/*.cpp Players/*.cpp -I. -I./Players -I./Cards

rm -f out.txt

valgrind --leak-check=full ./mtmchkin "Official Tests/extra_example/deck.txt" "Official Tests/extra_example/players.txt" > out.txt

diff out.txt "Official Tests/extra_example/output.txt"