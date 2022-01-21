/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <adesgran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:48:27 by adesgran          #+#    #+#             */
/*   Updated: 2022/01/21 11:45:32 by adesgran         ###   ########.fr       */
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
		print_str(c);
		c = 0x00;
	}
}

int	main(void)
{
	signal(SIGUSR1, read_input);
	signal(SIGUSR2, read_input);
	ft_printf("PID : %d\n", getpid());
	while (1)
		sleep(1);
	return (0);
}
