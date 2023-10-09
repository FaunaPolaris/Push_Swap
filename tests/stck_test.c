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

	first = *(int *)stack_a->front->as_void;
	second = *(int *)stack_a->front->next->as_void;

	stck_disp(stack_a);
	stck_swap(stack_a);
	mu_check(*(int *)stack_a->front->as_void == second);
	mu_check(*(int *)stack_a->front->next->as_void == first);
	stck_disp(stack_a);



	first = *(int *)stack_b->front->as_void;
	second = *(int *)stack_b->front->next->as_void;

	stck_disp(stack_b);
	stck_swap(stack_b);
	mu_check(*(int *)stack_b->front->as_void == second);
	mu_check(*(int *)stack_b->front->next->as_void == first);
	stck_disp(stack_b);
	stck_swap(stack_a);
	stck_swap(stack_b);
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
