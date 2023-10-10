#include "stack.h"

int	stck_push_all(t_stack *from, t_stack *to)
{
	int	size;

	if (!from || !from->front || !to)
		return (0);
	size = dll_size(from->front);
	while (size--)
		stck_push(from, to);
	return (1);
}
