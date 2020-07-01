/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: greed <greed@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/07 11:41:50 by greed         #+#    #+#                 */
/*   Updated: 2020/06/30 18:04:12 by greed         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/*
**	SYSTEM LIBRIARIES
*/

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

/*
**	Mini Libx
*/

# include <mlx.h>

/*
**	Libft PrintF and Get Next Line Updated Lib List
*/

# include <libft.h>
# include <liblist.h>

/*
**	Defines and Starting Values
*/

# define START_P_DIR_X   	-1
# define START_P_DIR_Y   	0
# define START_P_PLANE_X 	0
# define START_P_PLANE_Y 	0.66
# define MV_SPEED        	0.038
# define ROT_SPEED       	1.7
# define BUMP_B				-0.000040
# define AMB_LIGHT       	7
# define LOOKSPEED			0.040
# define LOOKACCEL			0.004
# define DEG90				1.5708
# define DEG270				4.71239

/*
**	Controls
*/

# define K_ESC          	53
# define K_W		    	13
# define K_S		    	1
# define K_A		    	0
# define K_D		    	2
# define K_LEFT		    	123
# define K_RIGHT	    	124

# define E_KEY_PRESS        2
# define E_KEY_RELEASE      3
# define E_MOUSE_PRESS      4
# define E_MOUSE_RELEASE    5
# define E_MOUSE_MOVE       6
# define E_EXIT             17

/*
**	Colors
*/

typedef struct		s_clr
{
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
}					t_clr;

typedef union		u_color
{
	t_clr			pack;
	unsigned int	color;
}					t_color;

typedef struct		s_data
{
	char			*g_text_north;
	char			*g_text_south;
	char			*g_text_west;
	char			*g_text_east;
	char			*g_text_sprite;
	char			g_direction;
	int				g_num_sprite;
	t_clr			g_floor_clr;
	t_clr			g_ceiling_clr;
	unsigned int	g_color;
	unsigned int	g_fl_color;
	unsigned int	g_ce_color;
}					t_data;

/*
**	Textures
*/

typedef struct		s_text
{
	double			wall_x;
	char			*addr;
	int				bits_pp;
	int				line_len;
	int				endian;
	int				width;
	int				height;
	int				text_x;
	int				text_y;
	int				textnum;
	void			*img_ptr;
}					t_text;

/*
**	Flood Fill ENUM
*/

enum		e_check
{
	VALID,
	INVALID,
};

/*
**	Sprite List
*/

typedef struct		s_sprite_list
{
	double			x;
	double			y;
}					t_sprite_list;

/*
**	Sprites
*/

typedef	struct		s_sprite
{
	double			sprite_x;
	double			sprite_y;
	double			inv_det;
	double			transform_x;
	double			transform_y;
	double			wall_x;
	char			*addr;
	int				bits_pp;
	int				line_len;
	int				endian;
	int				width;
	int				height;
	int				text_x;
	int				text_y;
	int				textnum;
	int				sprite_screen_x;
	int				sprite_height;
	int				draw_start_y;
	int				draw_end_y;
	int				sprite_width;
	int				draw_start_x;
	int				draw_end_x;
	int				stripe;
	void			*img_ptr;
}					t_sprite;

/*
**	All working data for Ray Casting (RAY)
*/

typedef struct		s_vect
{
	double			x;
	double			y;
}					t_vect;

typedef struct		s_play
{
	t_vect			pos;
	t_vect			dir;
	t_vect			plane;
}					t_play;

typedef struct		s_ray
{
	double			ray_dir_x;
	double			ray_dir_y;
	double			perp_wall_dist;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			speedx;
	double			speedy;
	double			*z_buff;
	double			look_vel;
	double			look_dir;
	char			*addr;
	char			*addr2;
	char			**sprite_loc;
	char			**map_array;
	char			start_dir;
	int				curr_img;
	int				bits_pp;
	int				line_len;
	int				line_height;
	int				endian;
	int				map_x;
	int				map_y;
	int				max_x;
	int				step_x;
	int				step_y;
	int				side;
	int				draw_start;
	int				draw_end;
	int				move_f;
	int				move_b;
	int				moving;
	int				sprite_text;
	int				map_len;
	int				trig;
	int				map_height;
	int				win_x;
	int				win_y;
	int				wall_height;
	int				move_left;
	int				move_right;
	int				strafe_l;
	int				strafe_r;
	int				vars;
	int				map_wid;
	int				bmp;
	int				nsew;
	unsigned int	color;
	unsigned int	flr_color;
	unsigned int	ceil_clr;
	t_data			data;
	t_list			*map_lst;
	t_text			text;
	t_text			text_east;
	t_text			text_north;
	t_text			text_south;
	t_text			text_west;
	t_sprite		sprite;
	t_play			play;
	void			*mlx_ptr;
	void			*mlx_ptr2;
	void			*mlx_wind;
	void			*img_ptr;
	void			*img_ptr2;
}					t_ray;

typedef struct		s_sort
{
	int				gap;
	int				swapped;
	int				i;
	int				tempord;
	double			tempdist;
	int				j;
}					t_sort;

/*
**	Sprite list
*/

t_sprite_list		*g_sprite_list;

/*
**	Function Prototypes
*/

t_clr				ft_make_clr(int hex_value);
t_clr				make_wall_clr(int map_x, int map_y);
t_clr				dark_mode(t_clr clr, double distance);

/*
**	Function Prototypes
*/

/*
**	New
*/

void				ft_img_to_bmp(t_ray *ray);
char				ft_chrmatch(char c, char *set);

/*
**	Reading File
*/

void				ft_input_check(int ac, char **av, t_ray *ray);
void				ft_valid_text(t_ray *ray, char **info);
void				valid_sprite_check(t_ray *ray, char **info);
void				valid_flr_ceiling(t_ray *ray, char **info);
void				functioncollar(t_ray *ray, char *line);
void				init(t_ray *ray);
bool				valid_file(char *str);

/*
**	Map
*/

bool				vlad_impaler(t_ray *ray);
char				*ft_trim_space(char *line);
char				ft_start_dir(t_ray *ray, char *str);
void				map_read_start(t_ray *ray, char *line);
void				char_array_my_map(t_ray *ray);
int					flood_fill_map(t_ray *ray, int x, int y);

/*
**	Error and Free
*/

void				put_error(char *error);
void				fremashin(char **words, int j);
void				free_this(char **array);
void				fre_array(char **array);
void				free_list(t_list *list, void (*func)(void *));

/*
**	Resolution
*/

int					ft_dig_str(char *str);
void				ft_get_res(t_ray *ray, char **info);
void				ft_img_to_bmp(t_ray *ray);

/*
**	Rendering
*/

int					render_frame(t_ray *ray);
unsigned int		ft_put_text_north(t_ray *ray, unsigned int color, int y);
unsigned int		ft_put_text_south(t_ray *ray, unsigned int color, int y);
unsigned int		ft_put_text_east(t_ray *ray, unsigned int color, int y);
unsigned int		ft_put_text_west(t_ray *ray, unsigned int color, int y);
unsigned int		ft_put_sprite(t_ray *ray, unsigned int color, int y);
void				ft_put_pixel(t_ray *ray, unsigned int color, int y, int x);
void				draw_vert_line(t_ray *ray, int x);
void				start_calc(t_ray *ray, int x);
void				perform_dda(t_ray *ray);
void				ft_start_calc(t_ray *ray, int x);
void				calc_wall_height(t_ray *ray);
void				calc_north_text(t_ray *ray);
void				calc_south_text(t_ray *ray);
void				calc_east_text(t_ray *ray);
void				calc_west_text(t_ray *ray);
void				set_floor_ceiling(t_ray *ray);
void				save_sprites(t_ray *ray);
void				cast_sprite(t_ray *ray);
void				start_text_img(t_ray *ray);
void				sprite_calc(t_ray *ray, int sprite_order[], int i);
void				comb_sort(int *order, double *dist, int amount);
void				comb_sort_ex(int *order, double *dist, t_sort *sort);
void				start_text_sprite(t_ray *ray);
void				cub3d(t_ray *ray);

/*
**	Movement
*/

int					handle_press(int keycode, t_ray *ray);
int					handle_release(int keycode, t_ray *ray);
int					ft_red_x(t_ray *ray);
int					wall_col(t_ray *ray, int x, int y);
int					check_coll(t_ray *ray, int xy);
void				move_right(t_ray *ray);
void				move_left(t_ray *ray);
void				move_back(t_ray *ray);
void				move_forward(t_ray *ray);
void				handle_strafe(t_ray *ray);
void				handle_moving(t_ray *ray);

int					new_movement(t_ray *ray);
void				ft_rot_dir(t_ray *ray, double ang);

/*
**	Testing
*/

void				ft_test_vars(t_ray *ray);
void				print_map(t_ray *ray);
#endif
