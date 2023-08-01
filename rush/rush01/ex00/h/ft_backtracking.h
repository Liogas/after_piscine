#ifndef FT_BACKTRACKING_H
#   define FT_BACKTRACKING_H

int	verif_line(int **grille, char *arg, int pos, int nb);
int	verif_col(int **grille, char *arg, int pos, int nb);
int ft_backtracking(int **grille, char *arg, int pos);

#endif