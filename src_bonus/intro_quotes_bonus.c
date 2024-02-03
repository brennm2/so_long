/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intro_quotes_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 20:25:40 by bde-souz          #+#    #+#             */
/*   Updated: 2024/02/03 10:48:35 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long_bonus.h"

void	intro_0(void)
{
	ft_printf("\n\n- Dallas: Alright, entry point.");
	ft_printf("Synchronize on my mark... Mark.\n\n");
	usleep(3000000);
	ft_printf("- Chains: Check!\n- Hoxton: Check!\n- Wolf:	  Check!\n\n");
	usleep(2000000);
	ft_printf("- Dallas: Remember: Stay low, stay dark, avoid guards ");
	ft_printf("and gunfire.\n");
	usleep(3000000);
	ft_printf("	  Here we go...\n");
	usleep(2000000);
}

void	intro_1(void)
{
	ft_printf("\n\n- Bain: Hoxton, ready!.\n\n");
	usleep(2000000);
	ft_printf("- Hoxton: I'm ready...\n\n");
	usleep(2000000);
	ft_printf("- Bain: Wolf, ready!.\n\n");
	usleep(2000000);
	ft_printf("- Wolf: Yeah, I'm ready.\n\n");
	usleep(2000000);
	ft_printf("- Bain: On your mark, Dallas!\n\n");
	usleep(2000000);
	ft_printf("- Dallas: Over there! I see the money. Let's do this.\n\n");
	usleep(4000000);
}

void	intro_2(void)
{
	ft_printf("\n\n- Bain: Now Hector tells me we need to hit the streets ");
	ft_printf("to get the money.\n\n");
	usleep(3000000);
	ft_printf("	Lucky for us, Someone in the Mendoza cartel gave up info\n");
	ft_printf("	that they're being investigated by the FBI.\n\n");
	usleep(3000000);
	ft_printf("	So all we have to do is hit the local FBI office to ");
	ft_printf("get our loot\n\n");
	usleep(3000000);
	ft_printf("	This is an FBI auxiliary office. The hornet's nest.\n");
	ft_printf("	For the love of God, stay quiet! First thing, get inside.\n\n");
	usleep(3000000);
	ft_printf("	And, yes, I know... Out of the frying pan, ");
	ft_printf("into the fire...\n\n");
	usleep(3000000);
}

void	intro_3(void)
{
	ft_printf("\n\n- Wolf: Guys... it fells like something's in the air... ");
	ft_printf("Money!\n\n");
	usleep(3000000);
	ft_printf("- PAYDAY Gang: *Laughs*.\n\n");
	usleep(2000000);
	ft_printf("- Bain: You're breaking up, can you hear me OK?.\n\n");
	usleep(3000000);
	ft_printf("- Dallas: Yeah, yeah, yeah... Run the plan!\n\n");
	usleep(3000000);
	ft_printf("- Bain: Right... Go to the ground floor, where they got the ");
	ft_printf("money, in fact.\n\n");
	usleep(3000000);
	ft_printf("	We're here to take what we left behind some days ago.\n");
	ft_printf("	This should be quick and clean, avoid guards and gunfire.\n\n");
	usleep(3000000);
	ft_printf("	I'll pick you up from the sewers when we're done.\n\n");
	usleep(3000000);
}

void	intro_quotes(void)
{
	int		intro_number;
	time_t	t;

	srand((unsigned) time(&t));
	intro_number = rand() % 4;
	if (intro_number == 0)
		intro_0();
	else if (intro_number == 1)
		intro_1();
	else if (intro_number == 2)
		intro_2();
	else if (intro_number == 3)
		intro_3();
}
