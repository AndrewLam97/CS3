#include "GameOverScreen.h"
#include "Application.h"

GameOverScreen::GameOverScreen() :
    AppState(GameOverState),
    bgImg(),
    bgSpr(),
    gameOverText("Game Over!",Application::getFont(FreeSans))
{
    gameOverText.setColor(sf::Color::Black);
    gameOverText.setCharacterSize(40);
    gameOverText.setOrigin(gameOverText.getLocalBounds().width/2,gameOverText.getLocalBounds().height/2);
}
void GameOverScreen::reset()
{
    sf::RenderWindow &win = Application::getWindow();
    bgImg.create(win.getSize().x,win.getSize().y);
    bgImg.update(win);
    bgSpr.setTexture(bgImg);
    gameOverText.setPosition(win.getSize().x/2,2*gameOverText.getCharacterSize());
}
void GameOverScreen::draw(sf::RenderWindow &window)
{
    window.draw(bgSpr);
    window.draw(gameOverText);
}
void GameOverScreen::update(float dt){}
void GameOverScreen::passEvent(sf::Event Event)
{
    if(Event.type == sf::Event::KeyPressed || Event.type == sf::Event::MouseButtonReleased)
        Application::changeState(GameSetupState);
}
void GameOverScreen::receiveMessage(const Message& msg)
{
    if(msg.ID == "GameOver")
    {
        const std::string &gcase = msg.getItem<std::string>(0);
        reset();
    }
}
