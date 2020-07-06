#include "cub3d.h"


double		tex_get_y(t_ray *ray, t_dda *dda, t_line line)
{
	double		texheight;
	double		step;

	
	if (dda->side == NORTH)
		texheight = ray->text_north.height;
	if (dda->side == EAST)
		texheight = ray->text_east.height;
	if (dda->side == WEST)
		texheight = ray->text_west.height;
	if (dda->side == SOUTH)
		texheight = ray->text_south.height;
	step = 1 * texheight / line.len;
	return (step);
}

int			tex_get_x(t_ray *ray, t_dda *dda, double dist)
{
	double		hitpos;
	double		texwidth;
	int			tex_x;

	if (dda->side == NORTH)
		texwidth = ray->text_north.width;
	if (dda->side == EAST)
		texwidth = ray->text_east.width;
	if (dda->side == WEST)
		texwidth = ray->text_west.width;
	if (dda->side == SOUTH)
		texwidth = ray->text_south.width;
	if (dda->side == EAST || dda->side == WEST)
		hitpos = ray->play.pos.y + dist * ray->play.cast.dir.y;
	else
		hitpos = ray->play.pos.x + dist * ray->play.cast.dir.x;
	hitpos -= floor(hitpos);
	hitpos = 1 - hitpos;
	tex_x = (int)(hitpos * (double)texwidth);
	if ((dda->side == EAST || dda->side == WEST) && ray->play.cast.dir.x > 0)
		tex_x = texwidth - tex_x - 1;
	if ((dda->side == NORTH || dda->side == SOUTH) && ray->play.cast.dir.y < 0)
		tex_x =texwidth - tex_x - 1;
	return (tex_x);
}

t_texdata	ft_texdata_get(t_ray *ray, t_dda *dda, double dist, t_line line)
{
	t_texdata	tex;

	tex.x = tex_get_x(ray, dda, dist);
	if (tex.x < 0)
		tex.x = 0;
	tex.y_step = tex_get_y(ray, dda, line);
	return (tex);
}

t_line		line_data(t_ray *ray, double dist, int x)
{
	t_line		line;

	line.x = x;
	line.len = ray->win_y / dist;
	line.start = -line.len / 2 + ray->win_y / 2;
	line.end = line.len / 2 + ray->win_y / 2;
	if (line.start < 0)
		line.start = 0;
	if (line.end >= ray->win_y)
		line.end = ray->win_y - 1;
	return (line);
}

t_cast		ray_dir(t_ray *ray, int x)
{
	t_cast		cast;
	double		camdir_x;
	t_vect		dir;
	t_vect		plane;

	dir = ray->play.dir;
	plane = ray->play.plane;
	camdir_x = ((2 * x / (double)ray->win_x) - 1);
	cast.dir.x = dir.x + plane.x * camdir_x;
	cast.dir.y = dir.y + plane.y * camdir_x;
	cast.pos = ray->play.pos;
	return (cast);
}

void		step_init(t_play play, t_dda*dda)
{
	if (play.cast.dir.x < 0.0)
	{
		dda->step.x = -1;
		dda->sidedist.x = (play.pos.x - (int)play.pos.x) * dda->delta_dist.x;
	}
	else
	{
		dda->step.x = 1;
		dda->sidedist.x = ((int)play.pos.x + 1.0 - play.pos.x) * dda->delta_dist.x;
	}
	if (play.cast.dir.y < 0)
	{
		dda->step.y = -1;
		dda->sidedist.y = ((int)play.pos.y - (int)play.pos.y) * dda->delta_dist.y;
	}
	else
	{
		dda->step.y = 1;
		dda->sidedist.y =((int)play.pos.y + 1.0 - play.pos.y) * dda->delta_dist.y;
	}
}

void		do_dda(t_ray *ray, t_dda *dda)
{
	int		hit;

	hit = 0;
	while(hit == 0)
	{
		if (dda->sidedist.y > dda->sidedist.x)
		{
			dda->sidedist.x += dda->delta_dist.x;
			dda->mappos.x += dda->step.x;
			dda->side = ft_set_side(dda->step.x, WEST, EAST);
		}
		else
		{
			dda->sidedist.y += dda->delta_dist.y;
			dda->mappos.y += dda->step.y;
			dda->side = ft_set_side(dda->step.y, NORTH, SOUTH);
		}
		if(dda->mappos.y < 0 || dda->mappos.x < 0 ||
			!ray->map_array[dda->mappos.y][dda->mappos.x] ||
			ray->map_array[dda->mappos.y][dda->mappos.x] == '1')
			hit = 1;
	}
}

double		dist_calc(t_ray *ray, t_dda *dda)
{
	double		dist;

	dda->delta_dist.x = ft_abs(1.0 / (double)ray->play.cast.dir.x);
	dda->delta_dist.y = ft_abs(1.0 / (double)ray->play.cast.dir.y);
	dda->mappos.x = (int)ray->play.pos.x;
	dda->mappos.y = (int)ray->play.pos.y;
	step_init(ray->play, dda);
	do_dda(ray, dda);
	if (dda->side == EAST || dda->side == WEST)
		dist = (dda->mappos.x - ray->play.pos.x + (1 - dda->step.x) / 2)
			/ ray->play.cast.dir.x;
	else
		dist = (dda->mappos.y - ray->play.pos.y + (1 - dda->step.y) / 2)
			/ ray->play.cast.dir.y;
	return (dist);
}
