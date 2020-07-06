/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_handling.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: greed <greed@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/06 10:30:03 by greed         #+#    #+#                 */
/*   Updated: 2020/07/06 12:55:40 by greed         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_del_map(char **map)
{
	int		i;
	int		size;

	size = ft_map_size(map);
	i = 0;
	while (i < size)
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map);
}

int			ft_map_size(char **map)
{
	int		size;

	size = 0;
	if (map == NULL)
		return (0);
	while (map[size])
		size++;
	return (size);
}

void		flood_check_edit(t_ray *ray, char **map, int x, int y)
{
	if (map[y][x] == 'O')
		map[y][x] = 'X';
	if (map[y][x] == 'U')
	{
		ray->data.g_num_sprite += 1;
		map[y][x] = 'X';
	}
}

int			flood_fill_edit(t_ray *ray, char **map, int x, int y)
{
	int		len;

	if (x < 0 || y < 0 || y >= ray->map_height)
		return (INVALID);
	if (map[y][x] == 'X' || map[y][x] == '1')
		return (0);
	len = ft_strlen_lib(ray->map_array[y]);
	if (x >= len)
		return (INVALID);
	flood_check_edit(ray, map, x, y);
	if (flood_fill_edit(ray, map, x, y - 1) ||
		flood_fill_edit(ray, map, x, y + 1) ||
		flood_fill_edit(ray, map, x - 1, y) ||
		flood_fill_edit(ray, map, x + 1, y) ||
		flood_fill_edit(ray, map, x + 1, y + 1) ||
		flood_fill_edit(ray, map, x + 1, y - 1) ||
		flood_fill_edit(ray, map, x - 1, y + 1) ||
		flood_fill_edit(ray, map, x - 1, y - 1))
		return (INVALID);
	return (VALID);
}

void		ft_validate_map(t_ray *ray)
{
	int		y;
	char	**map;
	int		size;

	size = ft_map_size(ray->map_array);
	y = 0;
	map = malloc(sizeof(char *) * (size + 1));
	if (!map)
		put_error("Malloc Failure in Map Validation");
	while (y < size)
	{
		map[y] = ft_strdup_lib(ray->map_array[y]);
		if (!map[y])
			put_error("Malloc fail in map validation 1");
		y++;
	}
	map[y] = 0;
	if ((flood_fill_edit(ray, map, ray->play.pos.x, ray->play.pos.y) == 1))
		put_error("Invalid map");
	ft_del_map(map);
}
