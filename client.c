/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <adesgran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:47:07 by adesgran          #+#    #+#             */
/*   Updated: 2022/01/03 16:20:10 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

void	handle_sigout(int sig)
{
	ft_printf("Signal out : %d\n:", sig);
	if (sig == 2)
	{
		ft_printf("Exit !\n");
		exit(0);
	}
}

int	main(int ac, char **av)
{
	pid_t	pid;

	if (ac < 2)
		return (1);
	pid = ft_atoi(av[1]);
	signal(ft_atoi(av[2]), handle_sigout);
	kill(pid, ft_atoi(av[2]));
		
	(void)ac;
	(void)av;
	return (0);
}
