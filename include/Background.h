//
// Created by Adnan on 10/8/2024.
//

#ifndef BACKGROUND_H
#define BACKGROUND_H
#include <string>
#include <SFML/Graphics.hpp>
using namespace sf;
class Background {
public:
    Background(const std::string& filepath, const RenderWindow& window);
    void draw(RenderWindow& window);
private:
    Texture backgroundTexture;
    Sprite backgroundSprite;

    void scaleToFitWindow(const RenderWindow& window);
};
#endif //BACKGROUND_H
