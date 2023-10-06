#include "stack.h"

t_stack	*stack_a;
t_stack *stack_b;

int	main(int argc, char **argv)
{
	void	**values_a;
	void	**values_b;

	if (argc != 3)
		return (1);
	values_a = (void **)fp_split(argv[1], ' ');
	values_b = (void **)fp_split(argv[2], ' ');
	if (!values_a || !values_b)
		return (1);
	stack_a = stck_new(values_a, 'a');
	stack_b = stck_new(values_b, 'b');
	st_test_swap();
	st_test_push();
	st_test_rotate();
	st_tests_reverse_rotate();
	st_tests_doubles();
	fp_grdfre((char **)values_a);
	fp_grdfre((char **)values_b);
	stck_rmv(stack_a);
	stck_rmv(stack_b);
	return (0);
}

static void	st_test_swap(void)
{
	fp_printf("initializing swap tests");
}
