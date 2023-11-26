/*
** EPITECH PROJECT, 2023
** My Hunter
** File description:
** World management
*/

#include "Game/world.h"
#include "Game/entity.h"
#include "Game/game.h"
#include "include/my_std.h"
#include "include/my_strings.h"
#include <SFML/Audio/Music.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Types.h>
#include <stdio.h>
#include <stdlib.h>

static void scale_background(world_t *world, sfRenderWindow *window)
{
    sfVector2u texture_size = sfTexture_getSize(world->background_texture);
    sfVector2u window_size = sfRenderWindow_getSize(window);

    sfSprite_setScale(world->background_sprite,
        (sfVector2f){(float)window_size.x / texture_size.x,
            (float)window_size.y / texture_size.y});
}

static int world_setup_score_text(world_t *world)
{
    world->score_text = sfText_create();
    if (world->score_text == NULL)
        return EXIT_FAILURE;
    world->score_font = sfFont_createFromFile(WORLD_SCORE_FONT_PATH);
    if (world->score_font == NULL)
        return EXIT_FAILURE;
    sfText_setFont(world->score_text, world->score_font);
    sfText_setCharacterSize(world->score_text, WORLD_SCORE_TEXT_SIZE);
    sfText_setPosition(world->score_text, (sfVector2f) {0, 0});
    sfText_setColor(world->score_text, sfWhite);
    world_set_score(world, 0);
    return EXIT_SUCCESS;
}

static int world_setup_level(world_t *world, sfRenderWindow *window)
{
    entity_t *entity = NULL;

    world->level = create_level(1, 1, 1);
    if (world->level == NULL)
        return EXIT_FAILURE;
    for (uint i = 0; i < world->level->entities_to_spawn; i++) {
        entity = create_entity(DEFAULT_ENTITY_TEXTURE_PATH, window);
        if (entity == NULL)
            return EXIT_FAILURE;
        if (add_entity_to_world(world, entity) == EXIT_FAILURE)
            return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

static int world_set_background(world_t *world, char *texture_path,
    sfRenderWindow *window)
{
    if (world->background_sprite != NULL)
        sfSprite_destroy(world->background_sprite);
    if (world->background_texture != NULL)
        sfTexture_destroy(world->background_texture);
    world->background_sprite = sfSprite_create();
    if (world->background_sprite == NULL)
        return EXIT_FAILURE;
    world->background_texture = sfTexture_createFromFile(texture_path, NULL);
    if (world->background_texture == NULL)
        return EXIT_FAILURE;
    sfSprite_setTexture(world->background_sprite,
        world->background_texture, sfTrue);
    scale_background(world, window);
    return EXIT_SUCCESS;
}

void world_new_level(level_t *level, sfRenderWindow *window, world_t *world)
{
    entity_t *entity = NULL;

    if (level->current_killed_entities >=
        level->entities_to_kill) {
        update_level(level, level->level + 1,
        level->entities_to_spawn + 1,
        level->entities_to_kill + 1);
        level->current_killed_entities = 0;
        entity = create_entity(DEFAULT_ENTITY_TEXTURE_PATH, window);
        add_entity_to_world(world, entity);
    }
}

int world_set_music(world_t *world, char *music_path)
{
    if (world->music != NULL)
        sfMusic_destroy(world->music);
    world->music = sfMusic_createFromFile(music_path);
    if (world->music == NULL)
        return EXIT_FAILURE;
    sfMusic_setLoop(world->music, sfTrue);
    sfMusic_setVolume(world->music, DEFAULT_MUSIC_VOLUME);
    sfMusic_play(world->music);
    return EXIT_SUCCESS;
}

void world_set_score(world_t *world, int score)
{
    char score_int[SCORE_INT_LEN];
    char score_str[SCORE_STR_LEN] = SCORE_STR_PREFIX;

    my_putnbr_base(score, BASE_10, score_int);
    my_strcat(score_str, score_int);
    sfText_setString(world->score_text, score_str);
}

int add_entity_to_world(world_t *world, entity_t *entity)
{
    int old_entities_size = world->entities_count * sizeof(entity_t);
    int new_entities_size = old_entities_size + sizeof(entity_t);

    world->entities = my_realloc(world->entities, old_entities_size,
        new_entities_size);
    if (world->entities == NULL)
        return EXIT_FAILURE;
    world->entities[world->entities_count] = entity;
    world->entities_count++;
    return EXIT_SUCCESS;
}

world_t *create_world(sfRenderWindow *window)
{
    world_t *world = malloc(sizeof(world_t));

    if (world == NULL)
        return NULL;
    world->background_sprite = NULL;
    world->background_texture = NULL;
    world->music = NULL;
    world->entities = NULL;
    world->entities_count = 0;
    if (world_setup_score_text(world) == EXIT_FAILURE)
        return NULL;
    if (world_set_background(
        world, WORLD_BACKGROUND_PATH, window) == EXIT_FAILURE)
        return NULL;
    if (world_set_music(world, WORLD_MUSIC_PATH) == EXIT_FAILURE)
        return NULL;
    if (world_setup_level(world, window) == EXIT_FAILURE)
        return NULL;
    return world;
}
