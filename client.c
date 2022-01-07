/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <adesgran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:47:07 by adesgran          #+#    #+#             */
/*   Updated: 2022/01/08 00:29:04 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

static void	send_char(char c, pid_t pid)
{
	int		i;

	i = 7;
	while (i >= 0)
	{
		usleep(1000);
		if ((c >> i) & 1)
			if (kill(pid, SIGUSR2) < 0)
				ft_printf("ERROR\n");
		if (!((c >> i) & 1))
			if (kill(pid, SIGUSR1) < 0)
				ft_printf("ERROR\n");
		i--;
	}
}

int	main(int ac, char **av)
{
	pid_t	pid;
	char	*to_send;

	if (ac < 2)
		return (1);
	ft_printf("String to send : \n\t%s\n", av[2]);
	pid = ft_atoi(av[1]);
	to_send = av[2];
	while (*to_send)
	{
		send_char(*to_send, pid);
		to_send++;
	}
	send_char('\0', pid);
	ft_printf("\nMessage sent\n");
	(void)ac;
	(void)av;
	return (0);
}
