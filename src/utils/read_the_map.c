#include "../../includes/so_long.h"

void read_fd(char *map_file, int *fd, char **temp)
{
    *fd = open(map_file, O_RDONLY);
    if (*fd == -1)
    {
        ft_printf("Failed to open\n");
        exit(EXIT_FAILURE);
    }
    *temp = ft_strdup("");
    if (!temp)
    {
        ft_printf("Memory allocation failed\n");
        close(*fd);
        exit(EXIT_FAILURE);
    }
}
void check_map_line(t_game *game, char *temp, int fd)
{
    int i = 0;
    while (temp[i] != '\0')
    {
        if (temp[i] == '\n' && (i == 0 || temp[i - 1] == '\n'))
            exit_error("The map is invalid (empty lines founded)", game, fd, temp);
        i++;
    }
}
void map_checker(t_game *game, char *temp, int fd)
{

    if (temp[0] == '\0' || !temp)
        exit_error("empty map", game, fd, temp);
    check_map_line(game, temp, fd);
    game->map = ft_split(temp, '\n');
    free(temp);
    close(fd);
    if (!game->map)
    {
        ft_printf("Memory allocation failed\n");
        free_resources(game);
        exit(EXIT_FAILURE);
    }
}
void map_validation(char *map_f, t_game *game)
{
    int fd;
    char *line;
    char *temp;
    char *new_temp;

    file_name_checker(map_f);
    read_fd(map_f, &fd, &temp);
    line = get_next_line(fd);
    while (line)
    {
        new_temp = ft_strjoin(temp, line);
        if (!new_temp)
        {
            free(temp);
            free(line);
            exit_error_and_close_fd("Memory allocation failed", fd);
        }
        free(temp);
        free(line);
        temp = new_temp;
        if (!temp)
            exit_error_and_close_fd("Memory allocation failed", fd);
        line = get_next_line(fd);
    }
    map_checker(game, temp, fd);
}