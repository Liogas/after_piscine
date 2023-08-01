#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "h/check_arg.h"
#include "h/ft_tools.h"
#include "h/grille.h"
#include "h/verif_buildings.h"
#include "h/ft_backtracking.h"

/* 
Fonction qui affiche le message d'erreur à la console.
*/
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
	size = ft_strlen(argf) / 4;
	grille = init_grille(argf);
	if (!ft_backtracking(grille, argf, 0))
	{
		free_grille(grille, size);
		free(argf);
		return (error_msg());
	}
	free_grille(grille, size);
	free(argf);
	return (0);
}