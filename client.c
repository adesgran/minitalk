/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <adesgran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:47:07 by adesgran          #+#    #+#             */
/*   Updated: 2022/01/21 13:43:48 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

static int	send_char(char c, pid_t pid)
{
	int		i;

	i = 7;
	while (i >= 0)
	{
		usleep(500);
		if ((c >> i) & 1)
		{
			if (kill(pid, SIGUSR2) < 0)
			{
				ft_printf("ERROR, can't send signal to PID:%i\n", pid);
				return (1);
			}
		}
		if (!((c >> i) & 1))
		{
			if (kill(pid, SIGUSR1) < 0)
			{
				ft_printf("ERROR, can't send signal to PID:%i\n", pid);
				return (1);
			}
		}
		i--;
	}
	return (0);
}

static void	send_stdin(pid_t pid)
{
	char		*line;
	size_t		i;

	ft_printf("String to send : \n\n=====\n");
	line = ft_get_next_line(1);
	while (line)
	{
		i = 0;
		while (i < ft_strlen(line))
		{
			if (send_char(line[i], pid))
			{
				free(line);
				exit(2);
			}
			i++;
		}
		free(line);
		line = ft_get_next_line(1);
	}
	ft_printf("\n=====\n");
}

static void	send_str(pid_t pid, char *str)
{
	ft_printf("String to send : \n\n=====\n%s\n=====\n", str);
	while (*str)
	{
		if (send_char(*str, pid))
			exit (2);
		str++;
	}
}

int	main(int ac, char **av)
{
	pid_t	pid;
	char	*to_send;

	if (ac != 3)
	{
		ft_printf("Wrong number of arguments !\n");
		return (1);
	}
	pid = ft_atoi(av[1]);
	to_send = av[2];
	if (ft_strlen(to_send) == 1 && to_send[0] == '-')
		send_stdin(pid);
	else
		send_str(pid, to_send);
	send_char('\0', pid);
	ft_printf("\n\n-----\n\nMessage sent\n\n-----\n");
	return (0);
}
