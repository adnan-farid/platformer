//
// Created by Adnan on 10/9/2024.
//

#include "Player.h"
#include <iostream>

Player::Player(const string &filename, int x, int y, Vector2f scale, float animationSpeed, int frameHeight, int frameWidth, vector<int> run, vector<int> jump, vector<int> wait)
    : animationSpeed(animationSpeed), frameHeight(frameHeight), frameWidth(frameWidth) {
    if (!playerTexture.loadFromFile(filename)) {
        playerTexture.loadFromFile("assets/character/char_blue.png");
    }
    playerSprite.setPosition(x, y);
    playerSprite.setTexture(playerTexture);
    playerSprite.setScale(scale.x, scale.y);
    //anim properties
    if (run.size() > 0) { runRow = run[0]; runFrames = run[1]; }
    if (wait.size() > 0) { waitRow = wait[0]; waitFrames = wait[1]; }
    if (jump.size() > 0) { jumpRow = jump[0]; jumpFrames = jump[1]; }
}

int currFrame = 0;

void Player::draw(RenderWindow &window, float deltaTime) {
    if (!isAnyKeyPressed()) {
        drawWaiting(window, deltaTime, waitRow, waitFrames);
    } else {
        drawRunning(window, deltaTime, runRow, runFrames);
    }
}

void Player::drawJumping(RenderWindow &window, float deltaTime, int row, int numFrames) {
    return;
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
        playerSprite.move(300* deltaTime, 0);
    } else if (Keyboard::isKeyPressed(Keyboard::A)) {
        playerSprite.move(-300* deltaTime, 0);
    }
    window.draw(playerSprite);
}

void Player::drawWaiting(RenderWindow &window, float deltaTime, int row, int numFrames) {
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



