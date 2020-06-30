/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wall_col2.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: greed <greed@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/30 12:41:19 by greed         #+#    #+#                 */
/*   Updated: 2020/06/30 12:49:06 by greed         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_iseq(double c1, double c2)
{
	if (c1 - c2 >= -0.01 && c1 - c2 <= 0.01)
		return (1);
	return (0);
}

double	ft_yeet_back_y(t_ray *ray, char **map, double old_x, double old_y)
{
	double		new_y;

	new = old_y;
	if (ft_iseq(floor(old_y), old_y) && (int)old_y - 1 > 0 &&
			!ft_chrmatch(map[(int)old_y - 1][(int)old_x], "1"))
		new_y += 0.05;
	if (ft_iseq(ceil(old_y), old_y) &&
			map[(int)old_y + 1][(int)old_x] == '1')
		new_y -= 0.05;
	return (new_y);
}

double	ft_yeet_back_x(t_ray *ray, char **map, double old_x, double old_y)
{
	double		new_x;

	new_x = old_x;
	if (ft_iseq(floor(old_x), old_x) && (int)old_x - 1 > 0
			&& !ft_chrmatch(map[(int)old_y][(int)old_x - 1], "1"))
		new_x += 0.05;
	if (ft_iseq(floor(old_x), old_x)
			&& ft_chrmatch(map[(int)old_y][(int)old_x + 1], "1"))
		new_x -= 0.05;
	return (new_x);
	
}
int		ft_update_pos(t_ray *ray, )
{
	int		*key;

	key = 
}
