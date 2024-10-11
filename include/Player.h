//
// Created by Adnan on 10/9/2024.
//

#ifndef PLAYER_H
#define PLAYER_H
#include "SFML/Graphics.hpp"
#include <string>
#include <unordered_map>
#include "CollisionBox.h"
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
    //frame height: height in px of each frame
    //frame width: width in px of each frame
    //run, jump, wait: vector that contains row of animation [0] and number of frames in that animation [1]
    Player(const string &filename, Vector2f pos, Vector2f scale, float animationSpeed, int frameHeight, int frameWidth, vector<int> run = {}, vector<int> jump = {}, vector<int> idle = {});
    void draw(RenderWindow &window, float deltaTime);
    CollisionBox& getCollisionBox();
    void setJumpVelocity(float jumpVelocity);
    void setGravity(float gravity);
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
    Vector2f scale;
    //physics
    Vector2f pos;
    bool isJumping = false;
    float jumpVelocity = -600.0f;
    float gravity = 980.0f;
    //func
    void drawRunning(RenderWindow& window, float deltaTime, int row, int numFrames);
    void drawJumping(RenderWindow& window, float deltaTime, int row, int numFrames);
    void drawIdle(RenderWindow& window, float deltaTime ,int row, int numFrames);
    bool isAnyKeyPressed();
    //collisionbox
    CollisionBox playerCollisionBox;
};
#endif //PLAYER_H


