# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ijose <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/01 17:25:45 by ijose             #+#    #+#              #
#    Updated: 2021/02/07 14:13:27 by ijose            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			libftprintf.a

LIBFT_DIR =		libft
LIBFT = 		$(LIBFT_DIR)/libft.a

INC_DIR =		includes
INCLUDES =		$(INC_DIR)/basic_includes.h \
				$(INC_DIR)/format_handler.h \
				$(INC_DIR)/printer.h \
				$(INC_DIR)/ft_printf.h

HANDLERS_DIR =	handlers

PRINTERS_DIR =	printers

SRCS =			ft_printf.c \
				$(HANDLERS_DIR)/format_handler.c \
                $(HANDLERS_DIR)/u_i_handler.c \
                $(PRINTERS_DIR)/printer.c \
                $(PRINTERS_DIR)/print_char.c \
                $(PRINTERS_DIR)/print_hex.c \
                $(PRINTERS_DIR)/print_int.c \
                $(PRINTERS_DIR)/print_pointer.c \
                $(PRINTERS_DIR)/print_string.c \
                $(PRINTERS_DIR)/print_u_int.c \
                $(PRINTERS_DIR)/printer_utilities.c \
		$(PRINTERS_DIR)/printer_utilities_fp.c

SRC_OBJ =		ft_printf.o \
				printer.o \
                print_char.o \
                print_hex.o \
                print_int.o \
                print_pointer.o \
                print_string.o \
                print_u_int.o \
                printer_utilities.o \
		printer_utilities_fp.o \
                format_handler.o \
                u_i_handler.o

OBJS =			$(SRCS:.c=.o)

CFLAGS =		-Wall -Werror -Wextra -c

CC =			gcc
RM =			/bin/rm -rf

all:			$(NAME)

$(NAME): 		$(OBJS)
				$(MAKE) bonus -C ./libft
				cp libft/libft.a $(NAME)
				$(CC) $(CFLAGS) $(INCLUDES) $(SRCS)
				ar -rcs $(NAME) $(OBJS)
				ranlib $(NAME)

clean :
				$(MAKE) clean -C ./libft
				rm -rf $(SRC_OBJ)
				rm -rf $(OBJS)


fclean :		clean
				$(MAKE) fclean -C ./libft
				rm -rf $(NAME)

re: fclean all

.PONY: all, clean, fclean, re
