#include<iostream>
#include<SFML/Graphics.hpp>
#include"SFMLMenuScreen.h"
using namespace std;
using namespace sf;

SFMLMenuScreen::SFMLMenuScreen() {}
SFMLMenuScreen::SFMLMenuScreen(float w, float h)
{
    if (!(font.loadFromFile("arial.ttf")))
    {
        cout << "Error loadinf file :\n";
    }
    text[0].setFont(font);
    text[0].setFillColor(Color::Blue);
    text[0].setString("1- Enroll a student");
    text[0].setPosition(50, 300);
    text[0].setCharacterSize(50);

    text[1].setFont(font);
    text[1].setFillColor(Color::Black);
    text[1].setString("2- Course Registration");
    text[1].setPosition(50, 400);
    text[1].setCharacterSize(50);


    text[2].setFont(font);
    text[2].setFillColor(Color::Black);
    text[2].setString("3 - Attendence ");
    text[2].setPosition(50, 500);
    text[2].setCharacterSize(50);

    text[3].setFont(font);
    text[3].setFillColor(Color::Black);
    text[3].setString("4 - Marks");
    text[3].setPosition(50, 600);
    text[3].setCharacterSize(50);

    text[4].setFont(font);
    text[4].setFillColor(Color::Black);
    text[4].setString("5 - Course Withdraw");
    text[4].setPosition(50, 700);
    text[4].setCharacterSize(50);

    text[5].setFont(font);
    text[5].setFillColor(Color::Black);
    text[5].setString("6 - Exit ");
    text[5].setPosition(50, 800);
    text[5].setCharacterSize(50);

    selectindex = 0;
}
void SFMLMenuScreen::draw(RenderWindow& window)
{
    for (int i = 0; i < 6; i++)
    {
        window.draw(text[i]);
    }
}
int SFMLMenuScreen::mainmenupress()
{
    return selectindex;
}
void SFMLMenuScreen::moveUp()
{
    if (selectindex - 1 >= 0)
    {
        text[selectindex].setFillColor(Color::Black);
        selectindex--;
        text[selectindex].setFillColor(Color::Blue);
    }
}
void SFMLMenuScreen::moveDown()
{
    if (selectindex + 1 < 6)
    {
        text[selectindex].setFillColor(Color::Black);
        selectindex++;
        text[selectindex].setFillColor(Color::Blue);
    }
}
