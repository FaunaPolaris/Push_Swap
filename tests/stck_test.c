#include "stack.h"
#include <minunit.h>

t_stack	*stack_a;
t_stack *stack_b;
void	**as_voids_a;
void	**as_voids_b;

MU_TEST(swap_test)
{
	int	first;
	int	second;

	first = stack_a->front->as_int;
	second = stack_a->front->next->as_int;

	stck_disp(stack_a);
	stck_swap(stack_a, 1);
	mu_check(stack_a->front->as_int == second);
	mu_check(stack_a->front->next->as_int == first);
	stck_disp(stack_a);



	first = stack_b->front->as_int;
	second = stack_b->front->next->as_int;

	stck_disp(stack_b);
	stck_swap(stack_b, 1);
	mu_check(stack_b->front->as_int == second);
	mu_check(stack_b->front->next->as_int == first);
	stck_disp(stack_b);
	stck_swap(stack_a, 1);
	stck_swap(stack_b, 1);
}

MU_TEST_SUITE(stack_movement_tests)
{
	MU_RUN_TEST(swap_test);
	// MU_RUN_TEST(push_test);
	// MU_RUN_TEST(rotate_test);
	// MU_RUN_TEST(reverse_rotate_test);
}

int	main(int argc, char **argv)
{

	if (argc != 3)
		return (1);
	as_voids_a = (void **)fp_split(argv[1], ' ');
	as_voids_b = (void **)fp_split(argv[2], ' ');
	if (!as_voids_a || !as_voids_b)
		return (1);
	stack_a = stck_new(as_voids_a, 'a');
	stack_b = stck_new(as_voids_b, 'b');
	MU_RUN_SUITE(stack_movement_tests);
	MU_REPORT();
	fp_grdfre((char **)as_voids_a);
	fp_grdfre((char **)as_voids_b);
	stck_rmv(stack_a);
	stck_rmv(stack_b);
	return (0);
}
