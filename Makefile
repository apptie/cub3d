# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slee2 <slee2@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/06 20:57:48 by jimikim           #+#    #+#              #
#    Updated: 2021/10/04 16:58:41 by jimikim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = ./include
SRCS = ./mandatory/get_next_line/get_next_line.c \
	   ./mandatory/get_next_line/get_next_line_utils.c \
	   ./mandatory/libft/ft_putnbr_fd.c \
	   ./mandatory/libft/ft_putstr_fd.c \
	   ./mandatory/libft/ft_split.c \
	   ./mandatory/libft/ft_strcmp.c \
	   ./mandatory/libft/ft_strdup.c \
	   ./mandatory/libft/ft_strlen.c \
	   ./mandatory/libft/ft_strchr.c \
	   ./mandatory/libft/ft_word_count.c \
	   ./mandatory/libft/ft_array_count.c \
	   ./mandatory/libft/ft_atoi.c \
	   ./mandatory/free.c \
	   ./mandatory/error.c \
	   ./mandatory/info.c \
	   ./mandatory/calc.c \
	   ./mandatory/calc_sub.c \
	   ./mandatory/init.c \
	   ./mandatory/check.c \
	   ./mandatory/check_sub.c \
	   ./mandatory/key_set.c \
	   ./mandatory/key_event.c \
	   ./mandatory/key_arrow.c \
	   ./mandatory/player.c \
	   ./mandatory/texture.c \
	   ./mandatory/map.c \
	   ./mandatory/parse.c \
	   ./mandatory/rgb.c \
	   ./mandatory/cub3d.c
SRCS_BONUS = ./bonus/get_next_line/get_next_line_bonus.c \
	   ./bonus/get_next_line/get_next_line_utils_bonus.c \
	   ./bonus/libft/ft_putnbr_fd_bonus.c \
	   ./bonus/libft/ft_putstr_fd_bonus.c \
	   ./bonus/libft/ft_split_bonus.c \
	   ./bonus/libft/ft_strcmp_bonus.c \
	   ./bonus/libft/ft_strdup_bonus.c \
	   ./bonus/libft/ft_strlen_bonus.c \
	   ./bonus/libft/ft_strchr_bonus.c \
	   ./bonus/libft/ft_word_count_bonus.c \
	   ./bonus/libft/ft_array_count_bonus.c \
	   ./bonus/libft/ft_atoi_bonus.c \
	   ./bonus/free_bonus.c \
	   ./bonus/error_bonus.c \
	   ./bonus/info_bonus.c \
	   ./bonus/calc_bonus.c \
	   ./bonus/calc_sub_bonus.c \
	   ./bonus/init_bonus.c \
	   ./bonus/check_bonus.c \
	   ./bonus/check_sub_bonus.c \
	   ./bonus/key_set_bonus.c \
	   ./bonus/key_event_bonus.c \
	   ./bonus/key_arrow_bonus.c \
	   ./bonus/player_bonus.c \
	   ./bonus/texture_bonus.c \
	   ./bonus/map_bonus.c \
	   ./bonus/parse_bonus.c \
	   ./bonus/rgb_bonus.c \
	   ./bonus/cub3d_bonus.c
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

ifdef WITH_BONUS
OBJ_FILES = $(OBJS_BONUS)
else
OBJ_FILES = $(OBJS)
endif

bonus:
	make WITH_BONUS=1 all

$(NAME) : $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) -o $(NAME) -L./mlx -lmlx -framework OpenGL -framework AppKit

%.o : %.c
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $^ -o $@

clean :
	rm -f $(OBJS) $(OBJS_BONUS)

fclean :
	make clean
	rm -f $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re bonus
