#include <SFML/Graphics.hpp>
#include "PokerCard.h"
#include "CardGrid.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Aces Grid");
    
    CardGrid cg(2,4);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);

        cg.drawGrid(window);
        window.display();
    }

    return 0;
}