#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>

#include "h/dico.h"
#include "h/ft_str.h"

#include <stdio.h>
#include <errno.h>
#include <string.h>

#define SIZE_BUFFER 128

char    *set_line(char *buff, int start, int end)
{
    char    *str;
    int     i;

    str = (char *)malloc((end - start + 2) * sizeof(char));
    if (!str)
        return (0);
    i = 0;
    while (start <= end)
    {
        str[i] = buff[start];
        start++;
        i++;
    }
    str[i] = '\0';
    return (str);
}

char    **set_lines(char *buff, int size)
{
    int     i;
    int     j;
    char    **lines;
    int     start;

    lines = (char **)malloc((size + 1) * sizeof(char *));
    if (!lines)
        return (0);
    i = 0;
    j = 0;
    start = -1;
    while (buff[i] != '\0')
    {
        if (buff[i] != '\n' && start == -1)
            start = i;
        else if (buff[i] == '\n' && start != -1)
        {
            lines[j] = set_line(buff, start, i - 1);
            if (!lines[j])
                return (0);
            start = -1;
            j++;
        }
        i++;
    }
    lines[j] = 0;
    return (lines);
}

char    *add_buffer(char *new_buff, char *old_buff, int size)
{
    char    *buff;
    int     i;
    int     j;

    buff = (char *)malloc((SIZE_BUFFER + ft_strlen(old_buff) + 1) * sizeof(char));
    if (!buff)
        return (0);
    i = 0;
    while (old_buff[i] != '\0')
    {
        buff[i] = old_buff[i];
        i++;
    }
    j = 0;
    while (j < size)
    {
        buff[i + j] = new_buff[j];
        j++;
    }
    buff[i + j] = 0;
    return (buff);
}

int dico_parse(char ***lines, char *file, int size)
{
    int     fd;
    int     size_buff;
    char    buff[SIZE_BUFFER];
    char    *test;

    if((fd = open(file, O_RDONLY)) == -1)
        return (1);
    test = "\0";
    while ((size_buff = read(fd, buff, sizeof(buff) - 1)) > 0)
    {
        write(1, buff, size_buff);
        write(1, "\n", 1);
        test = add_buffer(buff, test, size_buff);
        if (!test)
            return (1);
    }
    *lines = set_lines(test, size);
    if (!*lines)
        return (1);
    free(test);
    return (0);
}

int dico_verif(char *file)
{
    int     nb_lines;
    char    **lines;
    int     i;

    lines = 0;
    if ((nb_lines = dico_lines(file)) < 1)
        return (1);
    if (dico_parse(&lines, file, nb_lines))
    {
        free(lines);
        return (1);
    }
    i = 0;
    while (lines[i])
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