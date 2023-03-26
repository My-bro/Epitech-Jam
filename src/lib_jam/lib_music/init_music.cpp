/*
** EPITECH PROJECT, 2023
** Epitech-Jam
** File description:
** init_music
*/

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

void init_music( sf::Music *music)
{
    music->openFromFile("src/musique/musique.ogg");
    //music->play();
    music->setVolume(50);
    music->setLoop(true);
}
