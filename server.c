/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <adesgran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:48:27 by adesgran          #+#    #+#             */
/*   Updated: 2022/01/03 16:00:13 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

void	handle_sigint(int sig)
{
	ft_printf("Signal : %d\n:", sig);
	if (sig == 2)
	{
		ft_printf("Exit !\n");
		exit(0);
	}
}

int	main(void)
{
	signal(SIGINT, handle_sigint);
	ft_printf("PID : %d\n", getpid());
	for (int i = 0; i < 10; i++)
	{
		ft_printf("Waiting for Signal..\n");
		sleep(5);
	}
	return (0);
}
