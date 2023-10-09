#include "stack.h"

t_stack	*stack_a;
void	**as_voids_a;

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	as_voids_a = (void **)fp_split(argv[1], ' ');
	if (!as_voids_a)
		return (1);
	stack_a = stck_new(as_voids_a, 'a');
	stck_disp(stack_a);
	for (int size = dll_size(stack_a->front);size != 0; size--)
	{
		stck_rott_rgt(stack_a);
		stck_disp(stack_a);
	}
	return (0);
}
