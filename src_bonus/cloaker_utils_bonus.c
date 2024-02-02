#include "../header/so_long_bonus.h"

void	check_cloaker_number(t_game *game)
{
	int	x;
	int	y;
	y = 0;
	while (game->rows > y)
	{
		x = 0;
		while (game->columns > x)
		{
			if (game->map[y][x] == 'X')
				game->cloaker_number += 1;
			x++;
		}
		y++;
	}
}

void	end_game_takedown(t_game *game)
{
	failed_heist_quotes_bonus();
	ft_quit_game(game);
}

void	check_cloaker_takedown(t_game *game, int i)
{
	if (game->cloaker_position[i].y == game->player_position.y 
		&& game->cloaker_position[i].x == game->player_position.x)
	{
		put_texture(game, PLAYER_DEAD, game->cloaker_position[i].y * SIZE,
			game->cloaker_position[i].x * SIZE);
		put_texture(game, PLAYER_DEAD, game->cloaker_position[i].y * SIZE,
			game->cloaker_position[i].x * SIZE);
		end_game_takedown(game);
	}
}
