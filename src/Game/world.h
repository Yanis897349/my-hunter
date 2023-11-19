/*
** EPITECH PROJECT, 2023
** My Hunter
** File description:
** World management
*/

#pragma once
#include "Game/entity.h"
#include <SFML/Graphics/Types.h>

typedef struct world_s {
    sfTexture *background_texture;
    sfSprite *background_sprite;
    entity_t **entities;
} world_t;
