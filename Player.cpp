//
// Created by Adnan on 10/9/2024.
//

#include "Player.h"
#include <iostream>

Player::Player(const string &filename, int x, int y, Vector2f scale, float animationSpeed, int numFrames, int frameHeight, int frameWidth)
    : animationSpeed(animationSpeed), frameHeight(frameHeight), frameWidth(frameWidth), numFrames(numFrames) {
    if (!playerTexture.loadFromFile(filename)) {
        playerTexture.loadFromFile("assets/character/char_blue.png");
    }
    playerSprite.setPosition(x, y);
    playerSprite.setTexture(playerTexture);
    playerSprite.setScale(scale.x, scale.y);
}   int currFrame = 0;

void Player::draw(RenderWindow &window, float deltaTime, int runRow, int waitRow, int jumpRow) {
    drawWaiting(window, deltaTime, waitRow);
}

void Player::drawJumping(RenderWindow &window, float deltaTime, int row) {
    return;
}

void Player::drawRunning(RenderWindow &window, float deltaTime, int row) {
    playerSheetStartY = row * frameHeight;
    timeSinceLastFrame += deltaTime;

    if ((Keyboard::isKeyPressed(Keyboard::A) or Keyboard::isKeyPressed(Keyboard::D)) && timeSinceLastFrame >= animationSpeed) {
        currFrame = (currFrame + 1) % numFrames;
        playerSprite.setTextureRect(IntRect(currFrame * frameWidth, playerSheetStartY, frameWidth, frameHeight));
        timeSinceLastFrame = 0.0f;
    }
    if (Keyboard::isKeyPressed(Keyboard::D)) {
        playerSprite.move(300* deltaTime, 0);
    } else if (Keyboard::isKeyPressed(Keyboard::A)) {
        playerSprite.move(-300* deltaTime, 0);
    }
    window.draw(playerSprite);
}

void Player::drawWaiting(RenderWindow &window, float deltaTime, int row) {
    playerSheetStartY = row * frameHeight;
    timeSinceLastFrame += deltaTime;

    if (!isAnyKeyPressed() && timeSinceLastFrame >= animationSpeed) {
        currFrame = (currFrame + 1) % numFrames;
        playerSprite.setTextureRect(IntRect(currFrame * frameWidth, playerSheetStartY, frameWidth, frameHeight));
        timeSinceLastFrame = 0.0f;
    }
    window.draw(playerSprite);
}

bool Player::isAnyKeyPressed()
{
    if (Keyboard::isKeyPressed(Keyboard::A)) {return true;}
    if (Keyboard::isKeyPressed(Keyboard::D)) {return true;}
    return false;
}



