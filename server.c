/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <adesgran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:48:27 by adesgran          #+#    #+#             */
/*   Updated: 2022/01/06 17:25:45 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

static void	print_char(char *str)
{
	char		c;
	int			i;

	i = 0;
	c = 0;
	while (i < 8)
	{
		c *= 2;
		if (str[i] == SIGUSR2)
			c += 1;
		i++;
	}
	printf("%c",c);
	//print_str(c);
}

static void	read_input(char c)
{
	static int	i;
	static char	*str;

	if (!i || i == 8)
		i = 0;
	if (!str)
	{
		str = malloc(sizeof(char) * 8);
		if (!str)
			return ;
	}
	str[i] = c;
	if (i == 7)
	{
		print_char(str);
		free(str);
		str = NULL;
	}
	i++;
}

static void	handle_sigstop(int sig)
{
	ft_printf("Stop Server\n");
	(void)sig;
}

static void	handle_sigusr1(int sig)
{
	read_input((char)sig);
}

static void	handle_sigusr2(int sig)
{
	read_input((char)sig);
}

int	main(void)
{
	signal(SIGSTOP, &handle_sigstop);
	signal(SIGUSR1, handle_sigusr1);
	signal(SIGUSR2, handle_sigusr2);
	ft_printf("PID : %d\n", getpid());
	while (1)
	{
		usleep(1000000);
	}
	return (0);
}
