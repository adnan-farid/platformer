//
// Created by Adnan on 10/9/2024.
//

#ifndef PLAYER_H
#define PLAYER_H
#include "SFML/Graphics.hpp"
#include <string>
#include <unordered_map>
using namespace std;
using namespace sf;
class Player {
public:
    //PARAMETERS
    //filename: string with path to character sprite sheet
    //x: x starting position of sprite
    //y: y starting position of sprite
    //scale: scales sprite to be smaller or larger
    //animationSpeed: speed at which the frames change
    //numFrames: number of frames in the row of your sprite sheet
    //frame height: height in px of each frame
    //frame width: width in px of each frame
    Player(const string &filename, int x, int y, Vector2f scale, float animationSpeed, int frameHeight, int frameWidth, vector<int> run = {}, vector<int> jump = {}, vector<int> wait = {});
void draw(RenderWindow &window, float deltaTime);
private:
    Texture playerTexture;
    Sprite playerSprite;
    //anim properties
    float animationSpeed = 0.1f;
    float timeSinceLastFrame = 0.0f;
    Clock clock;
    int frameHeight;
    int frameWidth;
    int playerSheetStartY;
    float deltaTime;
    int runRow;
    int runFrames;
    int jumpRow;
    int jumpFrames;
    int waitRow;
    int waitFrames;
    void drawRunning(RenderWindow& window, float deltaTime, int row, int numFrames);
    void drawJumping(RenderWindow& window, float deltaTime, int row, int numFrames);
    void drawWaiting(RenderWindow& window, float deltaTime ,int row, int numFrames);
    bool isAnyKeyPressed();
};
#endif //PLAYER_H


