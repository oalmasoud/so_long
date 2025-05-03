#include "../includes/so_long.h"

int main(int argc, char *argv[])
{
	t_game game;

	if (argc != 2)
	{
		ft_printf("Invalid number of arguments\n");
		exit(EXIT_FAILURE);
	}
	ft_bzero(&game, sizeof(t_game));
	map_validation(argv[1], &game);
	dimension_check(&game);
	main_check(&game);
	able_to_play(&game);
	start_game(&game);
	display_images(&game);
	mlx_hook(game.mlx_win, 17, 0, close_window, &game);
	mlx_hook(game.mlx_win, KeyPress, KeyRelease, handle_keypress, &game);
	display_map(&game);
	mlx_loop(game.mlx);
	free_resources(&game);
	return (EXIT_SUCCESS);

	return 0;
}