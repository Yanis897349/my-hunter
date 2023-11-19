/*
** EPITECH PROJECT, 2023
** My Hunter
** File description:
** Game entry point
*/

#include "Game/game.h"
#include "Screen/screen.h"
#include "Events/event_handler.h"
#include <SFML/Window/Window.h>
#include <stdlib.h>

static int run_game_loop(game_t *game)
{
    while (sfRenderWindow_isOpen(game->screen->window)) {
        while (sfRenderWindow_pollEvent(game->screen->window,
            &game->game_event))
            event_handler(game);
        sfRenderWindow_clear(game->screen->window, sfBlack);
        sfRenderWindow_drawSprite(game->screen->window,
            game->world->background_sprite, NULL);
        sfRenderWindow_display(game->screen->window);
    }
    return EXIT_SUCCESS;
}

static void destroy_game(game_t *game)
{
    sfRenderWindow_destroy(game->screen->window);
    sfSprite_destroy(game->world->background_sprite);
    sfTexture_destroy(game->world->background_texture);
    free(game->screen);
    free(game);
}

int run_game(void)
{
    game_t *game = malloc(sizeof(game_t));

    if (game == NULL)
        return EXIT_FAILURE;
    game->screen = create_game_screen(DEFAULT_WINDOW_WIDTH,
        DEFAULT_WINDOW_HEIGHT);
    if (game->screen == NULL)
        return EXIT_FAILURE;
    game->world = create_world();
    if (game->world == NULL)
        return EXIT_FAILURE;
    if (run_game_loop(game) == EXIT_FAILURE)
        return EXIT_FAILURE;
    destroy_game(game);
    return EXIT_SUCCESS;
}
