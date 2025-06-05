NAME =			fdf
NAME_BONUS =	fdf_bonus
CC =			gcc
FLAGS =			-Wall -Wextra -Werror
DIR_C =			srcs/
DIR_H =			includes
DIR_LIBFT =		libft
DIR_MLX =		mlx_linux

CFILES =		atof_base.c colors_utility.c atof_base_utility.c ft_printf.c matrix.c \
				bresenham_algorithm.c ft_printf_proc.c char_utility.c ft_printf_utils.c \
				check_add.c get_next_line.c point.c check.c get_next_line_utils.c \
				point_utils.c check_utility.c io_manage.c colors.c colors_lighting.c main.c

CFILES_M =		map.c mymlx.c mymlx_utils.c standard_projections.c
CFILES_B =		map_bonus.c mymlx_bonus.c mymlx_utils_bonus.c standard_projection_bonus.c

SRCS =			$(addprefix $(DIR_C), $(CFILES))
SRCS_M =		$(addprefix $(DIR_C), $(CFILES_M))
SRCS_B =		$(addprefix $(DIR_C), $(CFILES_B))

OBJS =			$(SRCS:%.c=%.o)
OBJS_M =		$(SRCS_M:%.c=%.o)
OBJS_B =		$(SRCS_B:%.c=%.o)

LIB_MLX =		mlx_linux/libmlx.a
LIB_LIBFT =		libft/libft.a

HEADERS =		$(DIR_H)/fdf.h $(DIR_H)/colors.h $(DIR_H)/ft_printf.h $(DIR_H)/ft_printf_utils.h $(DIR_H)/get_next_line.h

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(OBJS) $(OBJS_M) $(LIB_MLX) $(LIB_LIBFT)
	$(CC) $(FLAGS) $(OBJS) $(OBJS_M) -L $(DIR_MLX) -lmlx -L/usr/lib -lXext -lX11 -lm -lz $(LIB_LIBFT) -o $(NAME)

$(NAME_BONUS): $(OBJS) $(OBJS_B) $(LIB_MLX) $(LIB_LIBFT)
	$(CC) $(FLAGS) $(OBJS) $(OBJS_B) -L $(DIR_MLX) -lmlx -L/usr/lib -lXext -lX11 -lm -lz $(LIB_LIBFT) -o $(NAME_BONUS)

$(LIB_MLX):
	$(MAKE) -C $(DIR_MLX)

$(LIB_LIBFT):
	$(MAKE) -C $(DIR_LIBFT)

%.o: %.c $(HEADERS)
	$(CC) $(FLAGS) -I $(DIR_H) -I/usr/include -I $(DIR_MLX) -I $(DIR_LIBFT)/includes -O3 -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJS_M) $(OBJS_B)

clean_libft:
	$(MAKE) clean -C $(DIR_LIBFT)

clean_mlx:
	$(MAKE) clean -C $(DIR_MLX)

fclean: clean
	rm -f $(NAME)

fclean_libft:
	$(MAKE) fclean -C $(DIR_LIBFT)

fclean_mlx: clean_mlx
	rm -f mlx_linux/libmlx.a
	rm -f mlx_linux/libmlx_Linux.a

fclean_bonus: clean
	rm -f $(NAME_BONUS)

re: fclean fclean_libft all

re_bonus: fclean_bonus fclean_libft bonus

re_libft:
	$(MAKE) re -C $(DIR_LIBFT)

re_mlx: clean_mlx
	$(MAKE) -C $(DIR_MLX)

re_all: re re_libft re_mlx

re_all_bonus: re_bonus re_libft re_mlx

.PHONY: all bonus clean clean_libft clean_mlx fclean fclean_libft fclean_mlx fclean_bonus re re_bonus re_libft re_mlx re_all re_all_bonus
