/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wall_col2.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: greed <greed@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/07 22:12:35 by greed         #+#    #+#                 */
/*   Updated: 2020/07/07 22:58:26 by greed         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		len_start(char *str)
{
	int		len;
	int		i;
	int		start;

	i = 0;
	start = 0;
	len = ft_strlen(str);
	if (!len)
		return (-1);
	while (str[i])
	{
		if (str[i] == 'O')
		{
			start = i;
			return (start);
		}
		i++;
	}
	return (start);
}

static int		height_start(char **map, int max_height, int x)
{
	int		i;
	int		start;

	start = 0;
	i = 0;
	while (i < max_height)
	{
		if ((ft_strlen(map[i]) >= (size_t)x) && map[i][x] == 'O')
		{
			start = i;
			return (start);
		}
		i++;
	}
	return (start);
}

static int		height_end(char **map, int max_height, int x)
{
	int		i;
	int		end;

	i = 0;
	i = max_height;
	end = 0;
	while (i > 0)
	{
		if (ft_strlen(map[i]) >= (size_t)x && map[i][x] == 'O')
		{
			end = i;
			return (end);
		}
		i--;
	}
	return (end);
}

static int		len_end(char *str)
{
	int		len;
	int		end;

	end = 0;
	len = ft_strlen(str);
	if (!len)
		return (-1);
	while (len)
	{
		if (str[len] == 'O')
		{
			end = len;
			return (end);
		}
		len--;
	}
	return (end);
}

int				wall_col(t_ray *ray, int x, int y)
{
	int		len;
	int		max_wid;
	int		min_wid;
	int		max_height;
	int		min_height;

	if (!ray->map_array[y])
		return (-1);
	min_wid = len_start(ray->map_array[y]);
	max_wid = len_end(ray->map_array[y]);
	min_height = height_start(ray->map_array, ray->map_height - 1, x);
	max_height = height_end(ray->map_array, ray->map_height - 1, x);
	if (x < min_wid || x > max_wid || y < min_height || y > max_height
		|| ray->map_array[y][x] != 'O')
		return (-1);
	len = ft_strlen(ray->map_array[y]);
	if (!len)
		return (-1);
	return (0);
}
