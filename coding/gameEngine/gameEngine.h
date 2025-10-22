//#ifndef GAMEENGINE_H
//#define GAMEENGINE_H



class gameEngine
{
    private:
    //class members
    sf::RenderWindow* window;
    sf::Event gameEvent;

    //Mouse positions
    sf::Vector2i mousePositionWindow;

    //private functions
    void initialiseVariables();
    void initialiseWindow(assets assets, GameState gameState);

    public:

    //con/destructors
        gameEngine();
        virtual ~gameEngine();

    //function
        void updateMousePositions();
        void update(assets assets, GameState gameState);
        void pollEvents();
        void render();
        //accessors
        const bool running() const;


};

//#endif