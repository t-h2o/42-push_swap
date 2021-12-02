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

	// functions

int		ps_atoi(char *s);
void	ps_add_plate(plate **top, int n);
void	ps_free_stack(plate *top);
void	ps_show(plate *top);

	//	error

int		ps_is_not_digit(char *s);
int		ps_is_arg(int argc);
int		ps_check_not_same(int *tab, int i);

#endif /* PUSH_SWAP_h */
