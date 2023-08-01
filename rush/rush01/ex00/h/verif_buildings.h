#ifndef VERIF_BUILDINGS_H
#   define VERIF_BUILDINGS_H

void	split_arg(char *src, char *dst1, int key);
int		verif_building_liner(int *line, int y, char *arg, int nb);
int		verif_building_cold(int **grille, int x, char *arg, int nb);
int		verif_building_linel(int *line, int y, int x, char *arg, int nb);
int		verif_building_colu(int **grille, int x, int y, char *arg, int nb);

#endif