/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_sprite.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: greed <greed@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 13:47:34 by greed         #+#    #+#                 */
/*   Updated: 2020/06/12 15:12:18 by greed         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_save_sprite(t_ray *ray, char *path)
{
	if (ft_strncmp(path, "./pics/", 7))
		put_error("Invalid Sprite Text");
	else
	{
		ray->data.g_text_sprite = (char *)calloc(ft_strlen_lib(path) + 1,
			sizeof(char));
		ft_strlcpy_lib(ray->data.g_text_sprite, path, ft_strlen_lib(path) + 1);
	}
}

void		valid_sprite_check(t_ray *ray, char **info)
{
	int i;

	i = 0;
	ray->vars++;
	while (info[i])
		i++;
	if (i != 2)
		put_error("Invalid sprite arg");
	if (info[1][0] != '.')
		put_error("Invalid sprite arg");
	else
		ft_save_sprite(ray, info[1]);
}
