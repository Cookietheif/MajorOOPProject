If not used program before, run these:
sudo apt update
sudo apt install libsfml-dev
g++ -std=c++17 coding/main.cpp -o main \
    -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

run these to run program:
make clean
make

For adding files for compiling, add to end of Makefile SRC: line, e.g. SRC = coding/main.cpp coding/crops.cpp

CARROT.h/cpp has sprite template for entities