#pragma once

#include <SFML/Graphics.hpp>

class Pong {
private:
	sf::Texture texture;

	float Y;
public:
	sf::Texture getTexture();
	float getY();
	void setY(float y);

	Pong() {
		texture.loadFromFile("assets/arts/Player.png");
	}
};
