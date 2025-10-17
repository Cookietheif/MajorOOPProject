#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <string>
#include <iostream>

class gameEngine {
private:
    std::string currentSeason;

public:
    gameEngine();                        
    ~gameEngine();                       

    std::string getSeason() const;       
    void setSeason(const std::string&);  
    void nextTurn();                     
};

#endif
