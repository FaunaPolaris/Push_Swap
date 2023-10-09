#include "stack.h"

t_stack	*stack_a;
void	**as_voids_a;
t_stack	*stack_b;

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	as_voids_a = (void **)fp_split(argv[1], ' ');
	if (!as_voids_a)
		return (1);
	stack_a = stck_new(as_voids_a, 'a');
	stack_b = stck_new(NULL, 'b');
	stck_disp(stack_a);
	for (int size = dll_size(stack_a->front);size != 0; size--)
	{
		stck_push(stack_a, stack_b);
	}
	for (int size = dll_size(stack_b->front);size != 0; size--)
	{
		stck_push(stack_b, stack_a);
	}
	stck_disp(stack_a);
	stck_disp(stack_b);
}
