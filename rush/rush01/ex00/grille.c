#include <stdlib.h>
#include <stdio.h>
#include "h/ft_tools.h"

/*
Fonction qui initialise la grille grâce à l'argument donné
en paramètre.
*/
int	**init_grille(char *arg)
{
	int	**grille;
	int	size;
	int	i;
	int j;

	size = ft_strlen(arg) / 4;
	grille = (int **)malloc(size * sizeof(int *));
	if (!grille)
		return (NULL);
	i = -1;
	while (i++ < size - 1)
	{
		grille[i] = (int *)malloc(size * sizeof(int));
		if (!grille[i])
		{
			free(grille);
			return (NULL);
		}
		j = -1;
		while (j++ < size - 1)
		{
			grille[i][j] = 0;
		}
	}
	return (grille);
}

/*
Fonction qui libère la mémoire allouée pour la grille.
*/
void	free_grille(int **grille, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(grille[i]);
		i++;
	}
	free(grille);
}

/*
Fonction qui affiche à la console la grille
*/
void    display_grille(int **grille, int size)
{
    int i;
    int j;

    i = 0;
	while (i < size)
	{
		j = 0;
		while(j < size)
		{
			printf("%2d", grille[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
