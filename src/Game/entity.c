/*
** EPITECH PROJECT, 2023
** My Hunter
** File description:
** Entity management
*/

#include "Game/entity.h"
#include <SFML/Audio/Music.h>
#include <SFML/Audio/Sound.h>
#include <SFML/Audio/SoundBuffer.h>
#include <SFML/Audio/Types.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Clock.h>
#include <SFML/System/Vector2.h>
#include <stdio.h>
#include <stdlib.h>

static void scale_entity(entity_t *entity, sfRenderWindow *window)
{
    sfVector2u texture_size = sfTexture_getSize(entity->texture);
    sfVector2u window_size = sfRenderWindow_getSize(window);
    float scaleX = (float)window_size.x / texture_size.x * SCALE_FACTOR;
    float scaleY = (float)window_size.y / texture_size.y * SCALE_FACTOR;
    float scale = scaleX < scaleY ? scaleX : scaleY;
    float maxScale = MAX_SCALE_FACTOR;

    if (scale > maxScale) {
        scale = maxScale;
    }
    sfSprite_setScale(entity->sprite, (sfVector2f){scale, scale});
}

static int set_entity_clocks(entity_t *entity)
{
    entity->anim_clock = sfClock_create();
    entity->move_clock = sfClock_create();
    if (entity->anim_clock == NULL || entity->move_clock == NULL)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

static int set_entity_sprite(entity_t *entity, sfRenderWindow *window,
    char *texture_path)
{
    sfVector2u texture_size;
    int window_height = sfRenderWindow_getSize(window).y;
    sfVector2f entity_position =
        {DEFAULT_ENTITY_X_POS, rand() % (window_height - entity->rect.height)};

    entity->texture = sfTexture_createFromFile(texture_path, NULL);
    if (entity->texture == NULL)
        return EXIT_FAILURE;
    texture_size = sfTexture_getSize(entity->texture);
    entity->rect = (sfIntRect) {0, 0,
        texture_size.x / DEFAULT_ENTITY_SPRITES_WIDTH, texture_size.y};
    entity->sprite = sfSprite_create();
    if (entity->sprite == NULL)
        return EXIT_FAILURE;
    sfSprite_setTexture(entity->sprite, entity->texture, sfTrue);
    entity_set_position(entity, entity_position, window);
    entity->hitbox = sfSprite_getGlobalBounds(entity->sprite);
    return EXIT_SUCCESS;
}

static int set_entity_sound(entity_t *entity, char *sound_path)
{
    entity->hit_sound = sfSound_create();
    if (entity->hit_sound == NULL)
        return EXIT_FAILURE;
    entity->hit_sound_buffer = sfSoundBuffer_createFromFile(sound_path);
    if (entity->hit_sound_buffer == NULL)
        return EXIT_FAILURE;
    sfSound_setBuffer(entity->hit_sound, entity->hit_sound_buffer);
    return EXIT_SUCCESS;
}

void entity_set_position(entity_t *entity, sfVector2f position,
    sfRenderWindow *window)
{
    double window_width = sfRenderWindow_getSize(window).x;

    if (position.x > window_width)
        position = (sfVector2f) {0, position.y};
    entity->position = position;
    sfSprite_setPosition(entity->sprite, position);
}

void update_entity(entity_t *entity, sfRenderWindow *window)
{
    double anim_time =
        sfClock_getElapsedTime(entity->anim_clock).microseconds / MS_TO_SEC;
    double move_time =
        sfClock_getElapsedTime(entity->move_clock).microseconds / MS_TO_SEC;
    sfVector2u texture_size = sfTexture_getSize(entity->texture);

    if (anim_time > ANIMATION_SPEED) {
        sfClock_restart(entity->anim_clock);
        entity->rect.left += texture_size.x / DEFAULT_ENTITY_SPRITES_WIDTH;
        if ((uint) entity->rect.left >= texture_size.x)
            entity->rect.left = 0;
        sfSprite_setTextureRect(entity->sprite, entity->rect);
    }
    if (move_time > MOVE_SPEED) {
        sfClock_restart(entity->move_clock);
        entity->position.x += MOVE_OFFSET;
        entity_set_position(entity, entity->position, window);
    }
    scale_entity(entity, window);
    entity->hitbox = sfSprite_getGlobalBounds(entity->sprite);
}

void destroy_entity(entity_t *entity)
{
    sfSprite_destroy(entity->sprite);
    sfTexture_destroy(entity->texture);
    sfClock_destroy(entity->anim_clock);
    sfClock_destroy(entity->move_clock);
    sfSoundBuffer_destroy(entity->hit_sound_buffer);
    sfSound_destroy(entity->hit_sound);
    free(entity);
}

entity_t *create_entity(char *texture_path, sfRenderWindow *window)
{
    entity_t *entity = malloc(sizeof(entity_t));

    if (entity == NULL)
        return NULL;
    if (set_entity_clocks(entity) == EXIT_FAILURE)
        return NULL;
    if (set_entity_sprite(entity, window, texture_path) == EXIT_FAILURE)
        return NULL;
    if (set_entity_sound(entity,
        DEFAULT_ENTITY_HIT_SOUND_PATH) == EXIT_FAILURE)
        return NULL;
    return entity;
}
