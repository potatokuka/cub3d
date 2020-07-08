/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: greed <greed@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/05 18:10:00 by greed         #+#    #+#                 */
/*   Updated: 2020/07/08 13:16:39 by greed         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char		ft_start_dir(t_ray *ray, char *str)
{
	char dir;

	dir = 0;
	while (*str)
	{
		if (*str == 'N' || *str == 'S' || *str == 'E' || *str == 'W')
		{
			dir = *str;
			ray->trig += 1;
			str++;
		}
		else
			str++;
	}
	if (ray->trig > 1)
		put_error("Too Many Start Directions Given");
	return (dir);
}

void		pp_my_map(t_ray *ray, char *line)
{
	char	*str;
	int		i;
	int		trig;

	i = 0;
	trig = 0;
	while (line[i] != '\0' && trig == 0)
	{
		if (line[i] == ' ')
		{
			str = ft_trim_space(line);
			lst_new_back(&ray->map_lst, str);
			free(line);
			trig++;
		}
		i++;
	}
	if (trig == 0)
		lst_new_back(&ray->map_lst, line);
	return ;
}

void		char_array_my_map(t_ray *ray)
{
	char	**tmp;
	char	*str;
	t_list	*lst;
	int		size_len[2];
	int		xy[2];

	ft_bzero(xy, 8);
	size_len[0] = lst_size(ray->map_lst);
	ray->map_height = size_len[0];
	tmp = (char **)malloc(sizeof(char *) * size_len[0] + 1);
	lst = ray->map_lst;
	while (xy[1] < size_len[0])
	{
		xy[0] = 0;
		str = lst->content;
		tmp[xy[1]] = ft_strdup_lib(str);
		lst = lst->next;
		xy[1]++;
	}
	tmp[xy[1]] = 0;
	ray->map_array = tmp;
}

void		map_read_start(t_ray *ray, char *line)
{
	int		i;

	i = 0;
	if (ray->vars != 8)
		put_error("Incorrect configuration");
	while (line[i] != '\0')
	{
		if (ft_strchr_lib("0123NSEW ", line[i]) == NULL)
		{
			put_error("Invalid Map");
		}
		i++;
	}
	pp_my_map(ray, line);
}
