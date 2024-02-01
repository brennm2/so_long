/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:32:43 by bde-souz          #+#    #+#             */
/*   Updated: 2024/01/31 11:25:14 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	main(int ac, char **av)
{
	t_game	*game;
	int		fd;

	if (ac == 2 && check_map_name(av[1]) != -1)
	{
		game = init();
		fd = open (av[1], O_RDONLY);
		if (fd < 0)
		{
			ft_printf("Error\nProblem with opening the map file!\n");
			return (ft_quit_game(game));
		}
		game->map_name = av[1];
		read_map(av[1], game);
		if (map_check_validation (game) == -1
			|| check_map_characters(game) == -1)
			ft_quit_game(game);
		open_window(game);
	}
}
