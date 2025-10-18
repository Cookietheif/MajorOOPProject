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

    //game objects!!!!!!!!!!
    sf::Sprite createSprites();

    //private functions
    void initialiseVariables();
    void initialiseWindow();

    public:

    //con/destructors
        gameEngine();
        virtual ~gameEngine();

    //function
        void updateMousePositions();
        void update();
        void pollEvents();
        void render();
        void draw();
        void setBaseScreen();
        //accessors
        const bool running() const;


};

//#endif