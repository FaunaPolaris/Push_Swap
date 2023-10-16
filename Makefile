NAME		=	push_swap
CC		=	gcc
C_FLAGS		=	-Wall -Wextra -Werror -g3 -ggdb -O3
LIBLINK		=	-L ./sources/libft/ -lft -lm
INCLUDES	=	-I ./includes $(LIBLINK)

SRCS_DLLIST	=	add_back.c add_frnt.c clear.c fnd_end.c new_list.c new_node.c new_rlist.c putlist.c size.c
SRCS_DLLIST	+=	has.c has_higher.c has_lower.c highest.c lowest.c mediam.c next_lower.c next_higher.c index.c
SRCS_DLLIST	+=	next_lower_front.c is_crescent.c has_duplicates.c rindex.c closest_front.c
SRCS_DLLIST	+=	lindex3.c rlindex3.c lindex2.c closest.c closest_back.c closest_higher.c closest_lower.c
SRCS_STACK	=	new.c swap.c push.c rott_lft.c rott_rgt.c disp.c push_all.c push_higher.c push_lower.c
SRCS_STACK	+=	swap_double.c rott_rgt_double.c rott_lft_double.c lowest_to_front.c highest_to_front.c
SRCS_SORT	=	_quick.c  _from_lower.c _by_base.c _v2.c v2_rotate.c _2.c _3.c _4.c _5.c

SRCS_ALL	=	$(addprefix sources/linked_list/dll_,$(SRCS_DLLIST))
SRCS_ALL	+=	$(addprefix sources/stack/stck_,$(SRCS_STACK))
SRCS_ALL	+=	$(addprefix sources/sorting/sort,$(SRCS_SORT))

TOTAL_FILES	:=	$(words $(SRCS_ALL))
COMPILED_FILES	:=	0

OBJS_DIR	=	objs
OBJS_ALL	=	$(addprefix $(OBJS_DIR)/,$(SRCS_ALL:.c=.o))

MAIN		=	sources/main.c
TMAIN_STACK	=	tests/stck_test.c
TMAIN_LLIST	=	tests/dllist_test.c
TMAIN_ROTATE	=	tests/rotate_test.c
TMAIN_PUSH	=	tests/push_test.c
TMAIN_QSORT	=	tests/quick_sort_test.c

ANSI		=	\033[0
RED		=	;31
GREEN		=	;32

all: libft $(OBJS_ALL) $(NAME) tests
	@printf "%-20s$(ANSI)$(GREEN)m%-15s$(ANSI)m\n" "all" "compiled"

libft:
	@make -C sources/libft

$(OBJS_DIR)/%.o:%.c
	@mkdir -p $(@D)
	@$(CC) $(C_FLAGS) -c $< -o $@ -Iincludes/ 
	@$(eval COMPILED_FILES := $(shell echo $$(($(COMPILED_FILES)+1))))
	@echo -n "Compiled $(COMPILED_FILES) out of $(TOTAL_FILES)"
	@echo " ($(ANSI)$(GREEN)m$(shell echo 'scale=2; $(COMPILED_FILES) / $(TOTAL_FILES) * 100' | bc)%$(ANSI)m)"

$(NAME):
	@$(CC) $(C_FLAGS) $(OBJS_ALL) $(MAIN) $(INCLUDES) -o $@
	@printf "%-20s$(ANSI)$(GREEN)m%-15s$(ANSI)m\n" "push_swap" "compiled"

tests: $(OBJS_ALL) dllist_test stack_test push_test rotate_test quick_sort

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

quick_sort:
	@$(CC) $(C_FLAGS) $(OBJS_ALL) $(TMAIN_QSORT) $(INCLUDES) -o $@
	@printf "%-10s$(ANSI)$(GREEN)m%15s$(ANSI)m\n" "quick_sort" "compiled"

rotate_test:
	@$(CC) $(C_FLAGS) $(OBJS_ALL) $(TMAIN_ROTATE) $(INCLUDES) -o $@
	@printf "%-10s$(ANSI)$(GREEN)m%15s$(ANSI)m\n" "rotate_test" "compiled"

push_test:
	@$(CC) $(C_FLAGS) $(OBJS_ALL) $(TMAIN_PUSH) $(INCLUDES) -o $@
	@printf "%-10s$(ANSI)$(GREEN)m%15s$(ANSI)m\n" "push_test" "compiled"

tests_fclean:
	@rm -rf stack_test
	@rm -f dllist_test
	@rm -f quick_sort
	@rm -f push_test
	@rm -f rotate_test
	@printf "%-20s$(ANSI)$(RED)m%-15s$(ANSI)m\n" "Tests" "removed"

clean:
	@rm -rf $(OBJS_DIR)
	@printf "%-20s$(ANSI)$(RED)m%-15s$(ANSI)m\n" "Objects" "removed"

fclean: tests_fclean clean
	@make -C sources/libft fclean
	@rm $(NAME)
	@printf "%-20s$(ANSI)$(RED)m%-15s$(ANSI)m\n" "Executables" "removed"

tests_re: tests_fclean tests


re: fclean all

.PHONY: all libft tests dllist_test tests_fclean clean fclean tests_re re

