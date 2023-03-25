/*
** EPITECH PROJECT, 2023
** stomper
** File description:
** boostrap mynavy
*/

#include <iostream>
#include <SFML/Graphics.hpp>

int main(int argc, char **argv)
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML Simple Window");
    sf::Sprite sprite_window;
    sf::Texture texture_background;
    texture_background.loadFromFile("map_final.png");
    sprite_window.setTexture(texture_background);
    sprite_window.setPosition(0, 0);
    sprite_window.setScale(1,1);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::White);
        window.draw(sprite_window);
        window.display();
    }
    return 0;
}
