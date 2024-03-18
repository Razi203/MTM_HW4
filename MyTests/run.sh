

g++ --std=c++11 -o FilesTest -Wall -pedantic-errors -Werror -DNDEBUG MyTests/filesTester.cpp Files.cpp utilities.cpp Cards/*.cpp Players/*.cpp -I. -I./Players -I./Cards

rm -f out.txt

./FilesTest "MyTests/deck.txt" "MyTests/players.txt" > out.txt