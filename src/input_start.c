/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_start.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: greed <greed@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 09:51:28 by greed         #+#    #+#                 */
/*   Updated: 2020/06/26 12:49:52 by greed         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_save_input(t_ray *ray, char *file)
{
	char	*line;
	int		fd;
	int		ret;

	ret = 1;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		put_error("invalid input file");
	while (ret == 1)
	{
		ret = get_next_line(fd, &line);
		functioncollar(ray, line);
	}
	char_array_my_map(ray);
	if (vlad_impaler(ray) == false)
		put_error("Invalid Map");
	if (ray->data.g_num_sprite > 0)
		save_sprites(ray);
}

void	ft_input_ac_3(char **av, t_ray *ray)
{
	int		i;

	i = 0;
	if (ft_strcmp(av[2], "--save") != 0)
		put_error("Invalid third arguement");
	ray->bmp = open("save.bmp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	while (av[1][i])
	{
		if (ft_strchr_lib(".", av[1][i]))
		{
			if (valid_file(av[1]) == false)
				put_error("Invalid input given");
			else
				ft_save_input(ray, av[1]);
		}
		i++;
	}
}

void	ft_input_check(int ac, char **av, t_ray *ray)
{
	int		i;

	i = 0;
	if (ac > 3 || ac < 2)
		put_error("not correct amount of arguments given");
	if (ac == 3)
		ft_input_ac_3(av, ray);
	if (valid_file(av[1]) == false)
		put_error("Invalid input file given");
	if (ac == 2)
	{
		while (av[1][i])
		{
			if (ft_strchr_lib(".", av[1][i]))
				ft_save_input(ray, av[1]);
			i++;
		}
	}
}
