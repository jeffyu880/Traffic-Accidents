#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <string>


//CITATION
//Author: Joshua Fox, Professor for COP3503
//TextureManager.h and TextureManager.cpp provided by Professor Fox in COP3503 to use for Minesweeper Project as a way 
//to more easily deal with textures

using std::unordered_map;
using std::string;

class TextureManager {

	static unordered_map<string, sf::Texture> textures;
	static void LoadTexture(string textureName);
public:
	static sf::Texture& GetTexture(string textureName);
	static void Clear();

};