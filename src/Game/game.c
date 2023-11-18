/*
** EPITECH PROJECT, 2023
** My Hunter
** File description:
** Game entry point
*/

#include "Game/game.h"
#include "Events/event_handler.h"
#include <SFML/Window/Window.h>
#include <stdlib.h>

static int create_window(game_screen_t *game_screen)
{
    game_screen->window = sfRenderWindow_create(
        game_screen->screen_mode, WINDOW_NAME, sfResize | sfClose, NULL);
    if (game_screen->window == NULL)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

static game_screen_t *create_game_screen(int screen_width, int screen_height)
{
    game_screen_t *game_screen = malloc(sizeof(game_screen_t));

    if (game_screen == NULL)
        return NULL;
    game_screen->screen_mode.width = screen_width;
    game_screen->screen_mode.height = screen_height;
    game_screen->screen_mode.bitsPerPixel = SCREEN_PIXELS;
    if (create_window(game_screen) == EXIT_FAILURE)
        return NULL;
    return game_screen;
}

int run_game(void)
{
    game_t *game = malloc(sizeof(game_t));

    if (game == NULL)
        return EXIT_FAILURE;
    game->game_screen = create_game_screen(DEFAULT_SCREEN_WIDTH,
        DEFAULT_SCREEN_HEIGHT);
    if (game->game_screen == NULL)
        return EXIT_FAILURE;
    while (sfRenderWindow_isOpen(game->game_screen->window)) {
        while (sfRenderWindow_pollEvent(game->game_screen->window,
            &game->game_screen->game_event))
            event_handler(game);
        sfRenderWindow_clear(game->game_screen->window, sfBlack);
        sfRenderWindow_display(game->game_screen->window);
    }
    sfRenderWindow_destroy(game->game_screen->window);
    free(game->game_screen);
    return EXIT_SUCCESS;
}
