#pragma once
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>

class PokerCard
{
    int posX = 0;
    int posY = 0;

    const int suitOffsetX = 100;
    const int suitOffsetY = 137;
    const int rankAltOffsetX = 250;
    const int rankAltOffsetY = 350;

    sf::RectangleShape card;
    sf::Sprite suit;
    sf::Sprite rank;
    sf::Sprite rankAlt;
    sf::Texture suitTex;
    sf::Texture rankTex;

    std::string suitStr = "heart.png";
    std::string rankStr = "A.png";

public:
    void draw(sf::RenderWindow & window);
    void setSuit(std::string suitStr);
    void setRank(std::string rankStr);

    void setPosition(int x, int y);
    void addOffset(int offX, int offY);
    
    PokerCard();
};

