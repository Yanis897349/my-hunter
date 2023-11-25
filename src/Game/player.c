/*
** EPITECH PROJECT, 2023
** My Hunter
** File description:
** Player management
*/

#include "Game/player.h"
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <stdio.h>
#include <stdlib.h>

void player_add_score(player_t *player, int score)
{
    player->score += score;
}

void set_crosshair_position(player_t *player, sfRenderWindow *window)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfVector2u window_size = sfRenderWindow_getSize(window);
    sfVector2u crosshair_size = sfTexture_getSize(player->crosshair_texture);
    sfVector2f scale_factor = {0.05 , 0.05};

    sfSprite_setPosition(player->crosshair_sprite,
        (sfVector2f){mouse_pos.x - crosshair_size.x * scale_factor.x / 2,
            mouse_pos.y - crosshair_size.y * scale_factor.y / 2});
}

static int set_player_crosshair(player_t *player, char *texture_path,
    sfRenderWindow *window)
{
    player->crosshair_texture = sfTexture_createFromFile(texture_path, NULL);
    if (!player->crosshair_texture)
        return EXIT_FAILURE;
    player->crosshair_sprite = sfSprite_create();
    if (!player->crosshair_sprite)
        return EXIT_FAILURE;
    sfSprite_setTexture(player->crosshair_sprite, player->crosshair_texture,
        sfTrue);
    sfSprite_scale(player->crosshair_sprite, (sfVector2f){0.05, 0.05});
    set_crosshair_position(player, window);
    return EXIT_SUCCESS;
}

void destroy_player(player_t *player)
{
    sfTexture_destroy(player->crosshair_texture);
    sfSprite_destroy(player->crosshair_sprite);
    free(player);
}

player_t *create_player(sfRenderWindow *window)
{
    player_t *player = malloc(sizeof(player_t));

    if (!player)
        return NULL;
    player->score = 0;
    if (set_player_crosshair(player, PLAYER_CROSSHAIR_TEXTURE_PATH, window) ==
        EXIT_FAILURE)
        return NULL;
    return player;
}
