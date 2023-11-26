/*
** EPITECH PROJECT, 2023
** my-hunter
** File description:
** level
*/

#include "Game/level.h"
#include "Game/game.h"
#include <SFML/Graphics/Types.h>
#include <stdlib.h>
#include <sys/types.h>

void update_level(level_t *level, uint entities_to_spawn,
    uint entities_to_kill, uint current_killed_entities)
{
    level->entities_to_spawn = entities_to_spawn;
    level->entities_to_kill = entities_to_kill;
    level->current_killed_entities = current_killed_entities;
}

level_t *create_level(uint level, uint entities_to_spawn,
    uint entities_to_kill)
{
    level_t *level_struct = malloc(sizeof(level_t));

    if (!level_struct)
        return NULL;
    level_struct->level = level;
    level_struct->entities_to_spawn = entities_to_spawn;
    level_struct->entities_to_kill = entities_to_kill;
    level_struct->current_killed_entities = 0;
    return level_struct;
}
