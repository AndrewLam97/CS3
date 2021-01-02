#ifndef CtrlPanel_H
#define CtrlPanel_H
#include "WorldObject.h"
#include "Game.h"
#include "Animation.h"

class CtrlPanel : public WorldObject
{
public:
    CtrlPanel(Game& g);
    void handleCollision(WorldObject &b){};
    void draw(sf::RenderTarget &target);
    void step(float dt);
    void reset(){};
    void receiveMessage(const Message& msg);
private:
    void initSettingAngle(Player *pl);
    void postSettingAngle();
    void changePower(int delta,Player *pl);
    Game& _game;
    int fpsi;
    size_t p;
    bool settingPower;
    bool settingAngle;    //change angle of the turret by deltaX
    int prevMouseX;       //deltaX = mouse.x - prevMouseX
    sf::Vector2i mouseOldCoord;// reset mouse to original pos
    sf::Clock fpsTimer;
    sf::Text fps;
    sf::Text player;
    sf::Text rotation;
    sf::Text power;
    sf::Text fire;
    sf::RectangleShape gaugeBg;
    sf::RectangleShape gaugeFill;
    sf::Sprite crosshair;
    std::unique_ptr<Animation> currPlayerMarker;
};

#endif // CtrlPanel_H
