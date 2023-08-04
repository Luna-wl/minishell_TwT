NAME := minishell

BLK=\e[0;30m
RED=\e[0;31m
GRN=\e[0;32m
YEL=\e[0;33m
BLU=\e[0;34m
MAG=\e[0;35m
CYN=\e[0;36m
WHT=\e[0;37m
RESET=\e[0m

RL_DIR := /usr/local/opt/readline/
LIB_RL := -L$(RL_DIR)lib/

# RL_DIR := /usr/local/lib
# LIB_RL := -L$(RL_DIR)

CC := gcc
CFLAGS := -Wall -Werror -Wextra -lreadline $(LIB_RL) -g #-fsanitize=address

LIBFT_DIR := ./libft
LIBFT := $(LIBFT_DIR)/libft.a
LIB_I := -I$(LIBFT_DIR)

SRCS_DIR := ./srcs
SRCS := $(shell find $(SRCS_DIR) -name '*.c')
HEADER_I := -I$(SRCS_DIR) -I$(RL_DIR)include/

all: $(NAME)

$(NAME): $(SRCS) $(LIBFT)
	@$(CC) $(CFLAGS) $^ $(LIB_I) $(HEADER_I) -o $@
# @printf "$(RED)"
# @cat hell.txt

$(LIBFT):
	@make -C ./libft

norm:
	@echo "---- NORMINETTE ----"
	@norminette -R CheckDefine src/*.h
	@norminette -R CheckForbiddenSourceHeader src/*.c
	@echo "---- THANK YOU ^w^Y ----"

clean:
	@make fclean -C ./libft
	@rm -rf *.dSYM *.o $(NAME)

fclean: clean

re: fclean all libft

.PHONY: clean fclean re norm libft

# NAME = minishell

# BLK=\e[0;30m
# RED=\e[0;31m
# GRN=\e[0;32m
# YEL=\e[0;33m
# BLU=\e[0;34m
# MAG=\e[0;35m
# CYN=\e[0;36m
# WHT=\e[0;37m
# RESET=\e[0m

# RL_DIR := /usr/local/lib
# LIB_RL := -L$(RL_DIR)

# CC := gcc
# CFLAGS := -Wall -Werror -Wextra -lreadline $(LIB_RL) -g

# LIBFT_DIR := ./libft
# LIBFT := $(LIBFT_DIR)/libft.a
# LIB_I := -I$(LIBFT_DIR)

# SRCS_DIR := ./srcs
# SRCS := $(shell find $(SRCS_DIR) -name '*.c')
# HEADER_I := -I$(SRCS_DIR) -I$(RL_DIR)include/

# all: $(NAME)

# $(NAME): $(SRCS) $(LIBFT)
# 	@$(CC) $(CFLAGS) $^ $(LIB_I) $(HEADER_I) -o $@

# $(LIBFT):
# 	@make -C ./libft

# norm:
# 	@echo "---- NORMINETTE ----"
# 	@norminette -R CheckDefine src/*.h
# 	@norminette -R CheckForbiddenSourceHeader src/*.c
# 	@echo "---- THANK YOU ^w^Y ----"

# clean:
# 	@make fclean -C ./libft
# 	@rm -rf *.dSYM *.o $(NAME)

# fclean: clean

# re: fclean all libft
