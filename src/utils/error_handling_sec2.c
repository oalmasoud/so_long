#include "../../includes/so_long.h"

void map_content(t_game *game)
{
    int i;
    int j;

    i = 0;
    while (game->map[i])
    {
        j = 0;
        while (game->map[i][j])
        {
            if (game->map[i][j] != '0' && game->map[i][j] != '1' && game->map[i][j] != 'C' && game->map[i][j] != 'E' && game->map[i][j] != 'P')
            {
                ft_printf("invalid map content\n");
                free_resources(game);
                exit(EXIT_FAILURE);
            }
            j++;
        }
        i++;
    }
}
void player_position(t_game *game)
{
    int i;
    int j;

    i = 0;
    while (game->map[i])
    {
        j = 0;
        while (game->map[i][j])
        {
            if (game->map[i][j] == 'P')
            {
                game->player_x = j;
                game->player_y = i;
                return;
            }
            j++;
        }
        i++;
    }
}
void main_check(t_game *game)
{
    width_identical(game);
    map_content(game);
    map_walls(game);
    map_trophies(game);
    map_player(game);
    map_exit(game);
    player_position(game);
}