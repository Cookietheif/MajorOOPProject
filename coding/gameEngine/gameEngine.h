//#ifndef GAMEENGINE_H
//#define GAMEENGINE_H



class gameEngine
{
    private:
    //class members
    sf::RenderWindow* window;
    sf::Event gameEvent;

    //game objects!!!!!!!!!!
    sf::Sprite test;
    sf::Texture testTexture;
    sf::Sprite createSprites();

    //private functions
    void initialiseVariables();
    void initialiseWindow();

    public:

    //con/destructors
        gameEngine();
        virtual ~gameEngine();

    //function
        void update();
        void pollEvents();
        void render();
        void draw();
        //accessors
        const bool running() const;


};

//#endif