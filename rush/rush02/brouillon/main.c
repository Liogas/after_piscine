#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>

#include "h/check_arg.h"
#include "h/error_msg.h"
#include "h/dico.h"
#include "h/ft_str.h"
#include "h/dico_parse.h"

#include <stdio.h>
#include <errno.h>
#include <string.h>


int rush02(char *dico, char *number)
{
    char    *file;
    // int     nb;
    int     err;

    (void)number;
    file = set_file(dico);
    if (!file)
        return (1);
    err = 0;
    // nb = ft_atoi(number);
    // printf("%s\n", file);
    if (dico_verif(file))
        err++;
    free(file);
    return (err);
}

int main(int argc, char **argv)
{
    int err;

    err = 0;
    if((err = check_arg(argc, argv)) > 0)
        ARG_MSG()
    else if(err == -1)
    {
        err = 0;
        if (rush02(argv[1], argv[2]))
            err++;
    }
    else
    { 
        if(rush02("number.dict", argv[1]))
            err++;
    }
    if (!err)
        write(1, "Aucune erreur\n", 14);
    return (err);
}