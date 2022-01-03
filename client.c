/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <adesgran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:47:07 by adesgran          #+#    #+#             */
/*   Updated: 2022/01/03 17:33:57 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

static char	*convert_base(char c)
{
	int		i;
	char	*res;

	res = malloc(sizeof(char) * 8);
	i = 8;
	while (i)
	{
		if (c % 2)
			res[i - 1] = SIGUSR2;
		else
			res[i - 1] = SIGUSR1;
		c = c / 2;
		i--;
	}
	return (res);
}

static void send_char(char c, pid_t pid)
{
	char	*str;
	int		i;

	str = convert_base(c);
	i = 0;
	while (i < 8)
	{
		kill(pid, str[i]);
		i++;
	}
	free(str);
}

int	main(int ac, char **av)
{
	pid_t	pid;
	char	*to_send;

	if (ac < 2)
		return (1);
	pid = ft_atoi(av[1]);
	to_send = av[2];
	while (*to_send)
	{
		send_char(*to_send, pid);
		to_send++;
	}
	send_char('\n', pid);
	(void)ac;
	(void)av;
	return (0);
}
