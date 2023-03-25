/*
** EPITECH PROJECT, 2023
** stomper
** File description:
** boostrap mynavy
*/

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

void move(sf::Event event, sf::RenderWindow *window, sf::CircleShape *circle, sf::Vector2f *pos_cam)
{
    int lim_camx = 1332;
    float velocity = 0.4;
    //std::cout <<pos_cam->y<<'\n'<<std::endl;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        circle->setPosition(sf::Vector2f(circle->getPosition().x, circle->getPosition().y - velocity));
        if (circle->getPosition().y < 1465) {
            pos_cam->y -= velocity;
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        circle->setPosition(sf::Vector2f(circle->getPosition().x, circle->getPosition().y + velocity));
        if (circle->getPosition().y > 100) {
            pos_cam->y += velocity;
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        circle->setPosition(sf::Vector2f(circle->getPosition().x - velocity, circle->getPosition().y));
        if (circle->getPosition().x < 1432) {
            pos_cam->x -= velocity;
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        circle->setPosition(sf::Vector2f(circle->getPosition().x + velocity, circle->getPosition().y));
        if (circle->getPosition().x > 100) {
            pos_cam->x += velocity;
        }
    }

    if (pos_cam->x > lim_camx) {
        pos_cam->x = lim_camx;
    }
    if (pos_cam->x < 0) {
        pos_cam->x = 0;
    }
    if (pos_cam->y < 0) {
        pos_cam->y = 0;
    }
    if (pos_cam->y > 1364) {
        pos_cam->y = 1364;
    }
    if (circle->getPosition().x <= 0) {
        circle->setPosition(sf::Vector2f(0, circle->getPosition().y));
    }
    if (circle->getPosition().x >= 1532) {
        circle->setPosition(sf::Vector2f(1532, circle->getPosition().y));
    }
    if (circle->getPosition().y <= 0) {
        circle->setPosition(sf::Vector2f(circle->getPosition().x,0));
    }
    if (circle->getPosition().y >= 1565) {
        circle->setPosition(sf::Vector2f(circle->getPosition().x, 1565));
    }
}

int main(int argc, char **argv)
{
    sf::RenderWindow window(sf::VideoMode(4010, 4066), "SFML Simple Window");
    sf::Sprite sprite_window;
    sf::Texture texture_background;

    sf::Music music;
    music.openFromFile("src/musique/musique.ogg");
    music.play();
    music.setVolume(50);
    music.setLoop(true);
    texture_background.loadFromFile("src/sprite/Backgroud/map_final.png");
    sprite_window.setTexture(texture_background);
    sprite_window.setPosition(0, 0);
    sf::Vector2u windowSize = window.getSize();
    sf::Vector2u textureSize = texture_background.getSize();
    //std::cout <<textureSize.x<<'\n'<<std::endl;
    float scaleX = static_cast<float>(windowSize.x) / textureSize.x;
    float scaleY = static_cast<float>(windowSize.y) / textureSize.y;
    float scale = std::min(scaleX, scaleY);
    sprite_window.setScale(scale, scale);
    float view_w = 200;
    float view_h = 200;
    sf::Vector2f pos_cam (0,0);
    sf::CircleShape shape(10.f);
    shape.setFillColor(sf::Color(0, 0, 0));
    while (window.isOpen()) {
        sf::Event event;
        window.clear(sf::Color::White);
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        move(event, &window, &shape, &pos_cam);
        sf::View view1(sf::FloatRect(0, 0, view_w, view_h));
        sf::Vector2f position(view_w/2, view_h/2);
        //if (position.x)
        position.x = shape.getPosition().x + 5.f - view_w / 2;
        position.y = shape.getPosition().y + 5.f - view_h / 2;
        if (position.x < 0)
            position.x = 0;
        if (position.y < 0)
            position.y = 0;
        //if (shape.getPosition().x + view_w < windowSize.x && shape.getPosition().y + view_h< windowSize.y) {
            view1.reset(sf::FloatRect(pos_cam.x, pos_cam.y, 220, 220));
            window.setView(view1);
        //}
        window.draw(sprite_window);
        window.draw(shape);
        window.display();
    }
    return 0;
}
