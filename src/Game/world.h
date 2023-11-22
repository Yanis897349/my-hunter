/*
** EPITECH PROJECT, 2023
** My Hunter
** File description:
** World management
*/

#pragma once
#include "Game/entity.h"
#include <SFML/Audio/Types.h>
#include <SFML/Graphics/Types.h>
#define WORLD_BACKGROUND_PATH "src/assets/world/background.jpg"
#define WORLD_MUSIC_PATH "src/assets/world/ambient.ogg"

typedef struct world_s {
    sfTexture *background_texture;
    sfSprite *background_sprite;
    sfMusic *music;
    entity_t **entities;
    unsigned int entities_count;
} world_t;

int world_set_background(world_t *world, char *texture_path,
    sfRenderWindow *window);
int world_set_music(world_t *world, char *music_path);
int add_entity_to_world(world_t *world, entity_t *entity);
world_t *create_world(sfRenderWindow *window);
