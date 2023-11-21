/*
** EPITECH PROJECT, 2023
** My Hunter
** File description:
** Entity management
*/

#include "Game/entity.h"
#include <stdlib.h>

void entity_set_position(entity_t *entity, sfVector2f position)
{
    sfSprite_setPosition(entity->sprite, position);
}

entity_t *create_entity(char *texture_path)
{
    entity_t *entity = malloc(sizeof(entity_t));

    entity->texture = sfTexture_createFromFile(texture_path, NULL);
    if (entity->texture == NULL)
        return NULL;
    entity->sprite = sfSprite_create();
    if (entity->sprite == NULL)
        return NULL;
    sfSprite_setTexture(entity->sprite, entity->texture, sfTrue);
    entity_set_position(entity,
        (sfVector2f) {DEFAULT_ENTITY_X_POSITION, DEFAULT_ENTITY_Y_POSITION});
    return entity;
}
