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


void	spawn_cloaker (t_game *game)
{
	int i;
	int	x;

	i = 0;
	x = 0;

	while (game->cloaker_position)
	{
		
		ft_printf("cloaker: %d\n", game->cloaker_position[i]);
		i++;
	}

}
