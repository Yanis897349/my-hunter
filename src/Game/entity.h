/*
** EPITECH PROJECT, 2023
** My Hunter
** File description:
** Entity management
*/

#pragma once
#include <SFML/Graphics.h>

typedef struct entity_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position;
} entity_t;
