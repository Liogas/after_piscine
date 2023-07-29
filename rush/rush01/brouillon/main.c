#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "h/check_arg.h"
#include "h/ft_tools.h"
#include "h/grille.h"

/*
Mettre en place la fonction de backtracking
1. Fonctionne uniquement par ligne -> OK
2. Fonctionne avec les colonnes en plus des lignes
3. Vérifie si le nombre de batiments visibles est ok
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
	printf("Valeur final de l'arg : %s\n", dst1);
}

void	display_line(int *line, int size)
{
	int	i;

	i = 0;
	printf("Ma ligne possède : ");
	while (i < size)
	{
		printf("%2d", line[i]);
		i++;
	}
	printf("\n");
}

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
	size = ft_strlen(arg);
	i = size / 4 - 1;
	printf("Entrée dans verif_building_liner\n");
	printf("Size = %d\n", size);
	display_line(line, ft_strlen(arg) / 4);
	while(i >= 0)
	{
		printf("Valeur de i = %d\n", i);
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
	printf("Case remplies : %d\n", k);
	c++;
	cond = (char *)malloc((size / 4 + 1) * sizeof(char));
	if (!cond)
		return (0);
	split_arg(arg, cond, ft_strlen(arg) - ft_strlen(arg) / 4);
	printf("cond = %s\n", cond);
	printf("batiment(s) visible(s) -> %d\n", c);
	printf("Je regarde -> %c\n", cond[y]);
	if ((c - (cond[y] - '0') > 0 && max == 4)
		|| (c - (cond[y] - '0') != 0 && k == ft_strlen(cond)))
	{
		printf("Sortie de verif_building_linel\n");
		printf("Condition non remplie\n");
		return (free(cond), (0));

	}
	printf("Sortie de verif_building_linel\n");
	return (free(cond), (1));
}

int	verif_building_linel(int *line, int y, char *arg, int nb)
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
	printf("Entrée dans verif_building_linel\n");
	printf("Size = %d\n", size);
	display_line(line, ft_strlen(arg) / 4);
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
	printf("batiment(s) visible(s) -> %d\n", c);
	printf("Je regarde -> %c\n", cond[y]);
	if (c - (cond[y] - '0') > 0)
	{
		printf("Sortie de verif_building_linel\n");
		printf("Condition non remplie\n");
		return (free(cond), (0));

	}
	printf("Sortie de verif_building_linel\n");
	return (free(cond), (1));
}

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

/*int	get_size_building(int **grille, char * arg, int pos)
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
}*/

int ft_backtracking(int **grille, char *arg, int pos)
{
	int		y;
	int		x;
	int		i;

	printf("Travail sur la position n°%d de la grille\n", pos);
	display_grille(grille, ft_strlen(arg) / 4);
	printf("%d | %d\n", pos, (ft_strlen(arg) / 4) * (ft_strlen(arg) / 4));
	// if (pos == (ft_strlen(arg) / 4) * 2 + 1)
	if (pos == (ft_strlen(arg) / 4) * (ft_strlen(arg) / 4))
	{        
		printf("GRILLE PLEINE\n");		
		return (1);
	}
	y = pos / (ft_strlen(arg) / 4);
	x = pos % (ft_strlen(arg) / 4);
    if (grille[y][x] != 0)
		return (ft_backtracking(grille, arg, pos + 1));
	i = 1;
	while (i <= ft_strlen(arg) / 4)
    {
		printf("Insertion de %d dans grille[%d][%d]\n", i, y, x);
		display_grille(grille, ft_strlen(arg) / 4); 
        if (verif_line(grille, arg, pos, i) 
			&& verif_building_linel(grille[y], y, arg, i)
			&& verif_building_liner(grille[y], y, arg, i))
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