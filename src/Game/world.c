/*
** EPITECH PROJECT, 2023
** My Hunter
** File description:
** World management
*/

#include "Game/world.h"
#include "Game/game.h"
#include "include/my_std.h"
#include <SFML/Graphics.h>
#include <SFML/Graphics/Sprite.h>
#include <stdlib.h>

static void scale_background(world_t *world, sfRenderWindow *window)
{
    sfVector2u texture_size = sfTexture_getSize(world->background_texture);
    sfVector2u window_size = sfRenderWindow_getSize(window);

    sfSprite_setScale(world->background_sprite,
        (sfVector2f){(float)window_size.x / texture_size.x,
            (float)window_size.y / texture_size.y});
}

int world_set_background(world_t *world, char *texture_path,
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
    if (world_set_background(
        world, WORLD_BACKGROUND_PATH, window) == EXIT_FAILURE)
        return NULL;
    return world;
}
