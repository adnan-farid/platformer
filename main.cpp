#include <SFML/Graphics.hpp>
#include <iostream>
#include "Background.h"
#include "Platform.h"
#include "Player.h"
using namespace sf;
int main() {
    Clock clock;
    RenderWindow window(VideoMode(1920, 1080), "SFML Window");
    Background backgroundLayer1("../assets/background/background_layer_1.png", window);
    Background backgroundLayer2("../assets/background/background_layer_2.png", window);
    Background backgroundLayer3("../assets/background/background_layer_3.png", window);
    Platform platform1(5, "grass_stone", Vector2f(300,300), window, Vector2f(2.0f, 2.0f));
    Player player("../assets/character/char_blue.png", 300, 300, Vector2f(2.0f, 2.0f), 0.1f, 8,56,56);
    while (window.isOpen()) {
        Event event;
        float deltaTime = clock.restart().asSeconds();
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }
        window.clear();
        backgroundLayer1.draw(window);
        backgroundLayer2.draw(window);
        backgroundLayer3.draw(window);
        platform1.draw(window);
        player.draw(window, deltaTime,2,5,5);
        window.display();
    }
    return 0;
}
