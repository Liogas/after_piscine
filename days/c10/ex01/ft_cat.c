#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>


int	error_msg()
{
	write(1, "Error\n", 6);
	return (1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while(str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int file_error_msg(int error, char *file)
{
	write(1, "ft_cat: ", 8);
	ft_putstr(file);
	switch (error)
	{
		case EACCES:
			write(1,": Permission denied\n", 20);

	};
	return (1);
}

int	ft_cat(char **arg, int size)
{
	int		i;
	int		fd;
	char	buf[128];
	int		strlength;
	int 	err;

	i = 0;
	while(i < size)
	{
		if(i != 0)
		{
			fd = open(arg[i], O_RDONLY);
			if (fd == -1)
			{
				err = errno;
				return (file_error_msg(err, arg[i]));
			}
			while ((strlength = read(fd, buf, 127)) > 0)
				write(1, buf, strlength);
			close(fd);
		}
		i++;
	}
	return (0);
}

int check_arg(int argc, char **argv)
{
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;
	int	err;
	if(argc < 2)
		return (error_msg());
	if (check_arg(argc, argv))
		return (error_msg());
	return (ft_cat(argv, argc));
}