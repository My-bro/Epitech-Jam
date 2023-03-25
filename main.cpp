/*
** EPITECH PROJECT, 2023
** stomper
** File description:
** boostrap mynavy
*/

#include <iostream>
#include <SFML/Graphics.hpp>

void move(sf::Event event, sf::RenderWindow *window, sf::CircleShape *circle)
{
    int velocity = 10;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        circle->setPosition(sf::Vector2f(circle->getPosition().x, circle->getPosition().y - velocity));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        circle->setPosition(sf::Vector2f(circle->getPosition().x, circle->getPosition().y + velocity));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        circle->setPosition(sf::Vector2f(circle->getPosition().x - velocity, circle->getPosition().y));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        circle->setPosition(sf::Vector2f(circle->getPosition().x + velocity, circle->getPosition().y));
    }
    if (circle->getPosition().x <= 0) {
        circle->setPosition(sf::Vector2f(0, circle->getPosition().y));
    }
    if (circle->getPosition().y <= 0) {
        circle->setPosition(sf::Vector2f(circle->getPosition().x, 0));
    }
}

int main(int argc, char **argv)
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML Simple Window");
    sf::Sprite sprite_window;
    sf::Texture texture_background;
    texture_background.loadFromFile("src/sprite/backgroud/map_final.png");
    sprite_window.setTexture(texture_background);
    sprite_window.setPosition(0, 0);
    sf::Vector2u windowSize = window.getSize();
    sf::Vector2u textureSize = texture_background.getSize();
    float scaleX = static_cast<float>(windowSize.x) / textureSize.x;
    float scaleY = static_cast<float>(windowSize.y) / textureSize.y;
    float scale = std::min(scaleX, scaleY);
    sprite_window.setScale(scale, scale);
    sf::CircleShape shape(50.f);
    shape.setFillColor(sf::Color(0, 0, 0));
    while (window.isOpen()) {
        sf::Event event;
        window.clear(sf::Color::White);
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            move(event, &window, &shape);
        }
        window.draw(sprite_window);
        window.draw(shape);
        window.display();
    }
    return 0;
}
