/*
** EPITECH PROJECT, 2023
** Epitech-Jam
** File description:
** case_came
*/

#include <SFML/Graphics.hpp>

void case_cam(sf::RenderWindow *window, sf::View *view1,  sf::Vector2f pos_cam)
{
    view1->reset(sf::FloatRect(pos_cam.x, pos_cam.y, 420, 420));
    window->setView(*view1);
}
