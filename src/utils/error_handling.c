#include "../../includes/so_long.h"

void width_identical(t_game *game)
{
    int i;
    int j;

    i = 0;
    while (game->map[i])
    {
        j = 0;
        while (game->map[i][j])
            j++;

        if (j != game->map_width)
        {
            ft_printf("Invalid map width\n");
            free_resources(game);
            exit(EXIT_FAILURE);
        }
        i++;
    }
}
void dimension_check(t_game *game)
{
    int width;
    int i;

    width = ft_strlen(game->map[0]);
    game->map_width = width;

    i = 0;
    while (game->map[i])
        i++;
    game->map_height = i;
}
void exit_error(char *message, t_game *game, int fd, char *temp)
{
    ft_printf("%s\n", message);
    close(fd);
    free(temp);
    free_resources(game);
    exit(EXIT_FAILURE);
}
void exit_error_and_close_fd(char *message, int fd)
{
    ft_printf("%s\n", message);
    close(fd);
    exit(EXIT_FAILURE);
}
void file_name_checker(char *map_f)
{
    int i;

    i = 0;
    while (map_f[i])
        i++;
    if (map_f[i - 4] != '.' || map_f[i - 3] != 'b' || map_f[i - 2] != 'e' || map_f[i - 1] != 'r')
    {
        ft_printf("Error: Incorrect File Name\n");
        exit(EXIT_FAILURE);
    }
}