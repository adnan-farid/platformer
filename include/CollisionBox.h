//
// Created by Adnan on 10/10/2024.
//

#ifndef COLLISIONBOX_H
#define COLLISIONBOX_H

#include <SFML\Graphics.hpp>
using namespace sf;
using namespace std;

class CollisionBox {
public:
    CollisionBox(const Vector2f& size, const Vector2f& pos);
    void setPosition(const Vector2f& position);
    void move(const Vector2f& direction);
    Vector2f getPosition() const;
    Vector2f getSize() const;
    bool doesIntersect(const CollisionBox& other) const;
    void debugDraw(RenderWindow& window) const;
    void setSize(const Vector2f& size);
    void trimEdges(float left = 0.0f, float right = 0.0f, float top = 0.0f, float bottom = 0.0f);
private:
    Vector2f size;
    RectangleShape box;
};



#endif //COLLISIONBOX_H
