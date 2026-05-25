#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "Classes/Ball.h"
#include "Classes/Pong.h"

#include "hideConsole.h"

int score1_{};
int score2_{};

int main() {
    hideConsole();

    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "Gang Bang Michala");

    Pong pong1;
    Pong pong2;
    Ball ball;

    // Ball
    sf::Texture ballTexture(ball.getTexture());
    sf::Sprite ball_(ballTexture);
    ball.X = 400;
    ball.Y = 300;
    ball_.setPosition({ 400,300 });
    ball_.setOrigin({
        ball_.getLocalBounds().size.x / 2.f,
        ball_.getLocalBounds().size.y / 2.f
    });

    // Font
    const sf::Font font("assets/font/font.ttf");

    // Pongs
    sf::Texture pongTexture(pong1.getTexture());
    sf::Sprite pong1_(pongTexture);
    sf::Sprite pong2_(pongTexture);

    pong1.setY(300);pong2.setY(300);

    pong1_.setOrigin({
        pong1_.getLocalBounds().size.x / 2.f,
        pong1_.getLocalBounds().size.y / 2.f
    });

    pong2_.setOrigin({
        pong2_.getLocalBounds().size.x / 2.f,
        pong2_.getLocalBounds().size.y / 2.f
    });

    sf::Texture mapTexture("assets/arts/Board.png");
    sf::Sprite map(mapTexture);

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
            pong1.setY(pong1.getY() - 0.1f);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
            pong1.setY(pong1.getY() + 0.1f);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
            pong2.setY(pong2.getY() - 0.1f);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
            pong2.setY(pong2.getY() + 0.1f);
        }

        window.clear(sf::Color::White);

        // Drawing Map
        window.draw(map);
        map.setPosition({ -1, 0 });
        map.setScale({ 1.f, 1.5f });

        // Drawing Scores
        sf::Text score1(font, std::to_string(score1_), 50);
        sf::Text score2(font, std::to_string(score2_), 50);

        score1.setOrigin({
            score1.getLocalBounds().size.x / 2.f,
            0
        });

        score2.setOrigin({
              score2.getLocalBounds().size.x / 2.f,
              0
        });

        score1.setPosition({ 200, 50 });
        score2.setPosition({ 600, 50 });

        window.draw(score1);
        window.draw(score2);

        // ball
        ball.Move();
        ball_.setPosition({ ball.X, ball.Y });

        // pong(s)
        pong1_.setPosition({ 200, pong1.getY() });
        pong1_.setRotation(sf::Angle(sf::degrees(180.f)));

        pong2_.setPosition({ 600, pong2.getY() });

        // Collision Detection
        if (pong1_.getGlobalBounds().findIntersection(ball_.getGlobalBounds()) || pong2_.getGlobalBounds().findIntersection(ball_.getGlobalBounds())) {
            ball.XSpeed = -(ball.XSpeed);
            // ball.YSpeed = -(ball.YSpeed);
        }

        if (pong1.getY() < 0 || pong1.getY() > 600) {
            pong1.setY(0);
        }
        if (pong2.getY() < 0 || pong2.getY() > 600) {
            pong2.setY(0);
        }

        if (ball.X < 0 || ball.X > 800) {
            ball.XSpeed = -(ball.XSpeed);
        }
        else if (ball.Y < 0 || ball.Y > 600) {
            ball.YSpeed = -(ball.YSpeed);
        }

        // Win Detector
        if (ball.X <= 2) {
            ball.X = 400;
            ball.Y = 300;

            score2_++;
        }
        else if (ball.X >= 795) {
            ball.X = 400;
            ball.Y = 300;

            score1_++;
        }

        // Drawing
        window.draw(ball_);
        window.draw(pong1_);
        window.draw(pong2_);

        window.display();
    }
}
