
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	init_format(int *tab)
{
	tab[0] = 4;
	tab[1] = 5;
	tab[2] = 6;
	tab[3] = 7;
	tab[4] = 8;
	tab[5] = 9;
}

int	ft_is_num(char c)
{
	return (c >= '1' && c <= '9');
}

int	ft_strlen_arg(char *str, int *format)
{
	int	c;
	int	i;

	c = 0;
	i = 0;
	while(str[i] != '\0')
	{
		if (ft_is_num(str[i]))
		{
			c++;
			if(c > format[5] * 4)
				return (0);
		}
		i++;
	}
	return (c);
}

void	set_argf(int size, char *arg, char *argf)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	printf("size = %d\n", size);
	while(arg[i] != '\0')
	{
		if(ft_is_num(arg[i]))
		{
			argf[k] = arg[i];
			k++;
		}
		i++;
	}
	argf[k] = '\0';
}

int check_max(char *arg, int max)
{
	int	i;

	i = 0;
	while (arg[i] != '\0')
	{
		if((int)arg[i] - '0' < 0 || (int)arg[i] - '0' > max )
		{
			printf("arg[%d] contient : %c qui est supérieur à la taille max : %d\n", i, arg[i], max);
			return (0);
		}
		i++;
	}
	return (1);
}

int	set_format_arg(char *arg, char *argf, int size)
{
	int		i;
	int		format[6];

	init_format(format);
	printf("Chiffres présents dans l'arguments : %d\n", size);
	i = 0;
	while (i < 6)
	{
		if (size == format[i] * 4)
		{
			printf("size(%d) == format[%d](%d) * 4 = %d\n", size, i, format[i], format[i] * 4);
			set_argf(size, arg, argf);
			if (check_max(argf, format[i]) == 1)
			{
				printf("L'algorithme fonctionnera avec le format de grille %d*%d\n", format[i], format[i]);
				printf("FORMAT OK\n");
				return (1);
			}
		}
		i++;
	}
	printf("L'argument donné ne respecte pas le format\n");
	return (0);
}

int	check_error_arg(char *arg)
{
	char	*argf;
	int		size;
	int		format[6];

	init_format(format);
	size = ft_strlen_arg(arg, format);
	if (size < 16 || size > 36)
		return (1); 
	argf = (char *)malloc((size + 1) + sizeof(char));
	if (!argf || set_format_arg(arg, argf, size) == 0)
	{
		free(argf);
		return (1);
	}
	printf("Arg final récupéré : %s\n", argf);
	free(argf);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc != 2 || check_error_arg(argv[1]))
	{
		write(1, "ERROR\n", 6);
		return (1);
	}
	return (0);
}