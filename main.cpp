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
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::White);
        window.display();
    }
    return 0;
}
