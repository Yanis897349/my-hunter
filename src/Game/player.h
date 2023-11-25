/*
** EPITECH PROJECT, 2023
** My Hunter
** File description:
** Player management
*/

#pragma once

typedef struct player_s {
    int score;
} player_t;

void player_add_score(player_t *player, int score);
player_t *create_player(void);
