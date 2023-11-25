/*
** EPITECH PROJECT, 2023
** my-hunter
** File description:
** save_manager
*/

#include "save_manager.h"
#include "include/my_math.h"
#include "include/my_io.h"
#include "include/my_strings.h"
#include "stdio.h"
#include <stdlib.h>

int get_highest_score(void)
{
    FILE *file = fopen(SAVE_FILE_PATH, "r");
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int highest_score = 0;

    if (!file)
        return 0;
    read = getline(&line, &len, file);
    if (read == -1)
        return 0;
    highest_score = my_getnbr(line);
    fclose(file);
    return highest_score;
}

int save_highest_score(int score)
{
    FILE *file = fopen(SAVE_FILE_PATH, "w");
    char str[33];

    if (!file)
        return EXIT_FAILURE;
    my_putnbr_base(score, BASE_10, str);
    fwrite(str , 1, my_strlen(str), file);
    fclose(file);
    return EXIT_SUCCESS;
}
