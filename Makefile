# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsausage <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/25 14:23:51 by bsausage          #+#    #+#              #
#    Updated: 2019/12/25 14:23:53 by bsausage         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
FLAGS = -Wall -Werror -Wextra -g
INCLUDES = -I$(PRINTF_HEADERS_DIRECTORY) -I$(LIBFT_HEADERS_DIRECTORY) 

# LIBFT

LIBFT = $(LIBFT_DIRECTORY)libft.a
LIBFT_DIRECTORY = ./libft/
LIBFT_HEADERS_LIST = libft.h get_next_line.h
LIBFT_HEADERS_DIRECTORY = $(LIBFT_DIRECTORY)includes/

LIBFT_SOURCES_DIRECTORY = $(LIBFT_DIRECTORY)sources/
LIBFT_SOURCES_LIST = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
ft_memchr.c ft_memcmp.c	ft_strlen.c ft_strdup.c ft_strcpy.c \
ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c \
ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c \
ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
ft_isprint.c ft_toupper.c ft_tolower.c \
ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c \
ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c \
ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c \
ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c \
ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c \
ft_lstmap.c get_next_line.c ft_putwchar.c
LIBFT_SOURCES = $(addprefix $(LIBFT_SOURCES_DIRECTORY), $(LIBFT_SOURCES_LIST))

LIBFT_OBJECTS_DIRECTORY = $(LIBFT_DIRECTORY)objects/
LIBFT_OBJECTS_LIST = $(patsubst %.c, %.o, $(LIBFT_SOURCES_LIST))
LIBFT_OBJECTS = $(addprefix $(LIBFT_OBJECTS_DIRECTORY), $(LIBFT_OBJECTS_LIST))


# PRINTF

PRINTF_HEADERS_LIST = ft_printf.h
PRINTF_HEADERS_DIRECTORY = ./includes/
PRINTF_HEADERS = $(addprefix $(PRINTF_HEADERS_DIRECTORY), $(PRINTF_HEADERS_LIST))

PRINTF_SOURCES_DIRECTORY = ./sources/
PRINTF_SOURCES_LIST = ft_printf.c ft_print_argument.c ft_itoa_base.c \
ft_itoa_base_long.c ft_itoa_base_unsigned.c init_struct.c rounding.c\
get_flags.c free_functions.c print_struct.c get_numbers.c other.c \
di_case.c xp_case.c o_case.c b_case.c u_case.c f_case.c c_case.c s_case.c \
put_dot.c multiply.c

#   

PRINTF_SOURCES = $(addprefix $(PRINTF_SOURCES_DIRECTORY), $(PRINTF_SOURCES_LIST))

PRINTF_OBJECTS_DIRECTORY = objects/
PRINTF_OBJECTS_LIST = $(patsubst %.c, %.o, $(PRINTF_SOURCES_LIST))
PRINTF_OBJECTS	= $(addprefix $(PRINTF_OBJECTS_DIRECTORY), $(PRINTF_OBJECTS_LIST))

# COLORS

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(LIBFT_OBJECTS) $(PRINTF_OBJECTS_DIRECTORY) $(PRINTF_OBJECTS)
	@ar rc $(NAME) $(PRINTF_OBJECTS) $(LIBFT_OBJECTS)
	@ranlib $(NAME)
	@echo "\n$(NAME): $(GREEN)object files were created$(RESET)"
	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

$(PRINTF_OBJECTS_DIRECTORY):
	@mkdir -p $(PRINTF_OBJECTS_DIRECTORY)
	@echo "$(NAME): $(GREEN)$(PRINTF_OBJECTS_DIRECTORY) was created$(RESET)"

$(PRINTF_OBJECTS_DIRECTORY)%.o : $(PRINTF_SOURCES_DIRECTORY)%.c $(PRINTF_HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo "$(GREEN).$(RESET)\c"

$(LIBFT):
	@echo "$(NAME): $(GREEN)Creating $(LIBFT)...$(RESET)"
	@$(MAKE) -sC $(LIBFT_DIRECTORY)


clean:
	@$(MAKE) -sC $(LIBFT_DIRECTORY) clean
	@rm -rf $(PRINTF_OBJECTS_DIRECTORY)
	@echo "$(NAME): $(RED)$(PRINTF_OBJECTS_DIRECTORY) was deleted$(RESET)"
	@echo "$(NAME): $(RED)object files were deleted$(RESET)"

fclean: clean
	@rm -f $(LIBFT)
	@echo "$(NAME): $(RED)$(LIBFT) was deleted$(RESET)"
	@rm -f $(NAME)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"

re:
	@$(MAKE) fclean
	@$(MAKE) all
