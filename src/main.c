/*
** EPITECH PROJECT, 2023
** Project
** File description:
** Project description
*/

#include "Game/game.h"
#include "include/my_std.h"
#include <stdlib.h>
#include <time.h>

int main(void)
{
    srand(time(NULL));
    if (run_game() == EXIT_FAILURE)
        return EXIT_ERROR;
    return EXIT_SUCCESS;
}
