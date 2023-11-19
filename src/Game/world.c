/*
** EPITECH PROJECT, 2023
** My Hunter
** File description:
** World management
*/

#include "Game/world.h"

void world_set_background(world_t *world, sfTexture *texture)
{
    sfSprite_setTexture(world->background_sprite, texture, sfTrue);
}
