#pragma once 

#include<iostream>
#include<SFML/Graphics.hpp>
using namespace std;

using namespace sf;
class SFMLMenuScreen
{
private:
    int selectindex;
    Font font;
    Text text[6];  // as we have 5 menus 
public:
    SFMLMenuScreen();
    SFMLMenuScreen(float w, float h);
    void draw(RenderWindow& window);
    int mainmenupress();
    void moveUp();
    void moveDown();
};
