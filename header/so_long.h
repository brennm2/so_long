/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:15:46 by bde-souz          #+#    #+#             */
/*   Updated: 2024/01/31 11:25:51 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libs/Libft/libft.h"
# include "../libs/minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define SIZE 64
# define FLOOR "./textures/FLOOR.xpm"
# define PLAYER "./textures/PLAYER.xpm"
# define EXIT_PLAYER "./textures/EXIT_PLAYER.xpm"
# define EXIT "./textures/EXIT.xpm"

typedef struct s_point
{
	int		x;
	int		y;
}			t_point;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_img;

typedef struct s_game
{
	char	**map;
	char	**map_copy;
	char	*map_name;
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;

	t_point	player_position;
	t_point	coordinates;
	t_point	img_size;

	int		moves;
	int		rows;
	int		columns;
	int		collect;
	int		coin_bag;
	int		collect_check;
	int		exit_check;

}			t_game;

// -- UTILS/MAP_CHECK.C -- //
int			check_map_name(char *map_name);
int			map_check_validation(t_game *game);
int			check_for_exit_and_player(t_game *game);
int			check_for_collect(t_game *game);

// -- UTILS/MAP_CHECK_2.C -- //
int			check_for_first_and_last_line(t_game *game);
int			check_for_columns_wall(t_game *game);
int			check_map_characters(t_game *game);

// -- UTILS/MAP_PATH.C -- //
int			check_player_position(t_game *game);
void		map_path(char *map_name, t_game *game);

// -- UTILS/MAP_UTILS -- //
void		free_map_copy(char **map, t_game *game);
int			count_lines(char *map_name);
void		read_map(char *map_name, t_game *game);
void		fill_map(int fd, t_game *game);
int			map_columns_len(char *map_row);

// -- UTILS/UTILS.C -- //
int			ft_quit_game(t_game *game);
void		free_all(t_game *game);
void		free_almost_all(t_game *game);

// -- SRC/INIT.C -- //
t_game		*init(void);

// -- SRC/OPEN_WINDOW.C -- //
void		display_window(t_game *game);
void		open_window(t_game *game);

// -- SRC/RENDER_GAME.C -- //
void		render_map(t_game *game);
void		render_textures(t_game *game, int y, int x);
void		put_texture(t_game *game, char *texture_dir, int y, int x);

// -- MOVEMENTS/KEY_HANDLER.C -- //
int			key_handler(int key, t_game *game);
void		test_move_up(t_game *game);
void		test_move_down(t_game *game);
void		test_move_left(t_game *game);
void		test_move_right(t_game *game);

// -- MOVEMENTS/MOVES.C -- //
void		move_up(t_game *game);
void		move_down(t_game *game);
void		move_right(t_game *game);
void		move_left(t_game *game);

#endif
