#include <stdio.h>
#include <stdlib.h>
#include "h/ft_tools.h"

/* 
Fonction qui récupère le nombre de chiffres compris entre 
1 et 9 présents dans l'argument donné au lancement du programme.
Si ce nombre dépasse la taille max -> format[6] * 4 = 36. La fonction
return 0 pour prévenir d'une erreur.
*/
int	check_strlen_arg(char *str, int *format)
{
	int	c;
	int	i;

	c = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (ft_is_num(str[i]))
		{
			c++;
			if (c > format[6] * 4)
				return (0);
		}
		i++;
	}
	return (c);
}

/*
Fonction qui vérifie  qu'aucun des chiffres présents dans l'argument
dépassent la taille max possible
*/
int check_max_arg(char *arg, int max)
{
	int	i;

	i = 0;
	while (arg[i] != '\0')
	{
		if ((int)arg[i] - '0' < 0 || (int)arg[i] - '0' > max )
		{
			// printf("arg[%d] contient : %c qui est supérieur à la taille max : %d\n", i, arg[i], max);
			return (0);
		}
		i++;
	}
	return (1);
}

/*
Fonction qui stock les chiffres utiles dans la chaine argf (représente
l'argument final), elle sera utile au lancement de l'algorithme.
*/
void	set_argf(char *arg, char *argf)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (arg[i] != '\0')
	{
		if (ft_is_num(arg[i]))
		{
			argf[k] = arg[i];
			k++;
		}
		i++;
	}
	argf[k] = '\0';
}

/*
Fonction qui permet de vérifier si la chaine d'argument respecte
l'un des formats autorisés par l'algorithme.
*/
int	check_format_arg(char *arg, char *argf, int size)
{
	int		i;
	int		format[7];

	init_format(format);
	// printf("Chiffres présents dans l'arguments : %d\n", size);
	i = 0;
	while (i < 7)
	{
		if (size == format[i] * 4)
		{
			// printf("size(%d) == format[%d](%d) * 4 = %d\n", size, i, format[i], format[i] * 4);
			set_argf(arg, argf);
			if (check_max_arg(argf, format[i]) == 1)
			{
				// printf("L'algorithme fonctionnera avec le format de grille %d*%d\n", format[i], format[i]);
				// printf("FORMAT OK\n");
				return (1);
			}
		}
		i++;
	}
	// printf("L'argument donné ne respecte pas le format\n");
	return (0);
}

/*
Fonction qui renvoie l'argument final si aucune erreur rencontrée,
ou NULL en cas d'erreur.
*/
char	*check_error_arg(char *arg)
{
	char	*argf;
	int		size;
	int		format[7];

	init_format(format);
	size = check_strlen_arg(arg, format);
	if (size < 12 || size > 36)
		return NULL; 
	argf = (char *)malloc((size + 1) + sizeof(char));
	if (!argf || check_format_arg(arg, argf, size) == 0)
	{
		free(argf);
		return NULL;
	}
	return (argf);
}
