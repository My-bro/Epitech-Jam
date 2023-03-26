/*
** EPITECH PROJECT, 2023
** Epitech-Jam
** File description:
** init_portal_sprite
*/

#include <SFML/Graphics.hpp>

void init_portal_sprite(sf::Texture *texture_vortex, sf::Sprite *portal_sprite , std::vector<sf::IntRect> *animationFrames)
{
    texture_vortex->loadFromFile("src/sprite/effect/vortex.png");
    portal_sprite->setTexture(*texture_vortex);
    portal_sprite->setScale(0.1,0.1);
    int frameWidth = 649 / 4;
    int frameHeight = 384;
    for (int i = 0; i < 4; ++i) {
        animationFrames->push_back(sf::IntRect(i * frameWidth, 0, frameWidth, frameHeight));
    }
}
