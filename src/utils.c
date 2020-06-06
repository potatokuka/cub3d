/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: greed <greed@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/24 13:58:53 by greed         #+#    #+#                 */
/*   Updated: 2020/05/24 22:57:09 by greed         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool		valid_file(char *str)
{
	int		i;
	int		j;
	char	*check;

	check = ".cub";
	i = ft_strlen_lib(str) - 1;
	j = ft_strlen_lib(check) - 1;
	while (str[i] && j >= 0)
	{
		if (str[i] != check[j])
			return (false);
		j--;
		i--;
	}
	return (true);
}

int			trim_help(char *line)
{
	int		i;
	int		x;
	int		len;

	i = 0;
	x = 0;
	len = 0;
	while (line[i])
	{
		if (line[i] == ' ')
		{
			x++;
		}
		i++;
	}
	len = (i - x) + 1;
	return (len);
}

char		*ft_trim_space(char *line)
{
	char	*str;
	int		i;
	int		x;
	int		len;

	i = 0;
	x = 0;
	len = 0;
	len = trim_help(line);
	str = (char *)malloc(sizeof(char) * len);
	while (line[i])
	{
		if (line[i] != ' ')
		{
			str[x] = line[i];
			x++;
		}
		i++;
	}
	return (str);
}
