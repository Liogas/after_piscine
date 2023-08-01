#include "h/grille.h"
#include "h/verif_buildings.h"
#include "h/ft_tools.h"

/*
Fonction qui vérifie si le chiffre a insérer dans la grille
est déjà présent sur la ligne ou non.
*/
int	verif_line(int **grille, char *arg, int pos, int nb)
{
	int		y;
	int		i;

	y = pos / (ft_strlen(arg) / 4);
	i = 0;
	while (i < ft_strlen(arg) / 4)
	{
		if (grille[y][i] == nb){
			return (0);
		}
		i++;
	}
	return (1);
}

/*
Fonction qui vérifie si le chiffre a insérer dans la grille
est déjà présent sur la colonne ou non.
*/
int	verif_col(int **grille, char *arg, int pos, int nb)
{
	int		x;
	int		i;

	x = pos % (ft_strlen(arg) / 4);
	i = 0;
	while (i < ft_strlen(arg) / 4)
	{
		if (grille[i][x] == nb){
			return (0);
		}
		i++;
	}
	return (1);
}

/*
Fonction de backtracking qui s'occupe du remplissage de la grille.
*/
int ft_backtracking(int **grille, char *arg, int pos)
{
	int		y;
	int		x;
	int		i;

	if (pos == (ft_strlen(arg) / 4) * (ft_strlen(arg) / 4))
	{        
		display_grille(grille, ft_strlen(arg) / 4);	
		return (1);
	}
	y = pos / (ft_strlen(arg) / 4);
	x = pos % (ft_strlen(arg) / 4);
    if (grille[y][x] != 0)
		return (ft_backtracking(grille, arg, pos + 1));
	i = 1;
	while (i <= ft_strlen(arg) / 4)
    {
        if (verif_line(grille, arg, pos, i) && verif_col(grille, arg, pos, i)
			&& verif_building_colu(grille, x, y, arg, i)
			&& verif_building_cold(grille, x, arg, i)
			&& verif_building_linel(grille[y], y, x, arg, i)
			&& verif_building_liner(grille[y], y, arg, i)
			)
        {
            grille[y][x] = i;
            if (ft_backtracking(grille, arg, pos + 1))
	                return (1);
        }
		grille[y][x] = 0;
		i++;
    }
    return (0);
}