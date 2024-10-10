//
// Created by Adnan on 10/9/2024.
//

#include "Player.h"
#include <iostream>

Player::Player(const string &filename, Vector2f pos, Vector2f scale, float animationSpeed, int frameHeight,
    int frameWidth, vector<int> run, vector<int> jump, vector<int> idle) : pos(pos), scale(scale),
    animationSpeed(animationSpeed), frameHeight(frameHeight), frameWidth(frameWidth),
    playerCollisionBox(Vector2f(scale.x*frameWidth, scale.y*frameHeight), pos){
    if (!playerTexture.loadFromFile(filename)) {
        playerTexture.loadFromFile("assets/character/char_blue.png");
    }
    playerSprite.setPosition(pos.x, pos.y);
    playerSprite.setTexture(playerTexture);
    playerSprite.setScale(scale.x, scale.y);
    //anim properties
    if (run.size() > 0) { runRow = run[0]; runFrames = run[1]; }
    if (idle.size() > 0) { waitRow = idle[0]; waitFrames = idle[1]; }
    if (jump.size() > 0) { jumpRow = jump[0]; jumpFrames = jump[1]; }
}
int currFrame = 0;

void Player::draw(RenderWindow &window, float deltaTime) {
    if (!isAnyKeyPressed()) {
        drawIdle(window, deltaTime, waitRow, waitFrames);
    } else if (Keyboard::isKeyPressed(Keyboard::W)) {
        drawJumping(window, deltaTime, jumpRow, jumpFrames);
    } else {
        drawRunning(window, deltaTime, runRow, runFrames);
    }
    playerCollisionBox.debugDraw(window);
}

void Player::drawJumping(RenderWindow &window, float deltaTime, int row, int numFrames) {
    playerSheetStartY = row * frameHeight;
    timeSinceLastFrame += deltaTime;

    if (Keyboard::isKeyPressed(Keyboard::W) && !isJumping) {
        isJumping = true;
    }

    if (isJumping && timeSinceLastFrame >= animationSpeed) {
        currFrame = (currFrame + 1) % numFrames;
        playerSprite.setTextureRect(IntRect(currFrame * frameWidth, playerSheetStartY, frameWidth, frameHeight));
        timeSinceLastFrame = 0.0f;
        playerSprite.move(0, 300 * deltaTime);
    }
    playerCollisionBox.setPosition(Vector2f(playerSprite.getPosition().x, playerSprite.getPosition().y));
    window.draw(playerSprite);
}

void Player::drawRunning(RenderWindow &window, float deltaTime, int row, int numFrames) {
    playerSheetStartY = row * frameHeight;
    timeSinceLastFrame += deltaTime;

    if ((Keyboard::isKeyPressed(Keyboard::A) or Keyboard::isKeyPressed(Keyboard::D)) && timeSinceLastFrame >= animationSpeed) {
        currFrame = (currFrame + 1) % numFrames;
        playerSprite.setTextureRect(IntRect(currFrame * frameWidth, playerSheetStartY, frameWidth, frameHeight));
        timeSinceLastFrame = 0.0f;
    }
    if (Keyboard::isKeyPressed(Keyboard::D)) {
        playerSprite.setOrigin(0, 0);
        playerSprite.setScale({scale.x, scale.y});
        playerSprite.move(300* deltaTime, 0);
    } else if (Keyboard::isKeyPressed(Keyboard::A)) {
        playerSprite.setOrigin(playerSprite.getLocalBounds().width, 0);
        playerSprite.setScale({-scale.x, scale.y});
        playerSprite.move(-300* deltaTime, 0);
    }
    playerCollisionBox.setPosition(Vector2f(playerSprite.getPosition().x, playerSprite.getPosition().y));
    window.draw(playerSprite);
}

void Player::drawIdle(RenderWindow &window, float deltaTime, int row, int numFrames) {
    playerSheetStartY = row * frameHeight;
    timeSinceLastFrame += deltaTime;

    if (!isAnyKeyPressed() && timeSinceLastFrame >= animationSpeed) {
        currFrame = (currFrame + 1) % numFrames;
        playerSprite.setTextureRect(IntRect(currFrame * frameWidth, playerSheetStartY, frameWidth, frameHeight));
        timeSinceLastFrame = 0.0f;
    }
    playerCollisionBox.setPosition(Vector2f(playerSprite.getPosition().x, playerSprite.getPosition().y));
    window.draw(playerSprite);
}

bool Player::isAnyKeyPressed()
{
    if (Keyboard::isKeyPressed(Keyboard::A)) {return true;}
    if (Keyboard::isKeyPressed(Keyboard::D)) {return true;}
    if (Keyboard::isKeyPressed(Keyboard::W)) {return true;}
    return false;
}





