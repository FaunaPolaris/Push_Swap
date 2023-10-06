CC		=	gcc
C_FLAGS		=	-Wall -Wextra -Werror -g3 -ggdb
LIBLINK		=	-L ./sources/libft/ -lft -lm
INCLUDES	=	-I ./includes $(LIBLINK)

SRCS_DLLIST	=	add_back.c add_frnt.c clear.c fnd_end.c new_list.c new_node.c new_rlist.c putlist.c size.c
SRCS_STACK	=	new.c swap.c swap_double.c push.c rott_lft.c rott_lft_double.c rott_rgt_double.c rott_rgt.c disp.c

SRCS_ALL	=	$(addprefix sources/linked_list/dll_,$(SRCS_DLLIST))
SRCS_ALL	+=	$(addprefix sources/stack/stck_,$(SRCS_STACK))

TOTAL_FILES	:=	$(words $(SRCS_ALL))
COMPILED_FILES	:=	0

OBJS_DIR	=	objs
OBJS_ALL	=	$(addprefix $(OBJS_DIR)/,$(SRCS_ALL:.c=.o))

TMAIN_STACK	=	tests/stck_test.c
TMAIN_LLIST	=	tests/dllist_test.c

ANSI		=	\033[0
RED		=	;31
GREEN		=	;32

all: libft $(OBJS_ALL) tests
	@printf "%-20s$(ANSI)$(GREEN)m%-15s$(ANSI)m\n" "all" "compiled"

libft:
	@make -C sources/libft

$(OBJS_DIR)/%.o:%.c
	@mkdir -p $(@D)
	@$(CC) $(C_FLAGS) -c $< -o $@ -Iincludes/ 
	@$(eval COMPILED_FILES := $(shell echo $$(($(COMPILED_FILES)+1))))
	@echo -n "Compiled $(COMPILED_FILES) out of $(TOTAL_FILES)"
	@echo " ($(ANSI)$(GREEN)m$(shell echo 'scale=2; $(COMPILED_FILES) / $(TOTAL_FILES) * 100' | bc)%$(ANSI)m)"

tests: $(OBJS_ALL) dllist_test stack_test

dllist_test:
	@$(CC) $(C_FLAGS) $(OBJS_ALL) $(TMAIN_LLIST) $(INCLUDES) -o $@
	@printf "%-20s$(ANSI)$(GREEN)m%-15s$(ANSI)m\n" "dllist_test" "compiled"
	@printf "%10s\n" "----------"
	@printf "./dllist_test [content] [type]\n"
	@printf "content should be a string with values separated by spaces\n"
	@printf "type should be a char that determines which type of content will be sent\n\n"
	@printf "c = char\ns = string\ni = int\n"
	@printf "%10s\n" "----------"

stack_test:
	@$(CC) $(C_FLAGS) $(OBJS_ALL) $(TMAIN_STACK) $(INCLUDES) -o $@
	@printf "%-10s$(ANSI)$(GREEN)m%15s$(ANSI)m\n" "stack_test" "compiled"
	@printf "%10s\n" "----------"
	@printf "./stack_test [stack_a] [stack_b]\n"
	@printf "stacks should be numerical values separated by spaces, no numerical values will be evaluated to zero\n"
	@printf "a empty string will create an empty stack\n\n"
	@printf "%10s\n" "----------"

tests_fclean:
	@rm -rf stack_test
	@rm -f dllist_test
	@printf "%-20s$(ANSI)$(RED)m%-15s$(ANSI)m\n" "Tests" "removed"

clean:
	@rm -rf $(OBJS_DIR)
	@printf "%-20s$(ANSI)$(RED)m%-15s$(ANSI)m\n" "Objects" "removed"

fclean: tests_fclean clean
	@make -C sources/libft fclean
	@printf "%-20s$(ANSI)$(RED)m%-15s$(ANSI)m\n" "Executables" "removed"

tests_re: tests_fclean tests

tests_re: tests_fclean tests

re: fclean all

.PHONY: all libft tests dllist_test tests_fclean clean fclean tests_re re

