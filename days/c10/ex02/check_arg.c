#include "./h/ft_utils.h"
#include <stdlib.h>

char	**set_files(char **argv, int size)
{
	int		i;
	int		j;
	char	**files;

	i = 1;
	j = 0;
	files = (char **)malloc((size + 1) * sizeof(char *));
	if (!files)
		return NULL;
	while (argv[i])
	{
		if (!ft_strcmp(argv[i], "-c"))
			i++;
		else
		{
			files[j] = argv[i];
			j++;
		}
		i++;
	}
	files[j] = 0;
	return (files);
}

int	check_arg(int argc, char **argv, char ***files, int *opt)
{
	int		i;
	int		nb_files;
	
	if (argc < 2)
		return (0);
	i = 1;
	nb_files = 0;
	while (argv[i])
	{
		if (!ft_strcmp(argv[i], "-c"))
		{
			if (!argv[i + 1] || *opt != 0)
				return (0);
			*opt = ft_atoi(argv[i + 1]);
			i++;
			if (*opt < 0)
				return (0);
		}
		else
			nb_files++;
		i++;
	}
	if (nb_files < 1)
		return (0);
	*files = set_files(argv, nb_files);
	if(!files)
		return (0);
	return (1);
}