/*
** EPITECH PROJECT, 2023
** My Hunter
** File description:
** Game entry point
*/

#pragma once
#include <SFML/Graphics.h>

#define WINDOW_NAME "My Hunter"
#define DEFAULT_SCREEN_WIDTH 800
#define DEFAULT_SCREEN_HEIGHT 600
#define SCREEN_PIXELS 32

typedef struct game_screen_s {
    sfRenderWindow *window;
    sfVideoMode screen_mode;
    sfEvent game_event;
} game_screen_t;

typedef struct game_s {
    game_screen_t *game_screen;
} game_t;

int run_game(void);
