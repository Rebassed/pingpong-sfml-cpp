#include "Pong.h"

sf::Texture Pong::getTexture() {
	return texture;
}

float Pong::getY() {
	return Y;
}

void Pong::setY(float y) {
	Y = y;
}