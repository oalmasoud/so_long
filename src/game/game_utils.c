#include "../../includes/so_long.h"

int close_window(t_game *game)
{
    free_resources(game);
    exit(EXIT_SUCCESS);
    return (0);
}
void able_to_play(t_game *game)
{
    if (!can_player_complete_game(game))
    {
        ft_printf("No path to win the game\n");
        free_resources(game);
        exit(EXIT_SUCCESS);
    }
}
void	save_image_mlx(t_game *game, int x, int y, void *img)
{
	if (img)
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, img, x * WIDTH_SIZE, y
			* HEIGHT_SIZE);
	}
}
