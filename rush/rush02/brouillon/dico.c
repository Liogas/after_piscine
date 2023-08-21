#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

#include "h/ft_str.h"
#include "h/ft_char.h"

#include <stdio.h>
#include <errno.h>
#include <string.h>

char    *set_file(char *dico)
{
    int     i;
    int     j;
    char    *d;
    char    *file;

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
    int     err;

    if (!dico)
        return (1);
    fd = open(dico, O_RDONLY);
    if (fd == -1)
    {
        err = errno;
        printf("%s\n", strerror(err));
        err = 1;
    }
    return (fd);
}

int dico_lines(char *file)
{
    int     i;
    int     lines;
    int     fd;
    char    buff[128];
    int     size;

    fd = open_dico(file);
    if (!fd)
        return (1);
    lines = 1;
    while ((size = read(fd, buff, sizeof(buff) - 1)) > 0)
    {
        i = 0;
        while (i < size)
        {
            if (buff[i] == '\n')
            {
                while (buff[i + 1] == '\n')
                    i++;
                if (is_printable(buff[i + 1]))
                    lines++;
            }
            i++;
        }
    }
    return ((close(fd), lines));
}