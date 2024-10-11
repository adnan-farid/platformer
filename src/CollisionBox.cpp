//
// Created by Adnan on 10/10/2024.
//

#include "../include/CollisionBox.h"
#include <iostream>
CollisionBox::CollisionBox(const Vector2f& size, const Vector2f& pos) {
    this->size = size;
    box.setSize(size);
    box.setPosition(pos);
    box.setFillColor(Color::Transparent);
    box.setOutlineColor(Color::Red); // debug
    box.setOutlineThickness(1.0f);
}

Vector2f CollisionBox::getSize() const {
    return size;
}

Vector2f CollisionBox::getPosition() const {
    return box.getPosition();
}

void CollisionBox::move(const Vector2f &direction) {
    box.setPosition(getPosition() + direction);
}

void CollisionBox::debugDraw(RenderWindow &window) const {
    window.draw(box);
}

void CollisionBox::setPosition(const Vector2f &position) {
    box.setPosition(position);
}

void CollisionBox::setSize(const Vector2f &size) {
    box.setSize(size);
}

bool CollisionBox::doesIntersect(const CollisionBox &other) const {
    return box.getGlobalBounds().intersects(other.box.getGlobalBounds());
}

void CollisionBox::trimEdges(float left, float right, float top, float bottom) {
    float width = box.getSize().x - left - right;
    float height = box.getSize().y - top - bottom;

    if (width < 0) {width = 0;}
    if (height < 0) {height = 0;}

    box.setSize(Vector2f(width, height));
}


