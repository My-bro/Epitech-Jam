/*
** EPITECH PROJECT, 2023
** Epitech-Jam
** File description:
** main
*/

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

void init_music( sf::Music *music);
void init_window_sprite(sf::RenderWindow *window, sf::Sprite *sprite_window, sf::Texture *texture_background);
void init_portal_sprite(sf::Texture *texture_vortex, sf::Sprite *portal_sprite , std::vector<sf::IntRect> *animationFrames);
void move(sf::Event event, sf::RenderWindow *window, sf::CircleShape *circle, sf::Vector2f *pos_cam);
void case_cam(sf::RenderWindow *window, sf::View *view1,  sf::Vector2f pos_cam);
void handle_frame_portal( sf::Sprite *portal_sprite, std::vector<sf::IntRect> animationFrames,  float *frameDuration, float *elapsedTime, int *currentFrame);

int main(int argc, char **argv)
{
    sf::Event event;
    sf::RenderWindow window(sf::VideoMode(4010, 4066), "SFML Simple Window");
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
    init_portal_sprite(&texture_vortex, &portal_sprite , &animationFrames);
    shape.setFillColor(sf::Color::Black);
    int currentFrame = 0;
    float frameDuration = 0.2f;
    float elapsedTime;
    
    float countdownDuration = 180.f; // 3 minutes in seconds
    float elapsedTimeAccumulated = 0.f;
    float remainingTime;
    
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
        move(event, &window, &shape, &pos_cam);
        case_cam(&window, &view1, pos_cam);
        handle_frame_portal(&portal_sprite, animationFrames, &frameDuration, &elapsedTime, &currentFrame);
        window.draw(sprite_window);
        window.draw(shape);
        window.draw(portal_sprite);
        timerText.setPosition(pos_cam.x + 20 , pos_cam.y + 20);
        timerText.setString(std::to_string(remainingMinutes) + ":" + (remainingSeconds < 10 ? "0" : "") + std::to_string(remainingSeconds));
        // Draw the timer text
        window.draw(timerText);
        window.display();
    }
    return 0;
}

