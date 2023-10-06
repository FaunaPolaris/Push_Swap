#include "stack.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack *stack_b;
	void	**values_a;
	void	**values_b;

	if (argc != 4)
		return (1);
	values_a = (void **)fp_split(argv[1], ' ');
	values_b = (void **)fp_split(argv[2], ' ');
	if (!values_a || !values_b)
		return (1);
	stack_a = stck_new(values_a, 'a');
	stack_b = stck_new(values_b, 'b');
	dll_putlist(stack_a->front, argv[3][0], 1);
	dll_putlist(stack_b->front, argv[3][0], 1);
	write(1, "\n", 1);
	stck_swap(stack_a);
	stck_swap(stack_b);
	dll_putlist(stack_a->front, argv[3][0], 1);
	dll_putlist(stack_b->front, argv[3][0], 1);
	write(1, "\n", 1);
	stck_push(stack_a, stack_b);
	dll_putlist(stack_a->front, argv[3][0], 1);
	dll_putlist(stack_b->front, argv[3][0], 1);

	fp_grdfre((char **)values_a);
	fp_grdfre((char **)values_b);
	stck_rmv(stack_a);
	stck_rmv(stack_b);
	return (0);
}
