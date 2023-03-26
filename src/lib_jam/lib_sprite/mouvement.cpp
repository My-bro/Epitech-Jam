/*
** EPITECH PROJECT, 2023
** Epitech-Jam
** File description:
** mouvement
*/

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

int const lim_cam_x = 1332;
int const lim_cam_y = 1364;
int const lim_sprite_x = 1532;
int const lim_sprite_y = 1565;
float const velocity = 0.1;
int mid = 200;

void check_direction(sf::Event event, sf::RenderWindow *window, sf::CircleShape *circle, sf::Vector2f *pos_cam)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        circle->setPosition(sf::Vector2f(circle->getPosition().x, circle->getPosition().y - velocity));
        if (circle->getPosition().y < lim_sprite_y - mid) {
            pos_cam->y -= velocity;
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        circle->setPosition(sf::Vector2f(circle->getPosition().x, circle->getPosition().y + velocity));
        if (circle->getPosition().y > mid) {
            pos_cam->y += velocity;
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        circle->setPosition(sf::Vector2f(circle->getPosition().x - velocity, circle->getPosition().y));
        if (circle->getPosition().x < lim_sprite_x - mid) {
            pos_cam->x -= velocity;
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        circle->setPosition(sf::Vector2f(circle->getPosition().x + velocity, circle->getPosition().y));
        if (circle->getPosition().x > mid) {
            pos_cam->x += velocity;
        }
    }
}

void check_overflow_cam(sf::Vector2f *pos_cam)
{
    if (pos_cam->x > lim_cam_x) {
        pos_cam->x = lim_cam_x;
    }
    if (pos_cam->x < 0) {
        pos_cam->x = 0;
    }
    if (pos_cam->y < 0) {
        pos_cam->y = 0;
    }
    if (pos_cam->y > lim_cam_y) {
        pos_cam->y = lim_cam_y;
    }
}

void check_overflow_shape(sf::RenderWindow *window, sf::CircleShape *circle)
{
    if (circle->getPosition().x <= 0) {
        circle->setPosition(sf::Vector2f(0, circle->getPosition().y));
    }
    if (circle->getPosition().x >= lim_sprite_x) {
        circle->setPosition(sf::Vector2f(lim_sprite_x, circle->getPosition().y));
    }
    if (circle->getPosition().y <= 0) {
        circle->setPosition(sf::Vector2f(circle->getPosition().x,0));
    }
    if (circle->getPosition().y >= lim_sprite_y) {
        circle->setPosition(sf::Vector2f(circle->getPosition().x, lim_sprite_y));
    }
}

void move(sf::Event event, sf::RenderWindow *window, sf::CircleShape *circle, sf::Vector2f *pos_cam)
{
    check_direction(event,window,circle,pos_cam);
    check_overflow_cam(pos_cam);
    check_overflow_shape(window, circle);
}