# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/28 17:12:44 by Pablo Escob       #+#    #+#              #
#    Updated: 2024/09/28 21:51:42 by Pablo Escob      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = getnearprime
LIBNAME = lib$(NAME).a
TESTFILE = test.c

SRCDIR = src
OBJDIR = objs

FTPOW = ft_pow
LIBFT = ft
TESTNAME = test

FT_POW_DIR = ft_pow
LIBFTDIR = libft

SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

CC = gcc
CFLAGSO = -Wall -Wextra -Werror
LIBF_THIS = -L. -l$(NAME)
LIBF_FT = -L$(LIBFTDIR) -l$(LIBFT)
LIBF_FTPOW = -L$(FT_POW_DIR) -l$(FTPOW)
LFLAGS = $(LIBF_FT) $(LIBF_FTPOW)

LOPT = -o2

.PHONY: all, re, run, clean, fclean, lib, libfull

all: lib

lib: $(LIBNAME)

libfull: $(LIBNAMEFULL)

run: lib
	@$(CC) $(CFLAGSO) $(TESTFILE) -L. -l$(NAME) -o $(TESTNAME)
	./$(TESTNAME) 1000

clean:
	$(MAKE) -C $(LIBFTDIR) clean
	$(MAKE) -C $(FT_POW_DIR) clean
	rm -rf $(OBJDIR)

fclean: clean
	$(MAKE) -C $(LIBFTDIR) fclean
	$(MAKE) -C $(FT_POW_DIR) fclean
	rm -f $(TESTNAME) $(LIBNAME)

re: fclean all

$(LIBNAME): $(OBJ)
	$(MAKE) -C $(LIBFTDIR)
	$(MAKE) -C $(FT_POW_DIR)
	ar -rc $@ $(OBJ) $(FT_POW_DIR)/$(OBJDIR)/*.o $(LIBFTDIR)/$(OBJDIR)/*.o
	ranlib $(LIBNAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) -c $< -o $@