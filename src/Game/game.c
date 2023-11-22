/*
** EPITECH PROJECT, 2023
** My Hunter
** File description:
** Game entry point
*/

#include "Game/game.h"
#include "Game/entity.h"
#include "Game/world.h"
#include "Screen/screen.h"
#include "Events/event_handler.h"
#include <SFML/Audio/Music.h>
#include <SFML/Window/Window.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

static int render_world(game_t *game)
{
    sfRenderWindow_drawSprite(game->screen->window,
        game->world->background_sprite, NULL);
    for (uint i = 0; i < game->world->entities_count; i++) {
        update_entity(game->world->entities[i], game->screen->window);
        sfRenderWindow_drawSprite(game->screen->window,
            game->world->entities[i]->sprite, NULL);
    }
    return EXIT_SUCCESS;
}

static int run_game_loop(game_t *game)
{
    entity_t *entity = create_entity(DEFAULT_ENTITY_TEXTURE_PATH,
        game->screen->window);

    add_entity_to_world(game->world, entity);
    while (sfRenderWindow_isOpen(game->screen->window)) {
        while (sfRenderWindow_pollEvent(game->screen->window,
            &game->game_event))
            event_handler(game);
        sfRenderWindow_clear(game->screen->window, sfBlack);
        render_world(game);
        sfRenderWindow_display(game->screen->window);
    }
    return EXIT_SUCCESS;
}

static void destroy_game(game_t *game)
{
    sfRenderWindow_destroy(game->screen->window);
    sfSprite_destroy(game->world->background_sprite);
    sfTexture_destroy(game->world->background_texture);
    for (uint i = 0; i < game->world->entities_count; i++)
        destroy_entity(game->world->entities[i]);
    sfMusic_destroy(game->world->music);
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
    game->world = create_world(game->screen->window);
    if (game->world == NULL)
        return EXIT_FAILURE;
    if (run_game_loop(game) == EXIT_FAILURE)
        return EXIT_FAILURE;
    destroy_game(game);
    return EXIT_SUCCESS;
}
