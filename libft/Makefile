NAME		= libft.a

CC      	= gcc
CFLAGS		= -Wall -Wextra -Werror

AR			= ar rc
RM			= rm -f

INCS_DIR 	= ./includes
OBJS_DIR 	= ./objects
SRCS_DIR 	= ./srcs \
		   	  ./srcs/_to_ \
		   	  ./srcs/is_ \
		   	  ./srcs/lst_ \
		   	  ./srcs/mem_ \
		   	  ./srcs/put_ \
		   	  ./srcs/str_ \
			  ./srcs/vec_ \
			  ./srcs/utils

SRCS		= ./srcs/_to_/ft_atoi.c \
			  ./srcs/_to_/ft_atoll.c \
			  ./srcs/_to_/ft_itoa.c \
			  ./srcs/_to_/ft_tolower.c \
			  ./srcs/_to_/ft_toupper.c \
			  \
			  ./srcs/is_/ft_isalnum.c \
			  ./srcs/is_/ft_isalpha.c \
			  ./srcs/is_/ft_isascii.c \
			  ./srcs/is_/ft_isdigit.c \
			  ./srcs/is_/ft_isprint.c \
			  ./srcs/is_/ft_isspace.c \
			  \
			  ./srcs/mem_/ft_bzero.c \
			  ./srcs/mem_/ft_calloc.c \
			  ./srcs/mem_/ft_memccpy.c \
			  ./srcs/mem_/ft_memchr.c \
			  ./srcs/mem_/ft_memcmp.c \
			  ./srcs/mem_/ft_memcpy.c \
			  ./srcs/mem_/ft_memmove.c \
			  ./srcs/mem_/ft_memset.c \
			  \
			  ./srcs/put_/ft_putchar_fd.c \
			  ./srcs/put_/ft_putendl_fd.c \
			  ./srcs/put_/ft_putnbr_fd.c \
			  ./srcs/put_/ft_putstr_fd.c \
			  \
			  ./srcs/str_/ft_split.c \
			  ./srcs/str_/ft_strchr.c \
			  ./srcs/str_/ft_strcpy.c \
			  ./srcs/str_/ft_strdup.c \
			  ./srcs/str_/ft_strjoin.c \
			  ./srcs/str_/ft_strlcat.c \
			  ./srcs/str_/ft_strlcpy.c \
			  ./srcs/str_/ft_strlen.c \
			  ./srcs/str_/ft_strmapi.c \
			  ./srcs/str_/ft_strncmp.c \
			  ./srcs/str_/ft_strnstr.c \
			  ./srcs/str_/ft_strrchr.c \
			  ./srcs/str_/ft_strtrim.c \
			  ./srcs/str_/ft_substr.c \
			  \
			  ./srcs/vec_/ft_vecjoin.c \
			  ./srcs/vec_/ft_veclen.c \
			  \
			  ./srcs/utils/ft_abs.c \
			  ./srcs/utils/ft_imaxi.c \
			  ./srcs/utils/ft_imini.c \
			  ./srcs/utils/ft_iswapi.c \
			  ./srcs/utils/tools.c

BONUS		= ./srcs/lst_/ft_lstadd_back.c \
			  ./srcs/lst_/ft_lstadd_front.c \
			  ./srcs/lst_/ft_lstclear.c \
			  ./srcs/lst_/ft_lstdelone.c \
			  ./srcs/lst_/ft_lstiter.c \
			  ./srcs/lst_/ft_lstlast.c \
			  ./srcs/lst_/ft_lstmap.c \
			  ./srcs/lst_/ft_lstnew.c \
			  ./srcs/lst_/ft_lstsize.c

OBJS		= $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))
BONUS_OBJS	= $(addprefix $(OBJS_DIR)/, $(notdir $(BONUS:.c=.o)))

vpath %.c $(SRCS_DIR)


all: $(NAME)


# libft
$(NAME): $(OBJS) $(BONUS_OBJS)
	@$(AR) $(NAME) $^

$(OBJS_DIR)/%.o: %.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) -o $@ -c $^ -I $(INCS_DIR)

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)


# bonus
bonus: $(BONUS_OBJS)
	@$(AR) $(NAME) $^

clean:
	@$(RM) -r $(OBJS_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re, bonus
