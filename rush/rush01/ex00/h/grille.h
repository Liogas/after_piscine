#ifndef GRILLE_H
#   define GRILLE_H

int	    **init_grille(char *arg);
void	free_grille(int **grille, int size);
void    display_grille(int **grille, int size);

#endif