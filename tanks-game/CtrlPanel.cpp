#include "CtrlPanel.h"
#include "Application.h"
#include <cmath>

const int fontSize = 15;

CtrlPanel::CtrlPanel(Game& g) :
    WorldObject(PassiveType),
    _game(g),
    fpsi(),
    p(),
    settingPower(false),
    settingAngle(false),
    prevMouseX(),
    mouseOldCoord(),
    fps("",Application::getFont(FreeSans),fontSize),
    player("Player: 1",Application::getFont(FreeSans),fontSize),
    rotation("",Application::getFont(FreeSans),fontSize),
    crosshair(Application::getTexture(TurretTarget)),
    currPlayerMarker(AnimationCreator::create(ArrowDown))
{
    int xpadding = 30,ypadding = 30,lpadding = 5;
    int width = constants::windowWidth/3;
    int height = fontSize;
    //line 1
    player.setPosition  (xpadding + width*0,ypadding);
    player.setColor     (sf::Color::Black);
    crosshair.setOrigin(-60, crosshair.getLocalBounds().height / 2);
}
void CtrlPanel::draw(sf::RenderTarget &target)
{}
void CtrlPanel::step(float dt)
{
    auto pl = _game.getCurrPlayer();
    if(pl == nullptr)
        return;
    if(settingAngle || settingPower)
    {
        sf::Vector2i mouse = sf::Mouse::getPosition(Application::getWindow());
        int delta = mouse.x-prevMouseX;
        if(settingAngle)
            pl->rotateTurret( delta/2 );
        else
            changePower( delta/2,pl );
        prevMouseX = mouse.x;
        int mouse_margin = 20;
        if(mouse.x < mouse_margin) 

        {
            sf::Mouse::setPosition(sf::Vector2i(constants::windowWidth-mouse_margin-1,mouse.y),Application::getWindow());
            prevMouseX = constants::windowWidth-mouse_margin-1;
        }
        else if(mouse.x > constants::windowWidth-mouse_margin-1)
        {
            sf::Mouse::setPosition(sf::Vector2i(mouse_margin,mouse.y),Application::getWindow());
            prevMouseX = mouse_margin;
        }
        if(mouse.y < mouse_margin)
        {
            sf::Mouse::setPosition(sf::Vector2i(mouse.x,constants::windowHeight-mouse_margin-1),Application::getWindow());
        }
        else if(mouse.y > constants::windowHeight-mouse_margin)
        {
            sf::Mouse::setPosition(sf::Vector2i(mouse.x,mouse_margin),Application::getWindow());
        }
    }
    rotation.setString("Rotation : " + std::to_string(360-int(pl->getTurretAngle())));
}
void CtrlPanel::postSettingAngle()
{
    _game.decCounter();
    settingAngle = false;
    sf::Mouse::setPosition(mouseOldCoord,Application::getWindow());//set mouse to original pos
    Application::getWindow().setMouseCursorVisible(true);
    rotation.setStyle(sf::Text::Regular);
}
void CtrlPanel::initSettingAngle(Player *pl)
{
    _game.incCounter();
    settingAngle = true;
    mouseOldCoord = sf::Mouse::getPosition(Application::getWindow());//save current pos
    prevMouseX = mouseOldCoord.x;
    Application::getWindow().setMouseCursorVisible(false);
    rotation.setStyle(sf::Text::Bold);
}
void CtrlPanel::changePower(int delta,Player *pl)
{}
void CtrlPanel::receiveMessage(const Message& msg)
{
    if(msg.ID == "WindowEvent")
    {
        const sf::Event& event = msg.getItem<sf::Event>(0);
        auto pl = _game.getCurrPlayer();
        if(pl == nullptr)
            return;
        if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        {
            sf::Vector2f mcoord(event.mouseWheel.x,event.mouseButton.y);

            if(settingAngle)    postSettingAngle();
            else if(_game.isPlayerTurn() && rotation.getGlobalBounds().contains(mcoord)) initSettingAngle(pl);
            else if(_game.isPlayerTurn() && gaugeBg.getGlobalBounds().contains(mcoord))
            {
                _game.incCounter();
                settingPower = true;
                Application::getWindow().setMouseCursorVisible(false);
                prevMouseX = mcoord.x;
                gaugeBg.setOutlineThickness(2);
                gaugeBg.setOutlineColor(sf::Color::Red);
            }
            else if(_game.isPlayerTurn() && fire.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x,event.mouseButton.y)) )
                pl->fire();
        }
        else if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::R)
        {
            if(settingAngle)    postSettingAngle();
            else if(_game.isPlayerTurn())                initSettingAngle(pl);
        }
        else if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space && _game.isPlayerTurn())
            pl->fire();
        else if(_game.isPlayerTurn() && event.type == sf::Event::MouseWheelMoved)
        {
            sf::Vector2f mcoord(event.mouseWheel.x,event.mouseButton.y);
            if(gaugeBg.getGlobalBounds().contains(mcoord))
                changePower(event.mouseWheel.delta,pl);
        }
    }
}
