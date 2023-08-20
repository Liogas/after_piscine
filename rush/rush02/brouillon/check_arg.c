#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

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

int check_dict(char *dico)
{
    int     fd;
    int     err;
    char    *file;

    err = 0;
    file = 0;
    file = set_file(file, dico);
    if (!file)
        return (1);
    if((fd = open(file, O_RDONLY)) == -1)
        err ++;
    free(file);
    close(fd);
    return (err);
}

int check_number(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
        i++;
    if (i == ft_strlen(str))
        return (0);
    return (1);
}

int check_arg(int argc, char **argv)
{
    int err;

    err = 0;
    if (argc < 2 || argc > 3)
        err++;
    else if (argc == 3 && !check_dict(argv[1]) && !check_number(argv[2]))
        err = -1;
    else if (argc == 2 && check_number(argv[1]))
        err++;
    return (err);
}