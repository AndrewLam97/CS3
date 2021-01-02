#include "PokerCard.h"

PokerCard::PokerCard() {


	card.setSize(sf::Vector2f(250, 350));
	card.setFillColor(sf::Color::White);
	

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

	suit.setScale(0.05, 0.05);
	rank.setScale(0.15, 0.15);
	rankAlt.setScale(0.15, 0.15);

	rankAlt.setRotation(180);

	card.setPosition(posX, posY);
	suit.setPosition(posX + suitOffsetX, posY + suitOffsetY);
	rank.setPosition(posX, posY);
	rankAlt.setPosition(posX + rankAltOffsetX, posY + rankAltOffsetY);
}

void PokerCard::setSuit(std::string suitStr) {
	this->suitStr = suitStr;
}

void PokerCard::setRank(std::string rankStr) {
	this->rankStr = rankStr;
}

void PokerCard::draw(sf::RenderWindow & window) {
	
	window.draw(card);
	window.draw(suit);
	window.draw(rank);
	window.draw(rankAlt);
}

void PokerCard::setPosition(int x, int y) {
	posX = x;
	posY = y;

	card.setPosition(posX, posY);
	suit.setPosition(posX + suitOffsetX, posY + suitOffsetY);
	rank.setPosition(posX, posY);
	rankAlt.setPosition(posX + rankAltOffsetX, posY + rankAltOffsetY);
}
void PokerCard::addOffset(int offX, int offY) {
	this->posX += offX;
	this->posY += offY;

	card.setPosition(posX, posY);
	suit.setPosition(posX + suitOffsetX, posY + suitOffsetY);
	rank.setPosition(posX, posY);
	rankAlt.setPosition(posX + rankAltOffsetX, posY + rankAltOffsetY);
}
