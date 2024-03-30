# MTM_HW4
The Final MTMCHKIN

# Progress
- Player class: Done!
- Card class: Done!
- Input handling: Done!
- Output handling: Done!
- Game manager (Mtmchkin class): Done!


# Files
Given files that not to be touched:
- [main.cpp](main.cpp)
- [utilities.h](utilities.h)
- [utilities.cpp](utilities.cpp)

Our Files:
- [Card header](Cards/Card.h)
- [Card source](Cards/Card.cpp)
- [Player header](Players/Player.h)
- [Player source](Players/Player.cpp)
- [Types source](Players/Types.h)
- [Types source](Players/Types.cpp)
- [Files header](Files.h)
- [Files source](Files.cpp)
- [Mtmchkin header](Mtmchkin.h)
- [Mtmchkin source](Mtmchkin.cpp)
- [dry pdf](dry.pdf)

# Tests
For the official Tests, use [run.sh](OfficialTests/run.sh) in the *OfficialTests* folder.  
use: *./OfficialTests/run.sh*

For the unit & custom Tests, use [run.sh](MyTests/run.sh) in the *MyTests* folder   
use: *./MyTests/run.sh*

compile using:  
        g++ --std=c++11 -o mtmchkin -Wall -pedantic-errors -Werror -DNDEBUG *.cpp Cards/*.cpp Players/*.cpp -I. -I Players -I./Cards

valgrind:   
valgrind --leak-check=full ./mtmchkin deck.txt players.txt

Final Check:    
~mtm/public/2324a/ex4/finalcheck <submission>.zip

Zipped using:   
zip hw4 Mtmchkin.cpp Mtmchkin.h Files.h Files.cpp dry.pdf Players/* Cards/*

student tests:
[link to github](https://github.com/DanielWongi/234124-ex4-mtmchkin-test2024A?tab=readme-ov-file)