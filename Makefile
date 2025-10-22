CXX = g++
CXXFLAGS = -std=c++17 -Wall -I./coding -I./coding/Entities -I./coding/Events -I./coding/gameEngine -I./coding/gameEngine/gameObjects -I./coding/gameEngine/gameObjects/gameState -I./coding/gameEngine/gameObjects/assets
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

SRC = $(shell find coding -name "*.cpp")
OBJ = $(SRC:.cpp=.o)

TARGET = main

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(TARGET) $(LDFLAGS)

clean:
	rm -f $(OBJ) $(TARGET)