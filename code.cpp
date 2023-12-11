#include<iostream>
#include<fstream>
#include<regex>
#include<SFML/Graphics.hpp>
#include"SFMLMenuScreen.h"
#include"student.h"
#include"Course.h"
#include"filehandling.h"
#include"validation_header.h"
#include"System.h"
using namespace std;
using namespace sf;

bool Authentication(string Student_ID)
{
    ifstream inputFile("authentification.txt");


    if (!inputFile.is_open())
    {
        cout << "Error opening student data file." << endl;
        return false;
    }

    regex patternRegex(Student_ID);
    string line;
    bool check = false;

    while (getline(inputFile, line))
    {
        if (regex_match(line, patternRegex))
        {
            check = true;
            break;  // No need to continue searching if found
        }
    }
    return check;
}
int main()
{
    VideoMode desktopMode = VideoMode::getDesktopMode();
    bool checking_student = false;
    RenderWindow window(desktopMode, "FLEX managment System");
    Font font;
    font.loadFromFile("arial.ttf");
    if (!font.loadFromFile("arial.ttf"))
    {
        cout << "Error loading file \n";
    }
    // text display 
    Text text;
    text.setFont(font);
    text.setString("For Authentification Enter Your ROll Number");
    text.setCharacterSize(48);
    text.setFillColor(Color::Black);
    text.setPosition(200 * 4 - 100, 100 * 2);


    Text Esc;
    Esc.setFont(font);
    Esc.setString("Press ESC to Exit......");
    Esc.setCharacterSize(48);
    Esc.setFillColor(Color::Red);
    Esc.setPosition(200 * 7, 100 * 9);


    RectangleShape rectangle;
    rectangle.setSize(Vector2f(650, 150));
    rectangle.setPosition(200 * 4 - 40, 100 * 3);
    rectangle.setFillColor(Color::Transparent);
    rectangle.setOutlineColor(Color::Black);
    rectangle.setOutlineThickness(4.0f);
    string ID;


    Text userInputText;
    userInputText.setFont(font);
    userInputText.setCharacterSize(50);
    userInputText.setFillColor(Color::Black);
    userInputText.setPosition(200 * 4.5 - 100, 100 * 3.5);
    Text text_show;
    Text text_show2;

    bool shouldContinue = true;

    Texture texture;
    if (!texture.loadFromFile("C:/Users/echo/Desktop/NU-logo.jpg"));
    {
        cout << "Image not found\n";
    }
    Sprite sprite;
    sprite.setTexture(texture);
    Vector2f newSize(1000 * 1.9 + 30, 100 * 2);
    while (window.isOpen())
    {
        Event aevent;
        while (window.pollEvent(aevent))
        {
            if (aevent.type == Event::TextEntered)
            {
                if (aevent.type == Event::Closed)
                {
                    window.close();
                }
                if (aevent.key.code == Keyboard::Escape)
                {
                    window.close();
                }
                if (aevent.text.unicode < 128 && aevent.text.unicode > 31)
                {
                    ID += aevent.text.unicode;
                    userInputText.setString(ID + "|");

                }
                else if (aevent.text.unicode == 8 && !ID.empty()) // backspace
                {
                    ID.pop_back();
                    userInputText.setString(ID + "|");
                }

            }
        }
        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }
        if (aevent.key.code == Keyboard::Enter)
        {

            checking_student = Authentication(ID);
            if (checking_student)
            {
                window.clear();
                System obj;
                obj.load_student_with_their_courses();
                obj.load_all_ava_courses();
                obj.performMainMenuAction2();
            }
            else
            {
                window.clear();
                text_show2.setFont(font);
                text_show2.setString("You are not a student of FAST - Try Again..");
                text_show2.setCharacterSize(50);
                text_show2.setFillColor(Color::Black);
                text_show2.setPosition(200 * 4 - 100, 100 * 5);
            }
        }
        window.clear(Color::White);
        window.draw(sprite);
        sprite.setScale(newSize.x / sprite.getLocalBounds().width, newSize.y / sprite.getLocalBounds().height);
        window.draw(Esc);
        window.draw(text);
        window.draw(userInputText);
        window.draw(rectangle);
        window.draw(text_show2);
        window.display();
    }
    return 0;
}
