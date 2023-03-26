/*
** EPITECH PROJECT, 2023
** Epitech-Jam
** File description:
** handle_frame_portal
*/

#include <SFML/Graphics.hpp>

void handle_frame_portal( sf::Sprite *portal_sprite, std::vector<sf::IntRect> animationFrames,  float *frameDuration, float *elapsedTime, int *currentFrame)
{
    *frameDuration -= *elapsedTime;
    if (*frameDuration <= 0) {
        *currentFrame = (*currentFrame + 1) % 4;
        portal_sprite->setTextureRect(animationFrames[*currentFrame]);
        *frameDuration = 0.2f;
    }
}
