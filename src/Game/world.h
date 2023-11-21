/*
** EPITECH PROJECT, 2023
** My Hunter
** File description:
** World management
*/

#pragma once
#include "Game/entity.h"
#include <SFML/Graphics/Types.h>
#define WORLD_BACKGROUND_PATH "src/assets/world/background.jpg"

typedef struct world_s {
    sfTexture *background_texture;
    sfSprite *background_sprite;
    entity_t **entities;
    unsigned int entities_count;
} world_t;

int world_set_background(world_t *world, char *texture_path,
    sfRenderWindow *window);
world_t *create_world(sfRenderWindow *window);
