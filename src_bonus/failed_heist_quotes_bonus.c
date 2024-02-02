/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   failed_heist_quotes_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:20:16 by bde-souz          #+#    #+#             */
/*   Updated: 2024/02/02 18:06:16 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long_bonus.h"

void	end_failed_0(void)
{
	ft_printf("\n\n- Bain: WHAT?! No! This isn't happening!\n");
	usleep(3000000);
	ft_printf("	I- I... I just didn't know that the cops had this");
	ft_printf(" kind of firepower.\n");
	usleep(3000000);
	ft_printf("	I'll pull some strings so you'll be out of ");
	ft_printf("prison in no time.\n");
	usleep(3000000);
	ft_printf("	I'm sorry, I'm sorry! There were some things I couldn't ");
	ft_printf("predict.\n\n");
	usleep(3000000);
}

void	end_failed_1(void)
{
	ft_printf("\n\n- Bain: No... no, NO, NO!\n");
	usleep(3000000);
	ft_printf("	This was not supposed to happen!\n");
	usleep(3000000);
	ft_printf("	I know you guys are the best! The error must be in my end.\n");
	usleep(3000000);
	ft_printf("	Sorry guys, I messed up.\n");
	usleep(3000000);
	ft_printf("	With the connections that I have, you will be out of prison");
	ft_printf(" within a week.\n	One way or another...\n\n");
	usleep(3000000);
}

void	end_failed_2(void)
{
	ft_printf("\n\n- Bain: No! We were so god-damn close!\n");
	usleep(3000000);
	ft_printf("	I didn't give the police enough credit, I guess...\n");
	ft_printf("	Sorry, guys!\n");
	usleep(3000000);
	ft_printf("	Take some time to collect yourselves and come back stronger");
	ft_printf(" than ever.\n");
	usleep(3000000);
	ft_printf("	I'll start working on the prison break plan right away!\n\n");
	usleep(3000000);
}

void	end_failed_3(void)
{
	ft_printf("\n\n- Bain: I can't believe it, what a mess!\n");
	usleep(3000000);
	ft_printf("	I checked EVERYTHING! How did it go down like this?\n");
	usleep(3000000);
	ft_printf("	Must have been my plan! Sorry, people, I messed up!\n");
	usleep(3000000);
	ft_printf("	Don't worry, I know some people, you'll be out fast.\n\n");
	usleep(3000000);
}

void	failed_heist_quotes_bonus(void)
{
	int end_number;
	time_t t;

	srand((unsigned) time(&t));
	end_number = rand() % 4;

	if (end_number == 0)
		end_failed_0();
	else if(end_number == 1)
		end_failed_1();
	else if(end_number == 2)
		end_failed_2();
	else if(end_number == 3)
		end_failed_3();
}