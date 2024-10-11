#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "../include//Background.h"
#include "../include/Platform.h"
#include "../include/Player.h"
using namespace sf;
int main() {
    Clock clock;
    RenderWindow window(VideoMode(1920, 1080), "SFML Window");
    Background backgroundLayer1("../assets/background/background_layer_1.png", window);
    Background backgroundLayer2("../assets/background/background_layer_2.png", window);
    Background backgroundLayer3("../assets/background/background_layer_3.png", window);
    Platform platform1(3, "grass_stone", Vector2f(300,300), window, Vector2f(2.0f, 2.0f));
    //row and number of frames for corresponding animations
    vector<int> idle = {0,6};
    vector<int> run = {2,8};
    vector<int> jump = {3, 8};
    Player player("../assets/character/char_blue.png", Vector2f(300, 300), Vector2f(3.0f, 3.0f), 0.1f, 56,56, run, jump, idle);
    player.getCollisionBox().trimEdges(50, 50, 75);
    player.getCollisionBox().move(Vector2f(50,75));
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
        player.draw(window, deltaTime);
        window.display();
    }
    return 0;
}
