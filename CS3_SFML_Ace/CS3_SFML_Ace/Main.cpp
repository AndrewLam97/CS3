#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 700), "Ace of Hearts");
    sf::RectangleShape card(sf::Vector2f(500,700));
    card.setFillColor(sf::Color::White);

    sf::Sprite suit;
    sf::Sprite rank;
    sf::Sprite rankAlt;
    sf::Texture suitTex;
    sf::Texture rankTex;


    string suitStr = "heart.png";
    string rankStr = "A.png";

    if (!suitTex.loadFromFile(suitStr))
    {
        std::cout << "Error loading: " << suitStr << std::endl;
    }

    if (!rankTex.loadFromFile(rankStr))
    {
        std::cout << "Error loading: " << rankStr << std::endl;
    }
    
    suit.setTexture(suitTex, true);
    rank.setTexture(rankTex, true);
    rankAlt.setTexture(rankTex, true);

    suit.setScale(0.1, 0.1);
    rank.setScale(0.3, 0.3);
    rankAlt.setScale(0.3, 0.3);

    suit.setPosition(200, 275);

    rankAlt.setRotation(180);
    rankAlt.setPosition(500, 700);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(card);
        window.draw(suit);
        window.draw(rank);
        window.draw(rankAlt);
        window.display();
    }

    return 0;
}