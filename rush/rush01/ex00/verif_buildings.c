#include "h/ft_tools.h"
#include <stdlib.h>

/*
Fonction qui récupère les arguments utiles présent dans src.
*/
void	split_arg(char *src, char *dst1, int key)
{
	int	k;
	int	size;

	k = 0;
	size = ft_strlen(src);
	while(k < size / 4)
	{
		dst1[k] = src[key];
		key++;
		k++;
	}
	dst1[k] = '\0';
}

/*
Fonction qui vérifie si la condition du nombre de building visibles
depuis la droite est respectée.
*/
int	verif_building_liner(int *line, int y, char *arg, int nb)
{
	int		i;
	int 	size;
	int		c;
	int 	max;
	char	*cond;
	int		k;

	max = 0;
	c = 0;
	k = 0;
	size = ft_strlen(arg) / 4;
	i = size - 1;
	while(i >= 0)
	{
		if (line[i] > max && line[i] != 0 && line[i] > nb)
		{
			c++;
			max = line[i];
		}
		if (line[i] != 0)
			k++;
		i--;
	}
	k++;
	c++;
	cond = (char *)malloc((size + 1) * sizeof(char));
	if (!cond)
		return (0);
	split_arg(arg, cond, ft_strlen(arg) - ft_strlen(arg) / 4);
	if ((c - (cond[y] - '0') != 0 && k == ft_strlen(cond)))
	{
		return (free(cond), (0));

	}
	return (free(cond), (1));
}

/*
Fonction qui vérifie si la condition du nombre de building visibles
depuis le bas est respectée.
*/
int	verif_building_cold(int **grille, int x, char *arg, int nb)
{
	int		i;
	int 	size;
	int		c;
	int 	max;
	char	*cond;
	int		k;

	max = 0;
	c = 0;
	k = 0;
	size = ft_strlen(arg) / 4;
	i = size - 1;
	while(i >= 0)
	{
		if (grille[i][x] > max && grille[i][x] != 0 && grille[i][x] > nb)
		{
			c++;
			max = grille[i][x];
		}
		if (grille[i][x] != 0)
			k++;
		i--;
	}
	k++;
	c++;
	cond = (char *)malloc((size + 1) * sizeof(char));
	if (!cond)
		return (0);
	split_arg(arg, cond, ft_strlen(arg) / 4);
	if (c - (cond[x] - '0') != 0 && k == ft_strlen(cond))
	{
		return (free(cond), (0));

	}
	return (free(cond), (1));
}

/*
Fonction qui vérifie si la condition du nombre de building visibles
depuis la gauche est respectée.
*/
int	verif_building_linel(int *line, int y, int x, char *arg, int nb)
{
	int		i;
	int 	size;
	int		c;
	int 	max;
	char	*cond;

	i = 0;
	max = 0;
	c = 0;
	size = ft_strlen(arg);
	while(i < size / 4)
	{
		if (line[i] > max && line[i] != 0)
		{
			c++;
			max = line[i];
		}
		i++;
	}
	if (nb > max)
		c++;
	cond = (char *)malloc((size / 4 + 1) * sizeof(char));
	if (!cond)
		return (0);
	split_arg(arg, cond, ft_strlen(arg) - ((ft_strlen(arg) / 4) * 2));
	if (c - (cond[y] - '0') > 0 
		|| (c - (cond[y] - '0') != 0 && x == ft_strlen(cond) - 1))
	{
		return (free(cond), (0));

	}
	return (free(cond), (1));
}

/*
Fonction qui vérifie si la condition du nombre de building visibles
depuis le haut est respectée.
*/
int	verif_building_colu(int **grille, int x, int y, char *arg, int nb)
{
	int		i;
	int 	size;
	int		c;
	int 	max;
	char	*cond;

	i = 0;
	max = 0;
	c = 0;
	size = ft_strlen(arg);
	while(i < size / 4)
	{
		if (grille[i][x] > max && grille[i][x] != 0)
		{
			c++;
			max = grille[i][x];
		}
		i++;
	}
	if (nb > max)
		c++;
	cond = (char *)malloc((size / 4 + 1) * sizeof(char));
	if (!cond)
		return (0);
	split_arg(arg, cond, 0);
	if (c - (cond[x] - '0') != 0 && y == size / 4 - 1)
	{
		return (free(cond), (0));

	}
	return (free(cond), (1));
}