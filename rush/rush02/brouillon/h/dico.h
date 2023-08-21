#ifndef DICO_H
#   define DICO_H

char    *set_file(char *dico);
int     open_dico(char *dico);
int     dico_lines(char *file);

typedef struct S_DICO
{
    int     key;
    char    *value;
    struct S_DICO  *next;
} T_DICO;

#endif