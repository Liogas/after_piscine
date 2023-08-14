#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

void	ft_display_file(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		write(1, "Cannot read file.\n", 18);
		return ;
	}
	write(1, "En attente de la suite\n", 23);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		write(1, "File name missing.\n", 19);
		return (1);
	}
	else if (argc > 2)
	{
		write(1, "Too many arguments.\n", 20);
		return (1);
	}
	ft_display_file(argv[1]);
	return (0);
}