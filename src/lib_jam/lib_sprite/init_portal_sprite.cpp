/*
** EPITECH PROJECT, 2023
** Epitech-Jam
** File description:
** init_portal_sprite
*/

#include <SFML/Graphics.hpp>
#include "../../../Include/node_portal.h"

int const nombre_de_paire = 3;

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
        node->sprite_portal_a.setPosition(i * 10 ,i * 10);
        node->sprite_portal_b.setPosition(i * 20 ,i * 20 );
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
