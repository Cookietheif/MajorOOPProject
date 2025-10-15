//#ifndef GAMEENGINE_H
//#define GAMEENGINE_H

class gameEngine
{
    private:
    //class members
    sf::RenderWindow* window;
    sf::Event gameEvent;

    //private functions
    void initialiseVariables();
    void initialiseWindow();

    public:

    //con/destructors
        gameEngine();
        virtual ~gameEngine();

    //function
        void update();
        void render();

};

//#endif