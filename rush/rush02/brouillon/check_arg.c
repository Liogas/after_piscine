#include "h/dico.h"
#include "h/ft_str.h"

#include <stdio.h>

int check_arg(int argc, char **argv)
{
    int err;

    err = 0;
    if (argc < 2 || argc > 3)
        err++;
    else if (argc == 3 && open_dico(set_file(argv[1])) != -1 && !str_only_num(argv[2]))
        err = -1;
    else if (argc == 2 && str_only_num(argv[1]))
        err++;
    else if (argc == 3 && (open_dico(set_file(argv[1])) == -1 || str_only_num(argv[2])))
        err++;
    return (err);
}