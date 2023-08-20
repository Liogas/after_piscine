#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

#include "h/ft_str.h"

char    *set_file(char *file, char *dico)
{
    int     i;
    int     j;
    char    *d;

    d = "./dico/";
    file = (char *)malloc((ft_strlen(d) + ft_strlen(dico) + 1) * sizeof(char));
    if (!file)
        return NULL;
    i = 0;
    while (d[i] != '\0')
    {
        file[i] = d[i];
        i++;
    }
    j = 0;
    while (dico[j] != '\0')
    {
        file[i + j] = dico[j];
        j++;
    }
    file[i + j] = '\0';
    return (file);
}

int open_dico(char *dico)
{
    int     fd;
    char    *file;

    file = 0;
    file = set_file(file, dico);
    if (!file)
        return (1);
    fd = open(file, O_RDONLY);
    free(file);
    return (fd);
}