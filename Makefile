CC			=	cc
C_FLAGS		=	-Wall -Wextra -Werror -g3 -ggdb
LIBFT_DIR	=	./utils/libft/src
LIBS_LINK	=	-L $(LIBFT_DIR) -lrt -lm -lft
MINUNIT		=	-I ./includes/minunit 
INCLUDE		=	-I ./includes

STACK_SRCS	=	swap.c

STACK_SRCS	=	$(addprefix srcs/stack/,$(STACK_SRCS))

OBJS_DIR		=	objs
OBJS_ALL	=	$(addprefix $(OBJS_DIR)/,$(SRCS_SERVER:.c=.o))


MAIN = main.c

ANSI		=	\033[0
YELLOW		=	;33
GREEN		=	;32
RED			=	;31

all: $(OBJS_ALL) libft_make

libft_make:
	@make -C $(LIBFT_DIR)

$(OBJS_DIR)/%.o:%.c
	@mkdir -p $(@D)
	@$(CC) $(C_FLAGS) -c $< -o $@ $(INCLUDE)

swap: $(OBJS_ALL)
	@$(CC) $(C_FLAGS) $(OBJS_ALL) $(MAIN_NIKKO) $(INCLUDE) -o push_swap $(LIBS_LINK)
	@printf "%s$(ANSI)$(YELLOW)m%-15s$(ANSI)m\n" "client_nikko:" "Compiled"

clean:
	@rm -rf $(OBJS_DIR)

fclean: clean
	@rm -rf push_swap
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all tests libft_make swap client clean f_clean re