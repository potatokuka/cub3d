/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_img_data.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: greed <greed@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 10:47:03 by greed         #+#    #+#                 */
/*   Updated: 2020/05/20 17:51:19 by greed         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_save_west_text(t_ray *ray, char *path)
{
	if (ft_strncmp(path, "./pics/", 7))
		put_error("Invalid West Text");
	else
	{
		ray->data.g_text_west = (char *)calloc(ft_strlen_lib(path) + 1,
			sizeof(char));
		ft_strlcpy_lib(ray->data.g_text_west, path, ft_strlen_lib(path) + 1);
	}
}

void		ft_save_east_text(t_ray *ray, char *path)
{
	if (ft_strncmp(path, "./pics/", 7))
		put_error("Invalid East Text");
	else
	{
		ray->data.g_text_east = (char *)calloc(ft_strlen_lib(path) + 1,
			sizeof(char));
		ft_strlcpy_lib(ray->data.g_text_east, path, ft_strlen_lib(path) + 1);
	}
}

void		ft_save_south_text(t_ray *ray, char *path)
{
	if (ft_strncmp(path, "./pics/", 7))
		put_error("Invalid South Text");
	else
	{
		ray->data.g_text_south = (char *)calloc(ft_strlen_lib(path) + 1,
			sizeof(char));
		ft_strlcpy_lib(ray->data.g_text_south, path, ft_strlen_lib(path) + 1);
	}
}

void		ft_save_north_text(t_ray *ray, char *path)
{
	if (ft_strncmp(path, "./pics/", 7))
		put_error("Invalid North Text");
	else
	{
		ray->data.g_text_north = (char *)calloc(ft_strlen_lib(path) + 1,
			sizeof(char));
		ft_strlcpy_lib(ray->data.g_text_north, path, ft_strlen_lib(path) + 1);
	}
}

void		ft_valid_text(t_ray *ray, char **info)
{
	int i;

	i = 0;
	ray->vars++;
	while (info[i])
		i++;
	if (i != 2)
		put_error("Invalid texture arg");
	if (info[1][0] != '.')
		put_error("Invalid texture arg");
	else
	{
		if (info[0][0] == 'N')
			ft_save_north_text(ray, info[1]);
		else if ((info[0][0] == 'S' && info[0][1] == 'O'))
			ft_save_south_text(ray, info[1]);
		else if ((info[0][0] == 'E' && info[0][1] == 'A'))
			ft_save_east_text(ray, info[1]);
		else if ((info[0][0] == 'W' && info[0][1] == 'E'))
			ft_save_west_text(ray, info[1]);
	}
}
