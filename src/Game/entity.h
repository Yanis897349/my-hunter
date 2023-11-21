/*
** EPITECH PROJECT, 2023
** My Hunter
** File description:
** Entity management
*/

#pragma once
#include <SFML/Graphics.h>
#define DEFAULT_ENTITY_X_POSITION 0
#define DEFAULT_ENTITY_Y_POSITION 0

typedef struct entity_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position;
} entity_t;

void entity_set_position(entity_t *entity, sfVector2f position);
entity_t *create_entity(char *texture_path);
