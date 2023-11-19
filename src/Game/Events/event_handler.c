/*
** EPITECH PROJECT, 2023
** My Hunter
** File description:
** Event handler
*/

#include "Game/game.h"

void event_handler(game_t *game)
{
    sfEvent event = game->game_event;

    if (event.type == sfEvtClosed)
        sfRenderWindow_close(game->screen->window);
}
