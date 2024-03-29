NAME = push_swap

#-------------DIRECTORIES-----------#
INC_DIR = includes/
SRCS_DIR = srcs/
LIB_DIR = libraries/
OBJ_DIR = obj/

#---------------FILES---------------#
LIBS = $(LIB_DIR)libft/libft.a $(LIB_DIR)printf/libftprintf.a
LIB_HEADERS = -I$(LIB_DIR)libft -I$(LIB_DIR)printf

INC = -I$(INC_DIR) $(LIB_HEADERS)

SRCS = $(SRCS_DIR)actions/swap.c \
	   $(SRCS_DIR)actions/push.c \
	   $(SRCS_DIR)actions/rotate.c \
	   $(SRCS_DIR)actions/reverse_rotate.c \
	   $(SRCS_DIR)error_checks.c \
	   $(SRCS_DIR)init_stack.c \
	   $(SRCS_DIR)rotate_both.c \
	   $(SRCS_DIR)b_to_a.c \
	   $(SRCS_DIR)big_sort.c \
	   $(SRCS_DIR)free.c \
	   $(SRCS_DIR)main.c \
	   $(SRCS_DIR)sort3.c \
	   $(SRCS_DIR)stack_utils.c \
	   $(SRCS_DIR)utils.c

OBJ = $(patsubst $(SRCS_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

#---------------COMPILING-------------#
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g $(INC)

#-----------------RULES---------------#
$(OBJ_DIR)%.o:$(SRCS_DIR)%.c $(LIBS)
	@mkdir -p $(dir $@)
	@$(CC) -c $(CFLAGS) -o $@ $<
	@echo "Compiling $<"

all: lib $(NAME)

lib:
	@make -C $(LIB_DIR)libft
	@make -C $(LIB_DIR)printf

$(NAME): $(OBJ) $(LIBS) Makefile $(INC_DIR) $(LIB_DIR)
	@$(CC) $(OBJ) $(LIBS) -o $(NAME)
	@echo "Built $(NAME)"

clean:
	make clean -C $(LIB_DIR)libft
	make clean -C $(LIB_DIR)printf
	@rm -rf $(OBJ_DIR)

fclean: clean
	make fclean -C $(LIB_DIR)libft
	make fclean -C $(LIB_DIR)printf
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
