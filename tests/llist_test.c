#include "llist.h"

int	main(int argc, char **argv)
{
	t_dllist	*normal_list;
	t_dllist	*reverse_list;
	void		**values;

	if (argc != 3)
		return (1);
	values = (void **)fp_split(argv[1], ' ');
	normal_list = dll_new_list(values);
	reverse_list = dll_new_rlist(values);
	dll_putlist(normal_list, argv[2][0], 1);
	write(1, "\n", 1);
	dll_putlist(reverse_list, argv[2][0], 1);
	dll_clear(&normal_list);
	dll_clear(&reverse_list);
	for (int i = 0; values[i]; i++)
		free(values[i]);
	free(values);
	return (0);
}
