#ifndef PUSH_SWAP_h

# define PUSH_SWAP_h

	// include

# include	<stdio.h>
# include	<stdlib.h>

	// list

typedef struct s_list plate;

struct s_list {
	int		n;
	plate	*up;
	plate	*down;
};


	// to remove

void	ps_scan(plate **a, plate **b);

	// functions

int		ps_atoi(char *s);
int		ps_argc_to_stack(int argc, char **argv, plate **topa);

void	ps_add_plate(plate **top, int n);
void	ps_free_stack(plate *top);
void	ps_show(plate *topa, plate *topb);

void	ps_rotate(plate **a);
void	ps_swap(plate *x);

	//	error

int		ps_is_not_digit(char *s);
int		ps_is_arg(int argc);
int		ps_check_not_same(int *tab, int i);

#endif /* PUSH_SWAP_h */
