/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: greed <greed@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 09:50:05 by greed         #+#    #+#                 */
/*   Updated: 2020/07/08 13:02:54 by greed         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		main(int ac, char **av)
{
	t_ray ray;

	ft_bzero(&ray, sizeof(ray));
	ft_input_check(ac, av, &ray);
	if (ray.nsew != 1)
		put_error("Incorrect starting position");
	set_floor_ceiling(&ray);
	print_map(&ray);
	init(&ray);
	if (ac)
		cub3d(&ray);
	mlx_destroy_window(ray.mlx_ptr, ray.mlx_wind);
	return (0);
}
