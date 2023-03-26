/*
** EPITECH PROJECT, 2023
** Epitech-Jam
** File description:
** main
*/

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Include/node_portal.h"


void init_music( sf::Music *music);
void init_window_sprite(sf::RenderWindow *window, sf::Sprite *sprite_window, sf::Texture *texture_background);
node_info_t *init_portal_sprite(sf::Texture *texture_vortex, sf::Sprite *portal_sprite , std::vector<sf::IntRect> *animationFrames);
sf::Vector2f *move(sf::Event event, sf::RenderWindow *window, sf::CircleShape *circle, sf::Vector2f *pos_cam);
void case_cam(sf::RenderWindow *window, sf::View *view1,  sf::Vector2f pos_cam);
void handle_frame_portal( sf::Sprite *portal_sprite, std::vector<sf::IntRect> animationFrames,  float *frameDuration, float *elapsedTime, int *currentFrame);



int aff_diamonds(sf::RenderWindow *window, float *x, float *y, sf::CircleShape *shape, int *diamondCount, int *j, char *state)
{
    std::srand(std::time(nullptr));
    sf::Texture diamondTexture;
    diamondTexture.loadFromFile("diamond blue.png");
    sf::Sprite diamondSprite(diamondTexture);
    diamondSprite.setOrigin(diamondSprite.getGlobalBounds().width / 2, diamondSprite.getGlobalBounds().height / 2);
    std::rand();
    for (int i = 0; i < 10; i++)
    {
        diamondSprite.setPosition(x[i], y[i]);
        diamondSprite.setScale(0.005, 0.005);
        if (shape->getGlobalBounds().intersects(diamondSprite.getGlobalBounds()) && i != *j)
        {
            *diamondCount = *diamondCount + 1;
            *j = i;
            state[i] == 'N';
        }
        if (state[i] != 'N') {
            window->draw(diamondSprite);
        }
    }
    return 0;
}

void draw_vortex(node_info_t *head,  sf::RenderWindow *window, std::vector<sf::IntRect> animationFrames ,int currentFrame)
{
    while (head != nullptr) {
        head->sprite_portal_a.setTextureRect(animationFrames[currentFrame]);
        head->sprite_portal_b.setTextureRect(animationFrames[currentFrame]);
        window->draw(head->sprite_portal_a);
        window->draw(head->sprite_portal_b);
        head = head->next;
    }
}

int main(int argc, char **argv)
{
    sf::Event event;
    sf::RenderWindow window(sf::VideoMode(4010, 4066), "SFML Simple Window");
    window.setFramerateLimit(60);
    sf::Sprite sprite_window;
    sf::Texture texture_background;
    sf::Music music;

    sf::Texture texture_vortex;
    sf::Sprite portal_sprite;
    std::vector<sf::IntRect> animationFrames;

    sf::View view1(sf::FloatRect(0, 0, 200, 200));
    sf::CircleShape shape(10.f);
    sf::Vector2f pos_cam (0,0);
    sf::Clock clock;

    sf::Font font;
    sf::Color color_menu(230,184,0);
    font.loadFromFile("src/font/font.ttf");
    sf::Text timerText;
    timerText.setFont(font);
    timerText.setCharacterSize(24);
    timerText.setFillColor(color_menu);
    timerText.setPosition(10, 10);

    init_music(&music);
    init_window_sprite(&window, &sprite_window, &texture_background);
    node_info_t *head = init_portal_sprite(&texture_vortex, &portal_sprite , &animationFrames);
    shape.setFillColor(sf::Color::Black);

    int currentFrame = 0;
    float frameDuration = 0.2f;
    float elapsedTime;

    float countdownDuration = 180.f; // 3 minutes in seconds
    float elapsedTimeAccumulated = 0.f;
    float remainingTime;

    int diamondCount = 0;
    float x[10];
    float y[10];
    char state[10];
    for (int i = 0; i < 10; i++)
    {
        x[i] = static_cast<float>(std::rand() % 600);
        y[i] = static_cast<float>(std::rand() % 600);
    }
    int k = -1;

    while (window.isOpen()) {
        window.clear(sf::Color::White);
        elapsedTime = clock.restart().asSeconds();
        elapsedTimeAccumulated += elapsedTime;
        remainingTime = countdownDuration - elapsedTimeAccumulated;

        int remainingMinutes = static_cast<int>(remainingTime) / 60;
        int remainingSeconds = static_cast<int>(remainingTime) % 60;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        sf::Vector2f *position = move(event, &window, &shape, &pos_cam);
        case_cam(&window, &view1, pos_cam);
        handle_frame_portal(&portal_sprite, animationFrames, &frameDuration, &elapsedTime, &currentFrame);
        //window.draw(sprite_window);
        window.draw(shape);
        window.draw(portal_sprite);
        timerText.setPosition(pos_cam.x + 20 , pos_cam.y + 20);
        timerText.setString(std::to_string(remainingMinutes) + ":" + (remainingSeconds < 10 ? "0" : "") + std::to_string(remainingSeconds));
        // Draw the timer text
        window.draw(sprite_window);
        window.draw(timerText);
        window.draw(shape);
        aff_diamonds(&window, x, y, &shape, &diamondCount, &k, state);
        sf::Font font;
        font.loadFromFile("src/font/font.ttf");
        sf::Text text;
        text.setFont(font);
        text.setCharacterSize(24);
        text.setString("Diamonds collected: " + std::to_string(diamondCount));
        text.setPosition(10.0f + position->x, 10.0f + position->y);
        text.setScale(0.5, 0.5);
        draw_vortex(head,  &window, animationFrames , currentFrame);
        window.draw(text);
        window.display();
    }
    return 0;
}

