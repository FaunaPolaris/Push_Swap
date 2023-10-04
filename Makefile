CC		=	gcc
C_FLAGS		=	-Wall -Wextra -Werror -g3 -ggdb
LIBLINK		=	-L ./sources/libft/ -lft
INCLUDES	=	-I ./includes $(LIBLINK)

SRCS_DLLIST	=	add_back.c add_frnt.c clear.c fnd_end.c new_list.c new_node.c new_rlist.c putlist.c

SRCS_ALL	=	$(addprefix sources/linked_list/dll_,$(SRCS_DLLIST))

TOTAL_FILES	:=	$(words $(SRCS_ALL))
COMPILED_FILES	:=	0

OBJS_DIR	=	objs
OBJS_ALL	=	$(addprefix $(OBJS_DIR)/,$(SRCS_ALL:.c=.o))

TMAIN_LLIST	=	tests/llist_test.c

ANSI		=	\033[0
RED		=	;31
GREEN		=	;32

all: libft $(OBJS_ALL) tests
	@printf "%-10s$(ANSI)$(GREEN)m%-15s$(ANSI)m" "all" "compiled"

libft:
	@make -C sources/libft

$(OBJS_DIR)/%.o:%.c
	@mkdir -p $(@D)
	@$(CC) $(C_FLAGS) -c $< -o $@ -Iincludes/ 
	@$(eval COMPILED_FILES := $(shell echo $$(($(COMPILED_FILES)+1))))
	@echo -n "Compiled $(COMPILED_FILES) out of $(TOTAL_FILES)"
	@echo " ($(ANSI)$(GREEN)m$(shell echo 'scale=2; $(COMPILED_FILES) / $(TOTAL_FILES) * 100' | bc)%$(ANSI)m)"

tests: $(OBJS_ALL) llist_test
	@printf "%-10s$(ANSI)$(GREEN)m%-15s$(ANSI)m\n" "Tests" "compiled"

llist_test:
	@$(CC) $(C_FLAGS) $(OBJS_ALL) $(TMAIN_LLIST) $(INCLUDES) -o $@
	@printf "%-10s$(ANSI)$(GREEN)m%-15s$(ANSI)m\n" "llist_test" "compiled"
	@printf "%10s\n" "----------"
	@printf "./llist_test [content] [type]\n"
	@printf "content should be a string with values separated by spaces\n"
	@printf "type should be a char that determines which type of content will be sent\n\n"
	@printf "c = char\ns = string\ni = int\n"
	@printf "%10s\n" "----------"

tests_fclean:
	@rm -f llist_test
	@printf "%-10s$(ANSI)$(RED)m%-15s$(ANSI)m\n" "Tests" "removed"

clean:
	@rm -rf $(OBJS_DIR)
	@printf "%-10s$(ANSI)$(RED)m%-15s$(ANSI)m\n" "Objects" "removed"

fclean: clean tests_fclean
	@make -C sources/libft fclean
	@printf "%-10s$(ANSI)$(RED)m%-15s$(ANSI)m\n" "Executables" "removed"

re: fclean all

.PHONY: all libft tests llist_test tests_fclean clean fclean re

