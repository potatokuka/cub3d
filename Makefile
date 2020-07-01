# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: greed <greed@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2019/12/09 14:50:26 by greed         #+#    #+#                  #
#    Updated: 2020/06/26 12:02:00 by greed         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			=	cub3D
SRCS			=	bmp_save.c\
					calc_text.c\
					colors.c\
					digit_str.c\
					fre_machiner.c\
					flood_fill.c\
					func_call.c\
					hooking.c\
					init.c\
					input_start.c\
					keycode.c\
					main.c\
					parse_floor.c\
					parse_img_data.c\
					parse_map.c\
					parse_res.c\
					parse_sprite.c\
					print_vars.c\
					put_error.c\
					ray_calc.c\
					render_frame.c\
					render_text.c\
					sort.c\
					sprites.c\
					sprite_calc.c\
					start_text.c\
					red_x.c\
					utils.c\
					valid_map_check.c\
					wall_col2.c\
					rot_dir.c
CFILES			=	$(SRCS:%=src/%)
OFILES			=	$(CFILES:.c=.o)
CFLAGS			=	-Wall -Wextra -Werror -DNOLIST 
INCLUDES		=	-I include\
					-I lib/mlx\
					-I lib/libft\
					-I lib/liblist
LIBS			=	-L lib/mlx -lmlx\
					-L lib/libft -lft\
					-L lib/liblist -llist

# LIB LOCATIONS
MLX_LOC			=	lib/mlx
LIBFT_LOC		=	lib/libft
LIBLIST_LOC		=	lib/liblist
# COLORS
WHITE   = \x1b[37;01m
CYAN    = \x1b[36;01m
PINK    = \x1b[35;01m
BLUE    = \x1b[34;01m
YELLOW  = \x1b[33;01m
GREEN   = \x1b[32;01m
RED     = \x1b[31;01m
BLACK   = \x1b[30;01m
RESET   = \x1b[0m
all: $(NAME)
$(NAME): $(OFILES)
	@echo "$(WHITE)/-----		Compiling mlx		-----\\ $(RESET)"
	make -C $(MLX_LOC)
	cp $(MLX_LOC)/libmlx.dylib .
	@echo "$(WHITE)/-----		Compiling libft		-----\\ $(RESET)"
	make bonus -C $(LIBFT_LOC)
	@echo "$(WHITE)/-----		Compiling liblist	-----\\ $(RESET)"
	make -C $(LIBLIST_LOC)
	@echo "$(WHITE)/-----		Compiling cub3d	-----\\ $(RESET)"
	$(CC) $(LIBS) -o $(NAME) $(OFILES)
%.o: %.c
	gcc $(CFLAGS) $(INCLUDES) -c $< -o $@
clean:
	@echo "$(WHITE)/-----		Cleaning mlx		-----\\ $(RESET)"
	make clean -C $(MLX_LOC)
	@-rm libmlx.dylib
	@echo "$(WHITE)/-----		Cleaning libft		-----\\ $(RESET)"
	make clean -C $(LIBFT_LOC)
	@echo "$(WHITE)/-----		Cleaning liblist	-----\\ $(RESET)"
	make clean -C $(LIBLIST_LOC)
	@echo "$(WHITE)/-----		Cleaning cub3d		-----\\ $(RESET)"
	rm -f $(OFILES)
fclean: clean
	@echo "$(WHITE)/-----		Fcleaning libft		-----\\ $(RESET)"
	make fclean -C $(LIBFT_LOC)
	@echo "$(WHITE)/-----		Fcleaning liblist	-----\\ $(RESET)"
	make fclean -C $(LIBLIST_LOC)
	@echo "$(WHITE)/-----		Fcleaning cub3d	-----\\ $(RESET)"
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re
