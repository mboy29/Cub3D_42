# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mboy <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/07 17:37:18 by mboy              #+#    #+#              #
#    Updated: 2021/07/01 08:52:24 by mboy             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= cub3D

SRC 	= 	Sources/Parsing/parse.c\
			Sources/Parsing/parse_res.c\
			Sources/Parsing/parse_text.c\
			Sources/Parsing/parse_tab.c\
			Sources/Parsing/parse_sprite.c\
			Sources/Parsing/parse_rgb.c\
			Sources/Utils/is_map_c.c\
			Sources/Utils/open_map.c\
			Sources/Utils/init.c\
			Sources/Utils/init1.c\
			Sources/Utils/init2.c\
			Sources/Utils/swap.c\
			Sources/Utils/copy_map.c\
			Sources/save.c\
			Sources/color.c\
			Sources/gen.c\
			Sources/ex.c\
			Sources/play.c\
			Sources/key.c\
			Sources/map.c\
			Sources/ray1.c\
			Sources/ray2.c\
			Sources/move.c\
			Sources/sprites1.c\
			Sources/sprites2.c\
			Sources/walls.c\

SRCBNS 	= 	Bonus/Sources/Parsing/parse.c\
			Bonus/Sources/Parsing/parse_res.c\
			Bonus/Sources/Parsing/parse_text.c\
			Bonus/Sources/Parsing/parse_tab.c\
			Bonus/Sources/Parsing/parse_sprite.c\
			Bonus/Sources/Utils/is_map_c.c\
			Bonus/Sources/Utils/open_map.c\
			Bonus/Sources/Utils/update.c\
			Bonus/Sources/Utils/init.c\
			Bonus/Sources/Utils/init1.c\
			Bonus/Sources/Utils/init2.c\
			Bonus/Sources/Utils/swap.c\
			Bonus/Sources/Utils/copy_map.c\
			Bonus/Sources/game1.c\
			Bonus/Sources/game2.c\
			Bonus/Sources/save.c\
			Bonus/Sources/color.c\
			Bonus/Sources/gen.c\
			Bonus/Sources/prep.c\
			Bonus/Sources/ex.c\
			Bonus/Sources/play.c\
			Bonus/Sources/output.c\
			Bonus/Sources/key.c\
			Bonus/Sources/map.c\
			Bonus/Sources/ray1.c\
			Bonus/Sources/ray2.c\
			Bonus/Sources/move.c\
			Bonus/Sources/sprites1.c\
			Bonus/Sources/sprites2.c\
			Bonus/Sources/floors.c\
			Bonus/Sources/walls.c\

SRCLIBFT =	./Sources/Utils/Libft/ft_strlen.c\
			./Sources/Utils/Libft/ft_isalpha.c\
			./Sources/Utils/Libft/ft_isdigit.c\
			./Sources/Utils/Libft/ft_sqrt.c\
			./Sources/Utils/Libft/ft_atoi.c\
			./Sources/Utils/Libft/ft_strcmp.c\
			./Sources/Utils/Libft/ft_strdup.c\
			./Sources/Utils/Libft/ft_nblen.c\
			./Sources/Utils/Libft/ft_putnbr_fd.c\
			./Sources/Utils/Libft/ft_putstr_fd.c\
			./Sources/Utils/Libft/ft_split.c\
			./Sources/Utils/Libft/GNL/get_next_line.c\
			./Sources/Utils/Libft/GNL/get_next_line_utils.c

OBJS			= $(SRC:.c=.o)

OBJBNS			= $(SRCBNS:.c=.o)

OBJLIFT			= $(SRCLIBFT:.c=.o)

CC				= gcc

RM				= rm -rf

CFLAGS			= -Wall -Wextra -Werror -g -fsanitize=address

MLX				= libmlx.a

LIBS			= $(MLX) -framework OpenGL -framework AppKit -lm

ifdef WITH_BONUS
	OBJFILES = $(OBJBNS)
else
	OBJFILES = $(OBJS)
endif

all:			$(NAME)

bonus:			
				make WITH_BONUS=1
				@echo "\x1B[38;2;216;195;151m\n$(NAME) bonus version has been created!\033[0m"


$(NAME):		$(MLX) $(OBJFILES) $(OBJLIFT)
				gcc ${CFLAGS} -o ${NAME} ${OBJFILES} $(OBJLIFT) ${LIBS}
				@echo "\x1B[38;2;216;195;151m\n$(NAME) has been created!\033[0m"

clean:			
				$(RM) $(OBJFILES) $(OBJS) $(OBJBNS) $(OBJLIFT)
				@echo "\x1B[38;2;216;195;151m\nAll .o from $(NAME) have been removed.\033[0m"

fclean:			clean
				$(RM) $(NAME)
				@echo "\x1B[38;2;216;195;151m\n$(NAME) has been removed.\033[0m"

re:				fclean $(NAME)

.PHONY:			all clean fclean re bonus
