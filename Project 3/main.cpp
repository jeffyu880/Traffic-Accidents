/*
#include<SFML/Graphics.hpp>
#include <vector>
#include "TextureManager.h"
#include<unordered_map>
#include "Display.h"
#include <iostream>
#include "VisualElements.h"
#include "Accidents.h"
#include "MaxHeap.h"
#include "MinHeap.h" 
#include "redblacktree.h"
#include "node.h"
#include "ReadFile.h"

template<typename H>
unordered_map<string, H> CreateMap();
void deleteRBTREE(Node* root);
void deleteTree(RedBlackTree& rbtree);


int main()
{
    //Read in the data:
    bool resultSelected = false;
    unordered_map<string, MaxHeap<Accident>> maxStateMap = CreateMap<MaxHeap<Accident>>();
    unordered_map<string, MinHeap<Accident>> minStateMap = CreateMap<MinHeap<Accident>>();
    unordered_map<string, RedBlackTree> treeStateMap = CreateMap<RedBlackTree>();

    MinReadFile("US_Accidents_100000.csv", maxStateMap, minStateMap, treeStateMap);
    cout << "Done reading file." << std::endl;


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
        resultSelected = false;
        sf::Event event;
        while (window.pollEvent(event))
        {
            //IF WINDOW IS CLOSED
            if (event.type == sf::Event::Closed) {
                window.close();
                TextureManager::Clear();
                //  deleteTree(rbtree);
            }

            //If left click is detected, get coordinates and see if a button was pressed
            else if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                auto coordinates = sf::Mouse::getPosition(window);
                bool beforePressed = buttons["searchResults"].isPressed;
                findButtonPressed(coordinates, buttons);
                if ((!beforePressed) && buttons["searchResults"].isPressed) {
                    resultSelected = true;
                }

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
        displayNewBoard(window, buttons, &search, &results, vect, states, city, state, treeStateMap, maxStateMap, resultSelected);
    }

    return 0;
}

template<typename H>
unordered_map<string, H> CreateMap() {
    unordered_map<string, H> StateMap;
    StateMap["AL"];
    StateMap["AK"];
    StateMap["AZ"];
    StateMap["AR"];
    StateMap["CA"];
    StateMap["CO"];
    StateMap["CT"];
    StateMap["DE"];
    StateMap["FL"];
    StateMap["GA"];

    StateMap["HI"];
    StateMap["ID"];
    StateMap["IL"];
    StateMap["IN"];
    StateMap["IA"];
    StateMap["KS"];
    StateMap["KY"];
    StateMap["LA"];
    StateMap["ME"];
    StateMap["MD"];

    StateMap["MA"];
    StateMap["MI"];
    StateMap["MN"];
    StateMap["MS"];
    StateMap["MO"];
    StateMap["MT"];
    StateMap["NE"];
    StateMap["NV"];
    StateMap["NH"];
    StateMap["NJ"];

    StateMap["NM"];
    StateMap["NY"];
    StateMap["NC"];
    StateMap["ND"];
    StateMap["OH"];
    StateMap["OK"];
    StateMap["OR"];
    StateMap["PA"];
    StateMap["RI"];
    StateMap["SC"];

    StateMap["SD"];
    StateMap["TN"];
    StateMap["TX"];
    StateMap["UT"];
    StateMap["VT"];
    StateMap["VA"];
    StateMap["WA"];
    StateMap["WV"];
    StateMap["WI"];
    StateMap["WY"];

    return StateMap;
}

void deleteRBTREE(Node* root) {
    if (root->left != NULL) {
        deleteRBTREE(root->left);
    }
    if (root->right != NULL) {
        deleteRBTREE(root->right);
    }
    delete root;
}

void deleteTree(RedBlackTree& rbtree) {
    //deleteRBTREE(rbtree.mainRoot);
}

*/