#include "Tank.h"
#include "Application.h"
#include "Missile.h"
#include "utilities.h"
#include "WeaponPostEffects.h"

#define HMAP(n)        Application::getGame().getLandHeight(n)
#define R_POINTDIST(n) (cachedSqrt(1 + (HMAP(n) - HMAP((n)+1))*(HMAP(n) - HMAP((n)+1)))+0.5)
#define L_POINTDIST(n) (-cachedSqrt(1+ (HMAP((n)-1) - HMAP(n))*(HMAP((n)-1) - HMAP(n)))-0.5)
#define TANK_WIDTH     tank.getLocalBounds().width
#define TANK_HEIGHT    tank.getLocalBounds().height

const float lvelocity = 150;

Tank::Tank() :
    WorldObject(TankType) ,
    myOwner(nullptr) ,
    moving() ,
    tank(Application::getTexture(TankTexture)) ,
    turret(Application::getTexture(TurretTexture)),
    freefall(true),
    velocity(),
    Name(),
    fadingLife(true),
    fadingTimer(1)
{
    Application::getGame().incCounter();
    tank.setOrigin(tank.getLocalBounds().width / 2, tank.getLocalBounds().height);
    turret.setOrigin(0, turret.getLocalBounds().height / 2);
    turret.setRotation(-45);
    setPosition(sf::Vector2f());
}
Tank::~Tank()
{
    if(freefall)
        Application::getGame().decCounter();
}
sf::RectangleShape Tank::getTankRect()
{
    sf::RectangleShape rs(sf::Vector2f(tank.getLocalBounds().width,tank.getLocalBounds().height));
    rs.setPosition(tank.getPosition().x,tank.getPosition().y-TANK_HEIGHT/2);
    return rs;
}
void Tank::weapAct(float dlife)
{
    int newlife = std::max(0.0f,myOwner->getLife()-dlife);
    assert(newlife<=Player::maxlife);
    myOwner->setLife(newlife);
    if(newlife == 0)
    {
        selfDestruct = true;
        Application::getMsgStream().sendMessage(Message("TankDestroyed"),"GameState");
    }
}
void Tank::setPlayer(Player *p)
{
    myOwner = p;
    Name.setString(p->getName());
    setPosition(tank.getPosition());
}
void Tank::setLifeFill(int l)
{}
void Tank::receiveMessage(const Message& msg)
{}
void Tank::handleCollision(WorldObject &b)
{
    switch(b.type)
    {
    case LandType:
        if(freefall)
        {
            int x0 = tank.getPosition().x , y0 = tank.getPosition().y;
            int h = constants::windowHeight-HMAP(x0);
            if(h <= y0)//collision
            {
                float ang = Application::getGame().getLandNormAng(x0,y0);
                tank.setRotation(std::fmod(90 - TO_DEG(ang),360) );
                freefall = false;
                velocity = sf::Vector2f();
                Application::getGame().decCounter();
                setPosition(x0,h);
                break;
            }
        }
        break;
    case WeaponType:
    case WeaponPostEffectType:
        b.handleCollision(*this);
        break;
    default:
        break;
    }
}

void Tank::draw(sf::RenderTarget &target)
{
    target.draw(turret); //#FIX
    target.draw(tank);
}
void Tank::setMovement(int val) {   moving = val;   }
void Tank::step(float dt)
{
    if(freefall)
    {
        velocity.y += constants::gravity*dt;
        sf::Vector2f ds = velocity*dt;
        tank.move(ds);
        turret.move(ds);
    }
    else
    {
        if(tank.getPosition().y<constants::windowHeight-HMAP(tank.getPosition().x))
        {
            freefall = true;
            Application::getGame().incCounter();
        }
        if(moving)
        {
            float phi = TO_RAD(tank.getRotation());
            //xvel is the horizontal component of the velocity with the angle phi.
            float xvel = std::max(2.0f,lvelocity*std::cos(phi))*((moving<0)?-1:1);
            sf::Vector2f ds(xvel*dt,0);
            ds.y = constants::windowHeight-HMAP(tank.getPosition().x+ds.x)-tank.getPosition().y;
            moving = 0;
            if(ds.y < 0 && std::abs(ds.y/ds.x) > std::tan(TO_RAD(80))) //if ascent slope is too steep
                return;
            tank.move(ds);
            turret.move(ds);
            float ang = Application::getGame().getLandNormAng(tank.getPosition().x,tank.getPosition().y);
            tank.setRotation(std::fmod(90 - TO_DEG(ang),360) );
        }
    }
    sf::Vector2f dist = sf::Vector2f(sf::Mouse::getPosition(Application::getWindow())) - tank.getPosition();
}
void Tank::reset()
{
    moving = 0;
    turret.setRotation(-45);
    if(!freefall)
    {
        freefall = true;
        Application::getGame().incCounter();
    }
}
void Tank::setPosition(const sf::Vector2f& pos)
{
    tank.setPosition(pos);
    turret.setPosition(pos-sf::Vector2f(0,TANK_HEIGHT/2));
}
