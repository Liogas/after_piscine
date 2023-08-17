#ifndef CHECK_ARG_H
#   define CHECK_ARG_H

char	**set_files(char **argv, int size);
int	    check_arg(int argc, char **argv, char ***files, int *opt);

#endif