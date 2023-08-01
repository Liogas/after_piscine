#ifndef CHECK_ARG_H
#   define CHECK_ARG_H

int	    check_strlen_arg(char *str, int *format);
int     check_max_arg(char *arg, int max);
void	set_argf(int size, char *arg, char *argf);
int	    check_format_arg(char *arg, char *argf, int size);
char	*check_error_arg(char *arg);

#endif