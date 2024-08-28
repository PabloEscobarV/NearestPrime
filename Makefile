# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/28 17:12:44 by Pablo Escob       #+#    #+#              #
#    Updated: 2024/08/28 17:35:44 by Pablo Escob      ###   ########.fr        #
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
LFLAGS = -L$(FT_POW_DIR) -l$(FTPOW) -L$(LIBFTDIR) -l$(LIBFT)

.PHONY: all, re, run, clean, fclean

all: lib

lib: $(LIBNAME)

run: lib
	$(CC) $(CFLAGSO) $(LIBNAME) $(LFLAGS) $(TESTFILE) -o $(TESTNAME)

clean:
	$(MAKE) -C $(LIBFTDIR) clean
	$(MAKE) -C $(FT_POW_DIR) clean
	rm -rf $(OBJDIR)

fclean: clean
	$(MAKE) -C $(LIBFTDIR) fclean
	$(MAKE) -C $(FT_POW_DIR) fclean
	rm -f $(TESTNAME) $(LIBNAME)

$(LIBNAME): $(OBJ)
	$(MAKE) -C $(LIBFTDIR)
	$(MAKE) -C $(FT_POW_DIR)
	ar -rc $(LIBNAME) $(OBJ) $(LIBFTDIR)/$(OBJDIR)/*.o $(FT_POW_DIR)/$(OBJDIR)/*.o
	ranlib $(LIBNAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) -c $< -o $@