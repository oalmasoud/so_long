#ifndef SO_LONG_H
#define SO_LONG_H

#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <X11/X.h>


/*Images path*/
#define PLAYER_IMAGE "assets/images/player.xpm"
#define Exit_IMAGE "assets/images/exit.xpm"
#define FLOOR_IMAGE "assets/images/floor.xpm"
#define TROPHY_IMAGE "assets/images/trophy.xpm"
#define WALL_IMAGE "assets/images/wall.xpm"
#define STANDARD_SIZE 50
#define WIDTH_SIZE STANDARD_SIZE
#define HEIGHT_SIZE STANDARD_SIZE

/*Game Structure*/

typedef struct s_game
{
    void *mlx;
    void *mlx_win;
    int map_width;
    int map_height;
    char **map;
    int img_width;
    int img_height;
    int player_x;
    int player_y;
    int player_moves;
    void *player_img;
    void *wall_img;
    void *exit_img;
    void *floor_img;
    void *collectible_img;
    int remaining_collectibles;
} t_game;

enum		e_game
{
	W = 'w',
	S = 's',
	A = 'a',
	D = 'd',
	LEFT = 65361,
	RIGHT = 65363,
	UP = 65362,
	DOWN = 65364,
	ESC = 65307,
	Q = 113,
};

void map_validation(char *map_f, t_game *game);
void file_name_checker(char *map_f);
void exit_error(char *message, t_game *game, int fd, char *tmp);
void exit_error_and_close_fd(char *message, int fd);
void free_resources(t_game *game);
void dimension_check(t_game *game);
void main_check(t_game *game);
void width_identical(t_game *game);
void map_walls(t_game *game);
void map_trophies(t_game *game);
void map_player(t_game *game);
void map_exit(t_game *game);
void able_to_play(t_game *game);
bool can_player_complete_game(t_game *game);
void start_game(t_game *game);
void display_images(t_game *game);
void display_map(t_game *game);
int close_window(t_game *game);
int handle_keypress(int keycode, t_game *game);
void save_image_mlx(t_game *game, int x, int y, void *img);
void player_control(t_game *game, int x, int y);

#endif
