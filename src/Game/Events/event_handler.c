/*
** EPITECH PROJECT, 2023
** My Hunter
** File description:
** Event handler
*/

#include "Game/entity.h"
#include "Game/game.h"
#include "Screen/screen.h"
#include <SFML/Graphics/Rect.h>
#include <SFML/Window/Event.h>
#include <SFML/Window/Mouse.h>
#include <stdio.h>
#include <stdlib.h>

static void handle_mouse_click(sfMouseButtonEvent event, game_t *game)
{
    sfVector2f new_position = {0, 0};
    int window_height = game->screen->window_mode.height;

    if (event.button != sfMouseLeft)
        return;
    for (uint i = 0; i < game->world->entities_count; i++) {
        if (sfFloatRect_contains(&game->world->entities[i]->hitbox,
            event.x, event.y)) {
            new_position = (sfVector2f){0, rand() % (window_height -
                    game->world->entities[i]->rect.height)};
            entity_set_position(game->world->entities[i], new_position);
        }
    }
}

static void handle_mouse_moved(sfMouseMoveEvent event, game_t *game)
{
    return;
}

static void handle_resize(sfSizeEvent event, sfRenderWindow *window)
{
    if (event.width < MINIMUM_WINDOW_WIDTH) {
        sfRenderWindow_setSize(window,
            (sfVector2u){MINIMUM_WINDOW_WIDTH, event.height});
    }
    if (event.height < MINIMUM_WINDOW_HEIGHT) {
        sfRenderWindow_setSize(window,
            (sfVector2u){event.width, MINIMUM_WINDOW_HEIGHT});
    }
    if (event.width > MAXIMUM_WINDOW_WIDTH) {
        sfRenderWindow_setSize(window,
            (sfVector2u){MAXIMUM_WINDOW_WIDTH, event.height});
    }
    if (event.height > MAXIMUM_WINDOW_HEIGHT) {
        sfRenderWindow_setSize(window,
            (sfVector2u){event.width, MAXIMUM_WINDOW_HEIGHT});
    }
}

void event_handler(game_t *game)
{
    sfEvent event = game->game_event;

    switch (event.type) {
    case sfEvtClosed:
        sfRenderWindow_close(game->screen->window);
        break;
    case sfEvtMouseButtonPressed:
        handle_mouse_click(event.mouseButton, game);
        break;
    case sfEvtMouseMoved:
        handle_mouse_moved(event.mouseMove, game);
        break;
    case sfEvtResized:
        handle_resize(event.size, game->screen->window);
        break;
    default:
        break;
    }
}
