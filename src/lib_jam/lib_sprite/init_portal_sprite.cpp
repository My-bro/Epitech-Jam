/*
** EPITECH PROJECT, 2023
** Epitech-Jam
** File description:
** init_portal_sprite
*/

#include <SFML/Graphics.hpp>
#include "../../../Include/node_portal.h"
#include <random>

int const nombre_de_paire = 3;
int const lim_sprite_x = 1532;
int const lim_sprite_y = 1565;

void link_node(node_info_t **head, node_info_t **tail, node_info_t **node)
{
    if (*head == NULL) {
        *head = *node;
        *tail = *node;
    } else {
        (*tail)->next = *node;
        *tail = *node;
    }
}

int randomInt(int min, int max)
{
    std::random_device randomDevice;
    std::mt19937 generator(randomDevice());
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(generator);
}


node_info_t *init_portal_sprite(sf::Texture *texture_vortex, sf::Sprite *portal_sprite , std::vector<sf::IntRect> *animationFrames)
{
    texture_vortex->loadFromFile("src/sprite/effect/vortex.png");
    node_info_t *head = NULL;
    node_info_t *tail = NULL;
    for (int i = 1; i != nombre_de_paire + 1; ++i) {
        node_info_t *node = new node_info_t;
        node->sprite_portal_a.setTexture(*texture_vortex);
        node->sprite_portal_b.setTexture(*texture_vortex);
        node->sprite_portal_a.setScale(0.1,0.1);
        node->sprite_portal_b.setScale(0.1,0.1);
        node->sprite_portal_a.setPosition(randomInt(0, lim_sprite_x ),randomInt(0, lim_sprite_y));
        node->sprite_portal_b.setPosition(randomInt(0, lim_sprite_x),randomInt(0, lim_sprite_y));
        link_node(&head, &tail, &node);
        node = node->next;
    }
    int frameWidth = 649 / 4;
    int frameHeight = 384;
    for (int i = 0; i < 4; ++i) {
        animationFrames->push_back(sf::IntRect(i * frameWidth, 0, frameWidth, frameHeight));
    }
    return head;
}
