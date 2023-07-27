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

int	main(int argc, char **argv)
{
	char	*argf;
	int		**grille;

	if (argc != 2)
	{
		write(1, "ERROR\n", 6);
		return (1);
	}
	argf = check_error_arg(argv[1]);
	if (!argf)
	{
		write(1, "ERROR\n", 6);
		return (1);
	}
	printf("Argument final : %s\n", argf);
	printf("Taille de l'argf = %d\n", ft_strlen(argf));
	grille = init_grille(argf);
	display_grille(grille, ft_strlen(argf) / 4);
	free_grille(grille, ft_strlen(argf) / 4);
	free(argf);
	return (0);
}