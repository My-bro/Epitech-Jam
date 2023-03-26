/*
** EPITECH PROJECT, 2023
** Epitech-Jam
** File description:
** init_window_sprite
*/

#include <SFML/Graphics.hpp>

void init_window_sprite(sf::RenderWindow *window, sf::Sprite *sprite_window, sf::Texture *texture_background)
{
    texture_background->loadFromFile("src/sprite/Backgroud/map_final.png");
    sprite_window->setTexture(*texture_background);
    sprite_window->setPosition(0, 0);
    sf::Vector2u windowSize = window->getSize();
    sf::Vector2u textureSize = texture_background->getSize();
    float scaleX = static_cast<float>(windowSize.x) / textureSize.x;
    float scaleY = static_cast<float>(windowSize.y) / textureSize.y;
    float scale = std::min(scaleX, scaleY);
    sprite_window->setScale(scale, scale);
}
