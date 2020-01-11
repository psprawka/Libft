# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/24 11:51:37 by psprawka          #+#    #+#              #
#    Updated: 2020/01/11 02:50:42 by psprawka         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = libft.a
FLAGS += -g -Wall -Wextra -Werror
# FLAGS +=  -fsanitize=address

SRC_DIR 	= srcs/
DATA_STUCTS	= data_structures/
DLIST		= double_list/
HT			= hash_table/
LIST		= list/
RBT			= red_black_tree/
QUEUE		= queue/
STACK		= stack/
NUMERIC		= numeric/
2D_ARRAY	= 2D_array/
STRING		= string/
MEMORY		= memory/
IO			= io/
TOOLS		= tools/
PRINTF		= ft_printf/srcs/

HEADERS 	= ./includes


SRC = $(SRC_DIR)$(IO)ft_putchar_fd.c  \
		$(SRC_DIR)$(IO)ft_putendl_fd.c \
		$(SRC_DIR)$(IO)ft_putnbr_fd.c \
		$(SRC_DIR)$(IO)ft_putstr_fd.c \
		$(SRC_DIR)$(IO)ft_gnl.c \
		$(SRC_DIR)$(MEMORY)ft_bzero.c \
		$(SRC_DIR)$(MEMORY)ft_memalloc.c \
		$(SRC_DIR)$(MEMORY)ft_memchr.c \
		$(SRC_DIR)$(MEMORY)ft_memcpy.c \
		$(SRC_DIR)$(MEMORY)ft_memdup.c \
		$(SRC_DIR)$(MEMORY)ft_memncmp.c \
		$(SRC_DIR)$(MEMORY)ft_memset.c \
		$(SRC_DIR)$(MEMORY)ft_swap.c \
		$(SRC_DIR)$(NUMERIC)ft_atoi.c \
		$(SRC_DIR)$(NUMERIC)ft_convert_binary.c \
		$(SRC_DIR)$(NUMERIC)ft_convert_hex.c \
		$(SRC_DIR)$(NUMERIC)ft_convert_octal.c \
		$(SRC_DIR)$(NUMERIC)ft_convert_uni.c \
		$(SRC_DIR)$(NUMERIC)ft_ulltoa.c \
		$(SRC_DIR)$(NUMERIC)ft_ftoa.c \
		$(SRC_DIR)$(NUMERIC)ft_itoa.c \
		$(SRC_DIR)$(NUMERIC)ft_putnbr.c \
		$(SRC_DIR)$(2D_ARRAY)ft_2Darr_size.c \
		$(SRC_DIR)$(2D_ARRAY)ft_2Darr_free.c \
		$(SRC_DIR)$(2D_ARRAY)ft_2Darr_print.c \
		$(SRC_DIR)$(STRING)ft_are_whitespaces.c \
		$(SRC_DIR)$(STRING)ft_putchar.c \
		$(SRC_DIR)$(STRING)ft_putendl.c \
		$(SRC_DIR)$(STRING)ft_putstr.c \
		$(SRC_DIR)$(STRING)ft_strclr.c \
		$(SRC_DIR)$(STRING)ft_strcat.c \
		$(SRC_DIR)$(STRING)ft_strchr.c \
		$(SRC_DIR)$(STRING)ft_strcmp.c \
		$(SRC_DIR)$(STRING)ft_strcount_chr.c \
		$(SRC_DIR)$(STRING)ft_strcpy.c \
		$(SRC_DIR)$(STRING)ft_strdup.c \
		$(SRC_DIR)$(STRING)ft_strdup_chr.c \
		$(SRC_DIR)$(STRING)ft_strjoin.c \
		$(SRC_DIR)$(STRING)ft_strlen.c \
		$(SRC_DIR)$(STRING)ft_strlen_chr.c \
		$(SRC_DIR)$(STRING)ft_strncat.c \
		$(SRC_DIR)$(STRING)ft_strncmp.c \
		$(SRC_DIR)$(STRING)ft_strncpy.c \
		$(SRC_DIR)$(STRING)ft_strnew.c \
		$(SRC_DIR)$(STRING)ft_strnstr.c \
		$(SRC_DIR)$(STRING)ft_strrev.c \
		$(SRC_DIR)$(STRING)ft_strstr.c \
		$(SRC_DIR)$(STRING)ft_strsplit_chr.c \
		$(SRC_DIR)$(STRING)ft_strsub.c \
		$(SRC_DIR)$(STRING)ft_wstrlen.c \
		$(SRC_DIR)$(STRING)ft_strtrim.c \
		$(SRC_DIR)$(TOOLS)ft_count_words.c \
		$(SRC_DIR)$(TOOLS)ft_is_sort.c \
		$(SRC_DIR)$(TOOLS)ft_sort_wordtab.c \
		$(SRC_DIR)$(TOOLS)ft_set_max_fd.c \
		$(SRC_DIR)$(DATA_STUCTS)init_node.c \
		$(SRC_DIR)$(DATA_STUCTS)remove_node.c \
		$(SRC_DIR)$(DATA_STUCTS)$(DLIST)add_double_list.c \
		$(SRC_DIR)$(DATA_STUCTS)$(DLIST)free_double_list.c \
		$(SRC_DIR)$(DATA_STUCTS)$(DLIST)init_double_list.c \
		$(SRC_DIR)$(DATA_STUCTS)$(DLIST)remove_double_list.c \
		$(SRC_DIR)$(DATA_STUCTS)$(HT)free_hashtable.c \
		$(SRC_DIR)$(DATA_STUCTS)$(HT)hash_hashtable.c \
		$(SRC_DIR)$(DATA_STUCTS)$(HT)init_hashtable.c \
		$(SRC_DIR)$(DATA_STUCTS)$(HT)insert_hashtable.c \
		$(SRC_DIR)$(DATA_STUCTS)$(HT)print_hashtable.c \
		$(SRC_DIR)$(DATA_STUCTS)$(HT)remove_hashtable.c \
		$(SRC_DIR)$(DATA_STUCTS)$(HT)search_hashtable.c \
		$(SRC_DIR)$(DATA_STUCTS)$(LIST)add_list.c \
		$(SRC_DIR)$(DATA_STUCTS)$(LIST)free_list.c \
		$(SRC_DIR)$(DATA_STUCTS)$(LIST)remove_list.c \
		$(SRC_DIR)$(DATA_STUCTS)$(RBT)create_rbtree.c \
		$(SRC_DIR)$(DATA_STUCTS)$(RBT)delete_rbtree.c \
		$(SRC_DIR)$(DATA_STUCTS)$(RBT)delete_repair_rbtree.c \
		$(SRC_DIR)$(DATA_STUCTS)$(RBT)get_family_rbtree.c \
		$(SRC_DIR)$(DATA_STUCTS)$(RBT)insert_rbtree.c \
		$(SRC_DIR)$(DATA_STUCTS)$(RBT)insert_repair_rbtree.c \
		$(SRC_DIR)$(DATA_STUCTS)$(RBT)print_rbtree.c \
		$(SRC_DIR)$(DATA_STUCTS)$(RBT)rotations_rbtree.c \
		$(SRC_DIR)$(DATA_STUCTS)$(RBT)search_rbtree.c \
		$(SRC_DIR)$(DATA_STUCTS)$(QUEUE)free_queue.c \
		$(SRC_DIR)$(DATA_STUCTS)$(QUEUE)init_queue.c \
		$(SRC_DIR)$(DATA_STUCTS)$(QUEUE)push_queue.c \
		$(SRC_DIR)$(DATA_STUCTS)$(QUEUE)push_pqueue.c \
		$(SRC_DIR)$(DATA_STUCTS)$(QUEUE)pop_queue.c \
		$(SRC_DIR)$(DATA_STUCTS)$(QUEUE)top_queue.c \
		$(SRC_DIR)$(DATA_STUCTS)$(STACK)is_empty_stack.c \
		$(SRC_DIR)$(DATA_STUCTS)$(STACK)push_stack.c \
		$(SRC_DIR)$(DATA_STUCTS)$(STACK)pop_stack.c \
		$(SRC_DIR)$(DATA_STUCTS)$(STACK)top_stack.c 

SRC_PRINTF = $(SRC_DIR)$(IO)$(PRINTF)ft_printf.c \
		$(SRC_DIR)$(IO)$(PRINTF)print.c \
		$(SRC_DIR)$(IO)$(PRINTF)gather_flags.c \
		$(SRC_DIR)$(IO)$(PRINTF)str_chr.c \
		$(SRC_DIR)$(IO)$(PRINTF)ptr_dbl.c \
		$(SRC_DIR)$(IO)$(PRINTF)int_uint.c \
		$(SRC_DIR)$(IO)$(PRINTF)tools.c \
		$(SRC_DIR)$(IO)$(PRINTF)ft_libftprintf.c

OBJ += $(SRC:.c=.o)
OBJ += $(SRC_PRINTF:.c=.o)

BUILD_PRINT = @echo "\r\033[38;5;214m[LIBFT] \x1B[33mBuilding $<"
DONE = @echo "\033[K\033[1;38;5;226mLIBFT ready to use!\x1B[0m"
CLEAN_O = @echo "\033[38;5;246mObject files removed! [LIBFT]\x1B[0m"
CLEAN_A = @echo "\033[38;5;246mExecutable removed! [LIBFT]\x1B[0m"


all: $(NAME)

$(OBJ): %.o: %.c
	$(BUILD_PRINT)
	@gcc $(FLAGS) -I $(HEADERS) -c $< -o $@

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	$(DONE)

clean:
	@/bin/rm -rf $(OBJ)
	$(CLEAN_O)

fclean: clean
	@/bin/rm -rf $(NAME)
	$(CLEAN_A)

re: fclean all

.PHONY: all clean fclean re
