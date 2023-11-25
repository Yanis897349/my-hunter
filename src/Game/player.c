/*
** EPITECH PROJECT, 2023
** My Hunter
** File description:
** Player management
*/

#include "Game/player.h"
#include <stdlib.h>

void player_add_score(player_t *player, int score)
{
    player->score += score;
}

player_t *create_player(void)
{
    player_t *player = malloc(sizeof(player_t));

    if (!player)
        return NULL;
    player->score = 0;
    return player;
}
