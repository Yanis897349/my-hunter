/*
** EPITECH PROJECT, 2023
** my-hunter
** File description:
** level
*/

#pragma once
#include <sys/types.h>

typedef struct level_s {
    unsigned int level;
    unsigned int entities_to_spawn;
    unsigned int entities_to_kill;
    unsigned int current_killed_entities;
} level_t;

void update_level(level_t *level, uint entities_to_spawn,
    uint entities_to_kill, uint current_killed_entities);
level_t *create_level(uint level, uint entities_to_spawn,
    uint entities_to_kill);
