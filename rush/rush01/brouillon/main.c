#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "h/check_arg.h"

int	main(int argc, char **argv)
{
	char	*argf;

	if (argc != 2)
	{
		write(1, "ERROR\n", 6);
		return (1);
	}
	argf = check_error_arg(argv[1]);
	if (!argf)
	{
		write(1, "ERROR\n", 6);
		return (1);
	}
	printf("Argument final : %s\n", argf);
	free(argf);
	return (0);
}