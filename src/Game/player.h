/*
** EPITECH PROJECT, 2023
** My Hunter
** File description:
** Player management
*/

#pragma once
#include <SFML/Graphics/Types.h>
#define PLAYER_CROSSHAIR_TEXTURE_PATH "src/assets/player/crosshair.png"

typedef struct player_s {
    sfTexture *crosshair_texture;
    sfSprite *crosshair_sprite;
    int score;
} player_t;

void destroy_player(player_t *player);
void set_crosshair_position(player_t *player, sfRenderWindow *window);
void player_add_score(player_t *player, int score);
player_t *create_player(sfRenderWindow *window);
