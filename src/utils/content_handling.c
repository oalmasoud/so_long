#include "../../includes/so_long.h"

void map_walls(t_game *game)
{
    int i;

    i = 0;
    while (i < game->map_width)
    {
        if (game->map[0][i] != '1' || game->map[game->map_height - 1][i] != '1')
        {
            ft_printf("Invalid walls it should be presented with 1\n");
            free_resources(game);
            exit(EXIT_FAILURE);
        }
        i++;
    }
    i = 0;
    while (i < game->map_height)
    {
        if (game->map[i][0] != '1' || game->map[i][game->map_width - 1] != '1')
        {
            ft_printf("Invalid walls it should be presented with 1\n");
            free_resources(game);
            exit(EXIT_FAILURE);
        }
        i++;
    }
}
void map_trophies(t_game *game)
{
    int counter;
    int i;
    int j;

    counter = 0;
    i = 0;
    j = 0;
    while (game->map[i])
    {
        j = 0;
        while (game->map[i][j])
        {
            if (game->map[i][j] == 'C')
                counter++;
            j++;
        }
        i++;
    }
    if (counter == 0)
    {
        printf("Invalid trophies atleast should be one\n");
        free_resources(game);
        exit(EXIT_FAILURE);
    }
    game->remaining_collectibles = counter;
}
void map_player(t_game *game)
{
    int counter;
    int i;
    int j;

    counter = 0;
    i = 0;
    j = 0;
    while (game->map[i])
    {
        j = 0;
        while (game->map[i][j])
        {
            if (game->map[i][j] == 'P')
                counter++;
            j++;
        }
        i++;
    }
    if (counter != 1)
    {
        printf("Invalid map: there should be exactly one player.\n");
        free_resources(game);
        exit(EXIT_FAILURE);
    }
}
void map_exit(t_game *game)
{
    int counter;
    int i;
    int j;

    counter = 0;
    i = 0;
    j = 0;
    while (game->map[i])
    {
        j = 0;
        while (game->map[i][j])
        {
            if (game->map[i][j] == 'E')
                counter++;
            j++;
        }
        i++;
    }
    if (counter != 1)
    {
        printf("Invalid map: there should be exactly one exit.\n");
        free_resources(game);
        exit(EXIT_FAILURE);
    }
}