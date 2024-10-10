//
// Created by Adnan on 10/10/2024.
//

#include "CollisionBox.h"

CollisionBox::CollisionBox(const Vector2f& size, const Vector2f& pos) {
    this->size = size;
    box.setSize(size);
    box.setPosition(pos);
    box.setFillColor(sf::Color::Transparent);
    box.setOutlineColor(sf::Color::Red); // debug
    box.setOutlineThickness(1.0f);
}

Vector2f CollisionBox::getSize() const {
    return size;
}

Vector2f CollisionBox::getPosition() const {
    return box.getPosition();
}

void CollisionBox::move(const Vector2f &direction) {
    box.move(direction);
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



