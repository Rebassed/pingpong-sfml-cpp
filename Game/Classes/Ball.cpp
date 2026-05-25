#include "Ball.h"

sf::Texture Ball::getTexture() {
	return texture;
}

float Ball::getPosition() {
	return X, Y = 400, 300;
}

void Ball::Move() {
	X += XSpeed;
	Y += YSpeed;
}