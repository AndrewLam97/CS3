#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    shape.setPosition(0,window.getSize().y / 2 - 100);
    bool direction = true;


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();

        
        if (direction == true) {
            if (shape.getPosition().x >= 1720) {
                direction = false;
            }
            shape.move(1, 0);
        }
        if (direction == false) {
            if (shape.getPosition().x <= 0) {
                direction = true;
            }
            shape.move(-1, 0);
        }
    }

    return 0;
}