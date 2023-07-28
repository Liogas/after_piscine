#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "h/check_arg.h"
#include "h/ft_tools.h"
#include "h/grille.h"

/*
Mettre en place la fonction de backtracking
1. Fonctionne uniquement par ligne
2. Fonctionne avec les colonnes en plus des lignes
3. Vérifie si le nombre de batiments visibles est ok
*/

int	verif_line(int **grille, char *arg, int pos, int nb)
{
	int	y;
	int	i;

	y = pos / (ft_strlen(arg) / 4);
	i = 0;
	while (i < ft_strlen(arg) / 4)
	{
		if(grille[y][i] == nb){
			return (0);
		}
		i++;
	}
	return (1);
}

int	get_size_building(int **grille, char * arg, int pos)
{
	printf("- Fonction gez_size_building -> ");
	int	i;

	i = 1;
	while (i <= ft_strlen(arg) / 4)
	{
		printf("Je travaille avec un batiment de taille : %d\n", i);
		if (verif_line(grille, arg, pos, i))
		{
			return (i);
		}
		i++;
	}
	return (0);
}

int ft_backtracking(int **grille, char *arg, int pos)
{
	printf("--- Entrée n°%d dans la fonction backtracking ---\n", pos + 1);
	int	y;
	int	x;
	
	printf("Arguments donnés: ARG = %s | POS = %d\n", arg, pos);
	printf("Etat de la grille au départ : \n");
	display_grille(grille, ft_strlen(arg) / 4);
	if (pos == ft_strlen(arg))
	{
		printf("Grille pleine\n");
		display_grille(grille, ft_strlen(arg) / 4);
		return (1);
	}
	y = pos / (ft_strlen(arg) / 4);
	x = pos % (ft_strlen(arg) / 4);
	printf("y = %d | x = %d\n", y, x);
	if (grille[y][x] != 0)
	{
		printf("Case déjà remplie\n");
		return (ft_backtracking(grille, arg, pos + 1));
	}
	grille[y][x] = get_size_building(grille, arg, pos);
	printf("Nouvelle valeur de la case : %d\n", grille[y][x]);
	if (grille[y][x] == 0)
	{
		printf("Pas de possibilité\n");
		return (0);
	}
	printf("On continue le boulot !\n");
	return (ft_backtracking(grille, arg, pos + 1));
}

int	error_msg()
{
	write(1, "ERROR\n", 6);
	return (1);
}

int	main(int argc, char **argv)
{
	char	*argf;
	int		**grille;
	int		size;

	if (argc != 2)
		return (error_msg());
	argf = check_error_arg(argv[1]);
	if (!argf)
		return (error_msg());
	(printf("Argument final : %s\n", argf), printf("Taille de l'argf = %d\n", ft_strlen(argf)));
	size = ft_strlen(argf) / 4;
	grille = init_grille(argf);
	printf("Initialisation de la grille terminée\n");
	display_grille(grille, size); 
	if (!ft_backtracking(grille, argf, 0))
	{
		free_grille(grille, size);
		free(argf);
		printf("La grille n'a pas de solution\n");
		return (error_msg());
	}
	free_grille(grille, size);
	free(argf);
	return (0);
}