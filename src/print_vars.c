/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_vars.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: greed <greed@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 09:59:47 by greed         #+#    #+#                 */
/*   Updated: 2020/06/12 15:42:30 by greed         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_map(t_ray *ray)
{
	int y;

	y = 0;
	while (y < ray->map_height)
	{
		ft_printf("%s\n", ray->map_array[y]);
		y++;
	}
}

void	test_text_value(t_ray *ray)
{
	ft_printf("\nnorth\n-----------\n\n%s\n", ray->data.g_text_north);
	ft_printf("\nsouth\n-----------\n\n%s\n", ray->data.g_text_south);
	ft_printf("\neast\n-----------\n\n%s\n", ray->data.g_text_east);
	ft_printf("\nwest\n-----------\n\n%s\n", ray->data.g_text_west);
	ft_printf("\nsprite\n-----------\n\n%s\n", ray->data.g_text_sprite);
	ft_printf("\nCeiling Red\n-----------\n\n%hhu\n",
		ray->data.g_ceiling_clr.red);
	ft_printf("\nCeiling Green\n-----------\n\n%hhu\n",
		ray->data.g_ceiling_clr.green);
	ft_printf("\nCeiling Blue\n-----------\n\n%hhu\n",
		ray->data.g_ceiling_clr.blue);
	ft_printf("\nFloor Red\n-----------\n\n%hhu\n", ray->data.g_floor_clr.red);
	ft_printf("\nFloor Green\n-----------\n\n%hhu\n",
		ray->data.g_floor_clr.green);
	ft_printf("\nFloor Blue\n-----------\n\n%hhu\n",
		ray->data.g_floor_clr.blue);
	ft_printf("\nSprite Number\n-----------\n\n%d\n", ray->data.g_num_sprite);
}

void	test_res_value(t_ray *ray)
{
	ft_printf("Res\n-----------\n\n%d %d\n", ray->win_x, ray->win_y);
}

void	ft_test_vars(t_ray *ray)
{
	ft_printf("\nRESOLUTION\n-----------\n");
	test_res_value(ray);
	ft_printf("\nPATH TO TEXT :\n");
	test_text_value(ray);
	ft_printf("\nStart Dir\n-----------\n\n%c\n", ray->data.g_direction);
	ft_printf("\nStart Pos\n-----------\n");
	ft_printf("\nX = %f\nY = %f\n", ray->play_pos_x, ray->play_pos_y);
	ft_printf("\nMAP WIDTH\n %d\n-----------\n", ray->map_wid);
	print_map(ray);
}
