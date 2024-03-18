# MTM_HW4
The Final MTMCHKIN
run tests:

g++ -o  playerTest PlayersTest.cpp Players/*.cpp Cards/*.cpp -I. -I./Players -I./Cards

g++ -o FilesTest filesTester.cpp Files.cpp  Players/*.cpp Cards/*.cpp -I. -I./Players -I./Cards

g++ --std=c++11 -o mtmchkin -Wall -pedantic-errors -Werror -DNDEBUG *.cpp Cards/*.cpp Players/*.cpp -I. -I./Players -I./Cards
./mtmchkin deck.txt players.txt >> out.txt
diff out.txt output.txt