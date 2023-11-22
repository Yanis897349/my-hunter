/*
** EPITECH PROJECT, 2023
** My Hunter
** File description:
** Window management
*/

#pragma once
#include <SFML/Graphics.h>
#define WINDOW_NAME "My Hunter"
#define DEFAULT_WINDOW_WIDTH 800
#define DEFAULT_WINDOW_HEIGHT 600
#define MINIMUM_WINDOW_WIDTH 800
#define MINIMUM_WINDOW_HEIGHT 600
#define MAXIMUM_WINDOW_WIDTH 1920
#define MAXIMUM_WINDOW_HEIGHT 1080
#define DEFAULT_WINDOW_PIXELS 32
#define DEFAULT_WINDOW_FPS 60

typedef struct screen_s {
    sfRenderWindow *window;
    sfVideoMode window_mode;
} screen_t;

screen_t *create_game_screen(int window_width, int window_height);
