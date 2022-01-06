/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <adesgran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:56:10 by adesgran          #+#    #+#             */
/*   Updated: 2022/01/06 16:20:35 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

/*static char	*add_buff(char *str, char buff[9])
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
	i++;
	if (!c)
	{
		ft_printf("%s", str);
		i = 0;
		free(str);
		str = NULL;
	}
	if (i == 8)
		i = 0;
}*/

void	print_str(char c)
{
	static char str[9999];
	static int i;

	if (!i)
		i = 0;
	if (i < 9999)
	{
		str[i] = c;
		str[i + 1] = '\0';
	}
	i++;
	if (!c || i == 9999)
	{
		ft_printf("%s", str);
		i = 0;
		str[0] = '\0';
	}
}
