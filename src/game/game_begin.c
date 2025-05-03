#include "../../includes/so_long.h"

void display_images(t_game *game)
{
    game->floor_img = mlx_xpm_file_to_image(game->mlx, FLOOR_IMAGE,
                                            &game->img_width, &game->img_height);
    game->player_img = mlx_xpm_file_to_image(game->mlx, PLAYER_IMAGE,
                                             &game->img_width, &game->img_height);
    game->wall_img = mlx_xpm_file_to_image(game->mlx, WALL_IMAGE,
                                           &game->img_width, &game->img_height);
    game->collectible_img = mlx_xpm_file_to_image(game->mlx,
                                                  TROPHY_IMAGE, &game->img_width, &game->img_height);
    game->exit_img = mlx_xpm_file_to_image(game->mlx, Exit_IMAGE,
                                           &game->img_width, &game->img_height);
    if (!game->wall_img || !game->player_img || !game->floor_img || !game->collectible_img || !game->exit_img)
    {
        ft_printf("Failed to load one or more images\n");
        free_resources(game);
        exit(EXIT_FAILURE);
    }
}
void display_map_in_window(t_game *game, int i, int j)
{
    if (game->map[i][j] == '1')
        save_image_mlx(game, j, i, game->wall_img);
    else if (game->map[i][j] == 'P')
        save_image_mlx(game, j, i, game->player_img);
    else if (game->map[i][j] == 'E')
    {
        if (game->remaining_collectibles == 0)
            save_image_mlx(game, j, i, game->exit_img);
        else
            save_image_mlx(game, j, i, game->floor_img);
        if (game->player_x == j && game->player_y == i)
            save_image_mlx(game, j, i, game->player_img);
    }
    else if (game->map[i][j] == 'C')
        save_image_mlx(game, j, i, game->collectible_img);
    else if (game->map[i][j] == '0')
        save_image_mlx(game, j, i, game->floor_img);
}
void display_map(t_game *game)
{
    int i;
    int j;

    i = 0;
    while (i < game->map_height)
    {
        j = 0;
        while (j < game->map_width)
        {
            display_map_in_window(game, i, j);
            j++;
        }
        i++;
    }
}
void start_game(t_game *game)
{
    game->mlx = mlx_init();
    if (!game->mlx)
    {
        ft_printf("Mlx Initialize Failed\n");
        free_resources(game);
        exit(EXIT_FAILURE);
    }
    game->mlx_win = mlx_new_window(game->mlx, game->map_width * STANDARD_SIZE,
                                   game->map_height * STANDARD_SIZE, "ALBOOMAZ");
    if (!game->mlx_win)
    {
        ft_printf("Mlx window failed\n");
        free_resources(game);
        exit(EXIT_FAILURE);
    }
}