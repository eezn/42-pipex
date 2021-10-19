# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/18 14:25:54 by jin-lee           #+#    #+#              #
#    Updated: 2021/10/18 14:26:29 by jin-lee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= pipex

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra

RM			= rm -f

LIBFT		= ./libft/libft.a

INCS_DIR	= ./includes
OBJS_DIR	= ./objects
SRCS_DIR	= ./srcs

SRCS		= ./srcs/main.c \
			  ./srcs/print_error.c

OBJS		= $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))
vpath %.c $(SRCS_DIR)


all : $(NAME)


# pipex
$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(CDEBUG) -o $@ $^
	@echo pipex built successfully.

$(OBJS_DIR)/%.o: %.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) $(CDEBUG) -o $@ -c $^ -I $(INCS_DIR)

$(OBJS_DIR):
	@mkdir -p $@


# libft
$(LIBFT):
	@$(MAKE) -C ./libft all

clean:
	@$(MAKE) -C ./libft clean
	@$(RM) -r $(OBJS_DIR)

fclean: clean
	@$(MAKE) -C ./libft fclean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re