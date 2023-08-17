#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>

#include "./h/check_arg.h"
#include "./h/ft_utils.h"

void	error_msg_open(int err, char *file)
{
	write(1, "ft_tail: cannot open '", 22);
	ft_putstr(file);
	write(1, "' for reading: ", 15);
	ft_putstr(strerror(err));
}

int	get_size_file(int fd)
{
	char	buf[2048];
	int		str_length;
	int		final_length;
	
	final_length = 0;
	while ((str_length = read(fd, buf, sizeof(buf))) > 0)
		final_length += str_length;
	close(fd);
	return (final_length);
}

void	ft_display_file(char *file, int option, int fd)
{
	char	buf[1];
	int		file_size;
	int		str_length;
	int		err;

	file_size = get_size_file(fd);
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		err = errno;
		error_msg_open(err, file);
		write(1, "\n", 1);
	}
	else 
	{
		write(1, "==> ", 4);
		ft_putstr(file);
		write(1, " <==", 4);
		write(1, "\n", 1);
		str_length = 0;
		while ((str_length += read(fd, buf, sizeof(buf))) < file_size - option)
		{}
		while (read(fd, buf, sizeof(buf)) > 0)
			write(1, &buf[0], 1);
	}
	close(fd);
}

int	ft_tail(char **files, int option)
{
	int	i;
	int	fd;
	int	err;

	i = 0;
	while (files[i])
	{
		fd = open(files[i], O_RDONLY);
		if (fd == -1)
		{
			err = errno;
			error_msg_open(err, files[i]);
			write(1, "\n", 1);
		}
		else
		{
			ft_display_file(files[i], option, fd);
			if (files[i + 1])
				write(1, "\n", 1);
		}
		close(fd);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		option;
	char	**files;
	int 	i;
	
	option = 0;
	if (!check_arg(argc, argv, &files, &option))
		return (1);
	i = 0;
	while (files[i])
		i++;
	if (ft_tail(files, option))
		return (1);
	free(files);
	return (0);
}
