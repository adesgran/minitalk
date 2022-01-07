/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <adesgran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:48:27 by adesgran          #+#    #+#             */
/*   Updated: 2022/01/08 00:27:08 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

static void	read_input(int sig)
{
	static char	c;
	static int	i;

	if (!i)
		i = 8;
	if (!c)
		c = 0x00;
	if (sig == SIGUSR2)
		c += (1 << (i - 1));
	i--;
	if (!i)
	{
		printf("%c", c);
		if (!c)
			printf("\n");
		c = 0x00;
	}
}

static void	handle_sigstop(int sig)
{
	ft_printf("Stop Server\n");
	(void)sig;
}

int	main(void)
{
	signal(SIGSTOP, &handle_sigstop);
	signal(SIGUSR1, read_input);
	signal(SIGUSR2, read_input);
	ft_printf("PID : %d\n", getpid());
	while (1)
	{
		usleep(1000000);
	}
	return (0);
}
