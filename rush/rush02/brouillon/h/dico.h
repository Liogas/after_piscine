#ifndef DICO_H
#   define DICO_H

char    *set_file(char *file, char *dico);
int     open_dico(char *dico);
typedef struct S_DICO
{
    int     key;
    char    *value;
    struct S_DICO  *next;
} T_DICO;

#endif