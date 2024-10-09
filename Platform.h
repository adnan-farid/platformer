//
// Created by Adnan on 10/9/2024.
//

#ifndef PLATFORM_H
#define PLATFORM_H
#include <Vector>
#include <string>
#include <SFML/Graphics.hpp>
#include "Tile.h"
using namespace std;
using namespace sf;
class Platform {
public:
    //PARAMETERS
    //scale = tile size
    //pos = initial tile pos, expanding to the left
    //platformType = type of platform (grass or stone)
    //tileCt = amount of tiles in platform
    Platform(int tileCt, const string& platformType, Vector2f pos, RenderWindow& window, Vector2f scale);
    void draw(RenderWindow& window);
private:
    vector<Tile> tiles;
};



#endif //PLATFORM_H
