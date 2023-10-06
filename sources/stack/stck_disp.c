#include "stack.h"
#include <stdio.h>

void	stck_disp(t_stack *stack)
{
	int	stack_len;
	int	line_limit;
	t_dllist	*walker;

	if (!stack->front)
		return ;
	stack_len = dll_size(stack->front);
	walker = stack->front;
	fp_printf("stack id: %c\n", stack->id);
	if (stack_len <= 0 || !walker)
		return ;
	line_limit = sqrt(stack_len);
	for (int i = 1; walker; i++)
	{
		fp_printf("| %4i |", fp_atoi((char *)walker->value));
		if (i == line_limit)
		{
			write (1, "\n", 1);
			i = 0;
		}
		walker = walker->next;
	}
	if (stack->front && stack->back)
		fp_printf("\033[1;32m%i | %i \033[0m\n",
				fp_atoi((char *)stack->front->value),
				fp_atoi((char *)stack->back->value));
	write (1, "\n", 1);
}
