//
// Created by Adnan on 10/9/2024.
//

#ifndef TILE_H
#define TILE_H
#include <string>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
class Tile {
public:
    Tile(const string& tileType, Vector2f pos, const RenderWindow& window, Vector2f scale = Vector2f(1.0f, 1.0f));
    void draw(RenderWindow& window);
private:
    static Texture tileTexture;
    Sprite tileSprite;
};



#endif //TILE_H
