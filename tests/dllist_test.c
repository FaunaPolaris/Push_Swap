#include "llist.h"
// #include <minunit.h>

int	arg_size;

void	dll_test_next_prev_pointers(t_dllist *head)
{
	t_dllist	*aux = head;
	int	i = 0;

	while (aux)
	{
		i++;
		aux = aux->next;
	}
	if (i != arg_size)
	{
		fp_printf("Reference lost on node %i\n", i);
		return ;
	}
	aux = dll_fnd_back(head);
	i = 0;
	while (aux)
	{
		i++;
		aux = aux->prev;
	}
	if (i != arg_size)
	{
		fp_printf("Back reference lost on node %i\n", i);
	}
}

int	main(int argc, char **argv)
{
	t_dllist	*normal_list;
	t_dllist	*reverse_list;
	void		**values;

	if (argc != 3)
		return (1);
	values = (void **)fp_split(argv[1], ' ');
	arg_size = fp_grdlen((char **)values);
	normal_list = dll_new_list(values);
	reverse_list = dll_new_rlist(values);
	dll_putlist(normal_list, argv[2][0], 1);
	fp_printf("highest value: %i\n", dll_highest(normal_list));
	fp_printf("lowest value: %i\n", dll_lowest(normal_list));
	fp_printf("median value: %i\n", dll_mediam(normal_list));

	write(1, "\n", 1);

	dll_putlist(reverse_list, argv[2][0], 1);
	fp_printf("highest value: %i\n", dll_highest(reverse_list));
	fp_printf("lowest value: %i\n", dll_lowest(reverse_list) );
	fp_printf("median value: %i\n", dll_mediam(reverse_list));

	dll_test_next_prev_pointers(normal_list);
	dll_test_next_prev_pointers(reverse_list);
	dll_clear(&normal_list);
	dll_clear(&reverse_list);
	for (int i = 0; values[i]; i++)
		free(values[i]);
	free(values);
	return (0);
}
