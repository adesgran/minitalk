/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <adesgran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:56:10 by adesgran          #+#    #+#             */
/*   Updated: 2022/01/03 18:40:41 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

static char	*add_buff(char *str, char buff[9])
{
	char	*res;

	if (str)
	{
		res = ft_strjoin(str, buff);
		free(str);
	}
	else
		res = ft_strdup(buff);
	return (res);
}
	
void	print_str(char c)
{
	static char	*str;
	static char	buff[9];
	static int	i;

	if (!i)
		i = 0;
	buff[i] = c;
	buff[i + 1] = '\0';
	if (i == 7 || !c)
		str = add_buff(str, buff);
	if (!c)
	{
		ft_printf("%s", str);
		i = 0;
		free(str);
		str = NULL;
	}
	i++;
	if (i == 8)
		i = 0;
}
