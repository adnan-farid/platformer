//
// Created by Adnan on 10/9/2024.
//
#include "Tile.h"
#include "Platform.h"

Platform::Platform(int tileCt, const string &platformType, Vector2f pos, RenderWindow& window, Vector2f scale)
    : platformCollisionBox(Vector2f(tileCt * 24 * scale.x, 24 * scale.y), pos)  {
    Vector2f currPos = pos;
    for (int i = 0; i < tileCt; i++) {
        if (i == 0) {
            Tile currTile(platformType + "_left", currPos, window, scale);
            tiles.push_back(currTile);
        } else if (i == tileCt - 1) {
            Tile currTile(platformType + "_right", currPos, window, scale);
            tiles.push_back(currTile);
        } else {
            Tile currTile(platformType, currPos, window, scale);
            tiles.push_back(currTile);
        }
        currPos.x += 24 * scale.x;
    }
    float platformWidth = tileCt * 24 * scale.x;
    float platformHeight = 24 * scale.y;
    platformCollisionBox = CollisionBox(Vector2f(platformWidth, platformHeight), pos);

}
void Platform::draw(RenderWindow &window) {
    for (auto& tile : tiles) {
        tile.draw(window);
    }
    platformCollisionBox.debugDraw(window);

}

