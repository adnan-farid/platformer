//
// Created by Adnan on 10/9/2024.
//

#include "Tile.h"
#include <map>
#include <iostream>
Texture Tile::tileTexture;

static const map<string, IntRect> tileMap = {
    {"grass_stone_right", IntRect(72, 0, 24, 24)},
    {"grass_stone_left", IntRect(0, 0, 24, 24)},
    {"grass_stone", IntRect(16, 0, 24, 24)},
    {"stone_solid", IntRect(128, 0, 24, 24)},
};
Tile::Tile(const string& tileType, Vector2f pos, const RenderWindow& window, Vector2f scale) {
    string filepath = "../assets/oak_woods_tileset.png";
    if(!tileTexture.loadFromFile(filepath)) {
        cout << "Failed to load tile texture from " << filepath << endl;
        return;
    }
    auto tileRect = tileMap.find(tileType);
    if (tileRect == tileMap.end()) {
        cout << "Tile type " << tileType << " does not exist" << endl;
    }

    tileSprite.setTexture(tileTexture);
    //value of map
    tileSprite.setTextureRect(tileRect->second);
    tileSprite.setPosition(pos);
    tileSprite.setScale(scale);
}
void Tile::draw(RenderWindow &window) {
    window.draw(tileSprite);
}
