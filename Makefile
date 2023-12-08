# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: armgonza <armgonza@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/06 12:49:47 by armgonza          #+#    #+#              #
#    Updated: 2023/12/06 12:49:51 by armgonza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a
RM = rm -f
CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRCS = get_next_line.c \
       get_next_line_utils.c \

BONUS_SRCS = get_next_line_bonus.c \
			 get_next_line_utils_bonus.c \

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)


## COLORS ##
END		= \033[0m
RED		= \033[1;31m
GREEN	= \033[1;32m
YELLOW	= \033[1;33m
BLUE	= \033[1;34m
WHITE	= \033[1;37m

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)


bonus: $(OBJS) $(BONUS_OBJS)
	@ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus