#ifndef TITLESCREEN_H
#define TITLESCREEN_H

#include "AppState.h"
#include "Menu.h"

class TitleScreen : public AppState
{
    public:
        TitleScreen();
        ~TitleScreen();
        void reset();
        void draw(sf::RenderWindow &window);
        void update(float dt);
        void passEvent(sf::Event event);
    private:
        sf::Sprite bg;
        sf::Sprite thumb;
        Menu mainMenu;
};

#endif // TITLESCREEN_H
