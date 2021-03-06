#include <SFML/Graphics.hpp>
#include <vector>
#include "TextureManager.h"
#include "Display.h"
#include <iostream>
#include "VisualElements.h"
#include "Accidents.h"
#include "MaxHeap.h"
#include "MinHeap.h" //may change to max heap
#include "redblacktree.h"
#include "node.h"
#include "ReadFile.h"


int main()
{
    //Read in the data:

    RedBlackTree rbtree;
    MaxHeap<Accident> maxheap;
    std::vector<Accident> accidents;

    ReadFile("US_Accidents_100000.csv", accidents);
    cout << "Done reading file." << std::endl;
    cout << accidents.size() << endl;
    for (auto accident : accidents) { //add all the accidents to the two data structures
        Node newNode(accident.severity, accident.city, accident.state, accident.startYear);
        Node* node = &newNode;
        rbtree.InsertNode(node);
        maxheap.insert(accident);

    }
    cout << rbtree.treesize << endl;



    //INITIALIZE IMPORTANT OBJECTS NECESSARY TO PRINT THINGS TO SCREEN
    sf::RenderWindow window(sf::VideoMode(1900, 1000), "SFML works!");
    std::map<string, Button> buttons;
    createButtons(buttons);

    std::vector<sf::Texture*> vect;
    sf::Texture search = TextureManager::GetTexture("search");
    sf::Texture results = TextureManager::GetTexture("results");

    sf::Texture fair = TextureManager::GetTexture("fair");
    sf::Texture cloudy = TextureManager::GetTexture("cloudy");
    sf::Texture rain = TextureManager::GetTexture("rain");
    sf::Texture snow = TextureManager::GetTexture("snow");
    sf::Texture fair_np = TextureManager::GetTexture("fair_notpressed");
    sf::Texture cloudy_np = TextureManager::GetTexture("cloudy_notpressed");
    sf::Texture snow_np = TextureManager::GetTexture("snow_notpressed");
    sf::Texture rain_np = TextureManager::GetTexture("rain_notpressed");

    std::map<string, sf::ConvexShape> states;
    loadStates(states);


    vect.push_back(&fair);
    vect.push_back(&cloudy);
    vect.push_back(&rain);
    vect.push_back(&snow);
    vect.push_back(&fair_np);
    vect.push_back(&cloudy_np);
    vect.push_back(&rain_np);
    vect.push_back(&snow_np);


    sf::String cityText = "";
    sf::String stateText = "";

    sf::Text city;
    sf::Text state;

    city.setString("");
    state.setString("");

    sf::Font font;
    font.loadFromFile("Font/Montserrat-Medium.ttf");

    city.setFont(font);
    city.setCharacterSize(25);

    state.setFont(font);
    state.setCharacterSize(25);


    //WHILE WINDOW IS OPEN
    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            //IF WINDOW IS CLOSED
            if (event.type == sf::Event::Closed) {
                window.close();
                TextureManager::Clear();
            }

            //If left click is detected, get coordinates and see if a button was pressed
            else if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                auto coordinates = sf::Mouse::getPosition(window);
                findButtonPressed(coordinates, buttons);

            }

            //if text is entered, check if a text box was pressed; If it was, "echo" the character back to screen
            else if (event.type == sf::Event::TextEntered) {
                if (buttons["City"].isPressed) {

                    if (event.text.unicode == '\b') { //backspace -> remove a character from end
                        if (cityText.getSize() != 0) {
                            cityText.erase(cityText.getSize() - 1);
                        }
                    }
                    else {
                        cityText = cityText + event.text.unicode;
                    }
                }
                else if (buttons["State"].isPressed) {
                    if (event.text.unicode == '\b') {
                        if (stateText.getSize() != 0) {
                            stateText.erase(stateText.getSize() - 1);
                        }
                    }
                    else {
                        stateText = stateText + event.text.unicode;
                    }
                }

                //update the string
                city.setPosition(sf::Vector2f(40, 530));
                city.setString(cityText);

                state.setPosition(sf::Vector2f(40, 605));
                state.setString(stateText);

                window.draw(city);
                window.draw(state);

            }

        }

        //display new board
        window.clear();
        displayNewBoard(window, buttons, &search, &results, vect, states, city, state);
    }

    return 0;
}

