/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_floor.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: greed <greed@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 14:13:52 by greed         #+#    #+#                 */
/*   Updated: 2020/05/20 17:50:41 by greed         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_check_color(int min, int max, int clr)
{
	if (clr >= min && max >= clr)
		return (1);
	return (0);
}

void		save_ceiling(t_ray *ray, char **value)
{
	int		red;
	int		green;
	int		blue;

	red = ft_atoi(value[0]);
	green = ft_atoi(value[1]);
	blue = ft_atoi(value[2]);
	if (!(ft_check_color(0, 255, red)) || !(ft_check_color(0, 255, green)) ||
		!(ft_check_color(0, 255, blue)))
		put_error("Invalid Ceiling Color Value");
	ray->data.g_ceiling_clr.red = (char)red;
	ray->data.g_ceiling_clr.green = (char)green;
	ray->data.g_ceiling_clr.blue = (char)blue;
	free_this(value);
}

void		save_floor(t_ray *ray, char **value)
{
	int		red;
	int		green;
	int		blue;

	red = ft_atoi(value[0]);
	green = ft_atoi(value[1]);
	blue = ft_atoi(value[2]);
	if (!(ft_check_color(0, 255, red)) || !(ft_check_color(0, 255, green)) ||
		!(ft_check_color(0, 255, blue)))
		put_error("Invalid Floor Color Value");
	ray->data.g_floor_clr.red = (char)red;
	ray->data.g_floor_clr.green = (char)green;
	ray->data.g_floor_clr.blue = (char)red;
	free_this(value);
}

void		valid_flr_ceiling_two(t_ray *ray, char **info)
{
	char	**value;
	int		i;

	i = 0;
	value = ft_split(info[1], ',');
	while (value[i])
	{
		if (!ft_dig_str(value[i]))
			put_error("Invalid floor or ceiling");
		if (ft_atoi(value[i]) > 255 || ft_atoi(value[i]) < 0)
			put_error("Invalid floor or ceiling");
		i++;
	}
	if (i != 3)
		put_error("Invalid floor or ceiling");
	else
	{
		if (info[0][0] == 'F')
			save_floor(ray, value);
		else if (info[0][0] == 'C')
			save_ceiling(ray, value);
	}
}

void		valid_flr_ceiling(t_ray *ray, char **info)
{
	int i;

	i = 0;
	ray->vars++;
	while (info[i])
		i++;
	if (i != 2)
		put_error("Invalid floor or ceiling");
	else
		valid_flr_ceiling_two(ray, info);
}
