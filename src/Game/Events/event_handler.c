/*
** EPITECH PROJECT, 2023
** My Hunter
** File description:
** Event handler
*/

#include "Game/entity.h"
#include "Game/game.h"
#include "Game/player.h"
#include "Game/world.h"
#include "Screen/screen.h"
#include <SFML/Audio/Sound.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Window/Event.h>
#include <SFML/Window/Mouse.h>
#include <stdio.h>
#include <stdlib.h>

static int is_hitbox_contains(sfFloatRect hitbox, int x, int y)
{
    return sfFloatRect_contains(&hitbox, x, y);
}

static void set_new_position(entity_t *entity, sfRenderWindow *window)
{
    sfVector2f new_position = {0, 0};
    int window_height = sfRenderWindow_getSize(window).y;

    new_position = (sfVector2f){0, rand() % (window_height -
        entity->rect.height)};
    entity_set_position(entity, new_position, window);
}

static void handle_mouse_click(sfMouseButtonEvent event, game_t *game)
{
    if (event.button != sfMouseLeft)
        return;
    for (uint i = 0; i < game->world->entities_count; i++) {
        if (is_hitbox_contains(game->world->entities[i]->hitbox, event.x,
            event.y)) {
            set_new_position(game->world->entities[i], game->screen->window);
            sfSound_play(game->world->entities[i]->hit_sound);
            player_add_score(game->player, 1);
            world_set_score(game->world, game->player->score);
            game->world->level->current_killed_entities++;
            world_new_level(game->world->level, game->screen->window,
                game->world);
        }
    }
}

static void handle_mouse_moved(game_t *game)
{
    if (game->player->crosshair_sprite == NULL)
        return;
    set_crosshair_position(game->player, game->screen->window);
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
        handle_mouse_moved(game);
        break;
    case sfEvtResized:
        handle_resize(event.size, game->screen->window);
        break;
    default:
        break;
    }
}
