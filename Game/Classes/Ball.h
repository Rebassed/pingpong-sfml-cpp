#pragma once
#include <SFML/Graphics.hpp>

class Ball {
private:
    sf::Texture texture;

public:
    float X, Y;
    float XSpeed = 0.06f;
    float YSpeed = 0.06f;

    sf::Texture getTexture();
    float getPosition();
    void Move();

    Ball() {
        texture.loadFromFile("assets/arts/Ball.png");
    }
};