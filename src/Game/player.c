/*
** EPITECH PROJECT, 2023
** My Hunter
** File description:
** Player management
*/

#include "Game/player.h"

void player_add_score(player_t *player, int score)
{
    player->score += score;
}
