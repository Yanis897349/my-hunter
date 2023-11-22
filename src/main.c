/*
** EPITECH PROJECT, 2023
** Project
** File description:
** Project description
*/

#include "Game/game.h"
#include "include/my_std.h"
#include "include/my_strings.h"
#include "include/my_io.h"
#include <stdlib.h>
#include <time.h>

static void display_help(void)
{
    my_putstr("USAGE\n");
    my_putstr("    ./my_hunter [-i]\n\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("    Small video game based on the rules of Duck Hunt.\n");
    my_putstr("    The game is pokemon-themed.\n");
    my_putstr("    You have to click on the pokemons to shoot them.\n");
    my_putstr("    You have 3 lives, except if you provide the -i flag.");
}

int main(int ac, char **av)
{
    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        display_help();
        return EXIT_SUCCESS;
    }
    srand(time(NULL));
    if (run_game() == EXIT_FAILURE)
        return EXIT_ERROR;
    return EXIT_SUCCESS;
}
