#ifndef MENU_H
#define MENU_H
#include <SFML/Graphics.hpp>
#include <list>
#include <memory>

typedef std::unique_ptr<sf::Text> sfTextPtr;

class Menu
{
public:
    Menu(const sf::Font &f,int charSize = 20,int linePad = -1,int scrollBarWidth = 6);
    ~Menu() = default;
    void draw(sf::RenderTarget &target);
    template<typename... Tail>
    inline void add(const std::string& str,Tail... T)
    {
        add(str);
        add(T...);
    }
    template<typename... Tail>
    inline void add(const sf::Color& color,const std::string& str,Tail... T)
    {
        add(str,color);
        add(color,T...);
    }
    void add(const sf::Color& color){}
    void add(const std::string& item,sf::Color textColor = sf::Color::Black);
    void step(float dt);
    
    void create(float width = 0,float height = 0);
    void passEvent(const sf::Event& event);
    void clear();
    inline int querySelecion()
    {
        int temp = clicked;
        clicked=-1;
        return temp;
    }
    inline int getCharacterSize(){ return characterSize; }
    inline int getLinePadding(){ return linePadding; }
    inline void setCharacterSize(int size){ characterSize=size;}
    inline void setLinePadding(int pad){ linePadding=pad;}
    inline void setPosition(float x,float y)
    {
        scrollBar.move(-spr.getPosition());
        spr.setPosition(x,y);
        scrollBar.move(spr.getPosition());
    }
    inline void setSelectionBgColor(const sf::Color& theColor){ selectionBg.setFillColor(theColor); }
    inline const sf::Color& getSelectionBgColor(){ return selectionBg.getFillColor(); }
    inline void setScrollBarColor(const sf::Color& theColor){ scrollBar.setFillColor(theColor); }
    inline const sf::Color& getScrollBarColor(){ return scrollBar.getFillColor(); }
    inline sf::Vector2f getPosition(){ return spr.getPosition();}
    inline int getLineSpacing(){ return linePadding+characterSize; }
    inline void setActive(bool val){ active = val; }
    inline bool getActive(){ return active; }
    inline const sf::Vector2f& getSize(){ return view.getSize(); }
    inline void setBackgroundColor(const sf::Color& theColor){ bgColor=theColor; }
private:
    void updateTexture(int deltaScroll = 0);
    sf::RenderTexture rndrTxtre;
    sf::Sprite spr;
    sf::RectangleShape selectionBg;
    sf::RectangleShape scrollBar;
    sf::View view;
    const sf::Font &font;
    std::list<sfTextPtr> menuList;
    bool active;
    int characterSize;
    int linePadding;
    int marker;
    int itemsVisible; 
    int scrolled;
    bool scroll;
    int clicked;
    sf::Color bgColor;
};

#endif // MENU_H
