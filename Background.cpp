//
// Created by Adnan on 10/8/2024.
//
#include "Background.h"
#include <iostream>

using namespace sf;
using namespace std;

Background::Background(const string& filepath, const RenderWindow& window) {
    if (!backgroundTexture.loadFromFile(filepath)) {
      cout << "Error loading background texture" << endl;
    } else {
      backgroundSprite.setTexture(backgroundTexture);
      scaleToFitWindow(window);
    }
}

void Background::draw(RenderWindow& window) {
  window.draw(backgroundSprite);
}

void Background::scaleToFitWindow(const RenderWindow& window) {
  backgroundSprite.setScale(
        static_cast<float>(window.getSize().x) / backgroundTexture.getSize().x,
        static_cast<float>(window.getSize().y) / backgroundTexture.getSize().y
  );
}