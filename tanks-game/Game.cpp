
#include "Application.h"
#include "constants.h"
#include "CtrlPanel.h"
#include <cassert>

Game::Game() :
    AppState(GameState),
    playerActive(0),
    counter(0),
    landSliding(false),
    land(nullptr)
{}
void Game::reset()
{
    newGame();
}
void Game::newGame(int n_players,Land::Landtype land_t)
{
    world.clear();
    players.clear();
    playerActive = 0;
    counter = 0;

    land = static_cast<Land*>(world.addObj(WorldObject::LandType));
    auto &gland = Application::getMsgStream().getGroup("Land");
    gland.clear();
    gland.subscribe(land);
    land->genHeightMap(land_t);

    auto &gCtrlPanel = Application::getMsgStream().getGroup("CtrlPanel");
    gCtrlPanel.clear();
    gCtrlPanel.subscribe(world.addObj(new CtrlPanel(*this)));

    auto &gtanks = Application::getMsgStream().getGroup("Tanks");
    gtanks.clear();
    //initialize players
    int pw = constants::windowWidth/n_players; //divide width into p parts
    for(int i = 0;i < n_players; ++i)
    {
        Tank* pTank = static_cast<Tank*>(world.addObj(WorldObject::TankType));
        gtanks.subscribe(pTank);
        Playerptr pl(new Player(pTank,"Player "+ std::to_string(i+1) ));
        int x = rand()%(pw-50) + pw*i + 25; //place tank on both sides
        pTank->setPosition(sf::Vector2f(x,constants::windowHeight-getLandHeight(x)-10));
        pTank->setPlayer(pl.get());
        players.push_back(std::move(pl));
    }
    world.play();
}

void Game::draw(sf::RenderWindow &window)
{
    world.drawAll(window);
}
void Game::update(float dt)
{
    if(isPlayerTurn())
    {   
        if(players.size() == 1) //Game Over
        {
            Application::getMsgStream().sendMessage(Message("GameOver",
                                                            std::string("Last Tank Alive Won")),"AllAppStates");
            Application::changeState(GameOverState);
            reset();
        }
        else if(players.empty())
        {
            Application::getMsgStream().sendMessage(Message("GameOver",
                                                            std::string("Draw Game")),"AllAppStates");
            Application::changeState(GameOverState);
            reset();
        }
    }
    #ifndef STEPPED
    world.stepAll(dt);
    #endif // STEPPED
}
void Game::passEvent(sf::Event Event)
{
    if(Event.type == sf::Event::KeyPressed)
    {
        switch(Event.key.code)
        {
        case sf::Keyboard::A:
            if( isPlayerTurn() && players[playerActive] != nullptr)
                players[playerActive]->moveTank(-1);
            break;
        case sf::Keyboard::D:
            if( isPlayerTurn() && players[playerActive] != nullptr)
                players[playerActive]->moveTank(1);
            break;
#ifdef STEPPED
        case sf::Keyboard::S:
            world.crudeStepAll();
            break;
#endif // STEPPED
        default:
            break;
        }
    }
    Application::getMsgStream().sendMessage(Message("WindowEvent",Event),"CtrlPanel");
}
void Game::receiveMessage(const Message& msg)
{
    if(msg.ID == "SetLandSlide")
    {
        landSliding = true;
    }
    else if(msg.ID == "UnsetLandSlide")
    {
        landSliding = false;
    }
    else if(msg.ID == "PlayerTurnOver")
    {
        if(++playerActive >= players.size())
                playerActive = 0;
    }
    else if(msg.ID == "TankDestroyed")
    {
        size_t pi = 0;
        for(auto p_it = players.begin();p_it != players.end();)
        {
            if((*p_it)->isDead())
            {
                Application::getMsgStream().getGroup("Tanks").unsubscribe(&(*p_it)->getTank());
                p_it = players.erase(p_it);
                if(pi < playerActive) --playerActive;
            }
            else    (++p_it,++pi);
        }
    }
}
