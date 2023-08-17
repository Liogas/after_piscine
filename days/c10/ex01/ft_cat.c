#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>

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

int	error_msg(int error, char *file)
{
	if (!error || !file)
	{
		write(1, "ft_cat: ", 8);
		ft_putstr(file);
		write(1, ": ", 2);
		ft_putstr(strerror(error));
		write(1, "\n", 1);
	}
	else
		write(1, "Error\n", 6);
	return (1);
}

void	ft_display_file(int fd)
{
	char	buf[128];
	int		strlength;

	while ((strlength = read(fd, buf, 127)) > 0)
		write(1, buf, strlength);
}

int	ft_cat(char **arg)
{
	int		i;
	int		fd;
	int 	err;

	i = 0;
	while(arg[i])
	{
		if(i != 0)
		{
			fd = open(arg[i], O_RDONLY);
			if (fd == -1)
			{
				err = errno;
				error_msg(err, arg[i]);
			}
			else
			{
				ft_display_file(fd);
				close(fd);
			}
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if(argc < 2)
		return (error_msg(0, 0));
	return (ft_cat(argv));
}