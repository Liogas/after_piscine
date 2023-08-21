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

int ft_atoi(char *str)
{
    int result;
    int multiple;
    int i;

    result = 0;
    multiple = 1;
    i = 0;
    while (str[i + 1] != '\0')
    {
        multiple *= 10;
        i++;
    }
    i = 0;
    while (str[i] != '\0')
    {
        result += (str[i] - '0') * multiple;
        multiple /= 10;
        i++;
    }
    return (result);
}
