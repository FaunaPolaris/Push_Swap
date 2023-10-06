#include "stack.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack *stack_b;
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
	stck_disp(stack_a);
	stck_disp(stack_b);
	write(1, "\n", 1);
	stck_swap(stack_a);
	stck_swap(stack_b);
	stck_disp(stack_a);
	stck_disp(stack_b);
	write(1, "\n", 1);
	stck_push(stack_a, stack_b);
	stck_disp(stack_a);
	stck_disp(stack_b);
	write(1, "rotation tests:\n", 17);
	stck_rott_rgt(stack_a);
	stck_rott_lft(stack_b);
	stck_disp(stack_a);
	stck_disp(stack_b);
	fp_grdfre((char **)values_a);
	fp_grdfre((char **)values_b);
	stck_rmv(stack_a);
	stck_rmv(stack_b);
	return (0);
}
