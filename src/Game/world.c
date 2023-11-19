/*
** EPITECH PROJECT, 2023
** My Hunter
** File description:
** World management
*/

#include "Game/world.h"
#include "Game/game.h"
#include <SFML/Graphics.h>
#include <SFML/Graphics/Sprite.h>
#include <stdlib.h>

int world_set_background(world_t *world, char *texture_path)
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
    return EXIT_SUCCESS;
}

world_t *create_world(void)
{
    world_t *world = malloc(sizeof(world_t));

    if (world == NULL)
        return NULL;
    world->background_sprite = NULL;
    world->background_texture = NULL;
    if (world_set_background(world, WORLD_BACKGROUND_PATH) == EXIT_FAILURE)
        return NULL;
    return world;
}
