int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}

int str_only_num(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
        i++;
    if (i == ft_strlen(str))
        return (0);
    return (1);
}