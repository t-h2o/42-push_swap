#include	"get_next_line.h"

int	main(int a, char ** b)
{
	printf("%s\n", b[1]);
	char *ptr;
	ptr = get_next_line(0);
	printf("%s\n", ptr);
	free(ptr);
}
