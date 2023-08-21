#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>

#include "h/dico.h"
#include "h/ft_str.h"

#include <stdio.h>
#include <errno.h>
#include <string.h>

char *set_line(char *buff, int start, int end)
{
    char    *str;
    int     i;

    str = (char *)malloc((end - start + 2) * sizeof(char));
    if (!str)
        return 0;
    i = 0;
    while (start <= end)
    {
        str[i] = buff[start];
        i++;
        start++;
    }
    return (str);
}

/*
var[0] = i
var[1] = fd
var[2] = size use on read
var[3] = start
var[4] = end
*/
int dico_parse_file(char ***lines, char *file)
{
    int     var[5];
    char    buff[128];
    int     k;
    int     err;

    if((var[1] = open(file, O_RDONLY)) == -1)
    {
        printf("FIle = %s\n", file);
        printf("erreur ouverture\n");
        err = errno;
        printf("%s\n", strerror(err));
        return (1);
    }
    k = 0;
    while ((var[2] = read(var[1], buff, sizeof(buff) - 1)) > 0)
    {
        var[0] = 0;
        var[3] = -1;
        var[4] = -1;
        while (var[0] < var[2])
        {
            if (buff[var[0]] != '\n' && var[3] == -1)
                var[3] = var[0];
            else if (buff[var[0]] == '\n' && var[3] != -1)
            {
                *lines[k] = set_line(buff, var[3], var[0] - 1);
                var[3] = -1;
                k++;
            }
            var[0]++;
        }
    }
    return (0);
}

int dico_verif(char *file)
{
    int     nb_lines;
    char    **lines;
    int     i;

    printf("Nom du file = %s\n", file);
    if ((nb_lines = dico_lines(file)) < 1)
        return (1);
    printf("nb_lines = %d\n", nb_lines);
    lines = (char **)malloc((nb_lines + 1) * sizeof(char *));
    if (!lines)
        return (1);
    printf("Nom du file = %s\n", file);
    if (dico_parse_file(&lines, file))
    {
        printf("ERReur dico_parse_file\n");
        return (1);
    }
    i = 0;
    while (i < nb_lines)
    {
        printf("lines[%d] = %s\n", i, lines[i]);
        i++;
    }
    i = 0;
    while (i < nb_lines)
    {
        free(lines[i]);
        i++;
    }
    free(lines);
    return (0);
}   