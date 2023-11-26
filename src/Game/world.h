/*
** EPITECH PROJECT, 2023
** My Hunter
** File description:
** World management
*/

#pragma once
#include "Game/entity.h"
#include "Game/level.h"
#include <SFML/Audio/Types.h>
#include <SFML/Graphics/Types.h>
#define WORLD_BACKGROUND_PATH "src/assets/world/background.jpg"
#define WORLD_MUSIC_PATH "src/assets/world/ambient.ogg"
#define DEFAULT_MUSIC_VOLUME 20
#define WORLD_SCORE_FONT_PATH "src/assets/world/arial.ttf"
#define WORLD_SCORE_TEXT_SIZE 20
#define SCORE_INT_LEN 33
#define SCORE_STR_LEN 40
#define SCORE_STR_PREFIX "Score: "

typedef struct world_s {
    sfTexture *background_texture;
    sfSprite *background_sprite;
    sfFont *score_font;
    sfText *score_text;
    sfMusic *music;
    level_t *level;
    entity_t **entities;
    unsigned int entities_count;
} world_t;

void world_set_score(world_t *world, int score);
int world_set_music(world_t *world, char *music_path);
void world_new_level(level_t *level, sfRenderWindow *window, world_t *world);
int add_entity_to_world(world_t *world, entity_t *entity);
world_t *create_world(sfRenderWindow *window);
