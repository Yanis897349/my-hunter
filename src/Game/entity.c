/*
** EPITECH PROJECT, 2023
** My Hunter
** File description:
** Entity management
*/

#include "Game/entity.h"

void entity_set_position(entity_t *entity, sfVector2f position)
{
    sfSprite_setPosition(entity->sprite, position);
}
