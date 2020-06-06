/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   red_x.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: greed <greed@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/19 12:14:13 by greed         #+#    #+#                 */
/*   Updated: 2020/05/20 17:53:05 by greed         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		free_line_and_close(int fd, char *line)
{
	if (fd != -1)
		close(fd);
	if (line)
		free(line);
	return (1);
}

int		free_everything(t_ray *ray, int fd, char *line)
{
	int	i;
	int x;

	x = 0;
	if (ray->map_array)
	{
		i = 0;
		while (i < ray->map_height)
		{
			if (ray->map_array[i])
				free(ray->map_array[i]);
			i++;
		}
		free(ray->map_array);
	}
	free_line_and_close(fd, line);
	if (g_sprite_list)
		free(g_sprite_list);
	return (1);
}

int		ft_red_x(t_ray *ray)
{
	free_everything(ray, -1, NULL);
	exit(1);
	return (1);
}
