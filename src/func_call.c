/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   func_call.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: greed <greed@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/18 17:12:55 by greed         #+#    #+#                 */
/*   Updated: 2020/05/18 17:29:10 by greed         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		func_call_two(t_ray *ray, char **info, char *line, int die)
{
	if (line[0] == 'R' && line[1] == ' ')
		ft_get_res(ray, info);
	else if (line[0] == 'N' && line[1] == 'O')
		ft_valid_text(ray, info);
	else if (line[0] == 'S' && line[1] == 'O')
		ft_valid_text(ray, info);
	else if (line[0] == 'E' && line[1] == 'A')
		ft_valid_text(ray, info);
	else if (line[0] == 'W' && line[1] == 'E')
		ft_valid_text(ray, info);
	else if (line[0] == 'S' && line[1] == ' ')
		valid_sprite_check(ray, info);
	else if (line[0] == 'F' && line[1] == ' ')
		valid_flr_ceiling(ray, info);
	else if (line[0] == 'C' && line[1] == ' ')
		valid_flr_ceiling(ray, info);
	else if (ft_strchr_lib("012NSEW ", line[0]))
	{
		die = 0;
		map_read_start(ray, line);
	}
	return (die);
}

void	functioncollar(t_ray *ray, char *line)
{
	char	**info;
	int		die;

	die = 1;
	info = ft_split(line, ' ');
	if (!info[0])
	{
		fre_array(info);
		free(line);
		return ;
	}
	if (func_call_two(ray, info, line, die) == 1)
		free(line);
	fre_array(info);
}
