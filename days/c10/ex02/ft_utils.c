#include <unistd.h>

int is_num(char c)
{
    return (c >= '0' && c <= '9');
}

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] != '\0' && str2[i] != '\0' && str1[i] == str2[i])
		i++;
	return (str1[i] - str2[i]);
}

void    ft_putstr(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        write(1, &str[i], 1);
        i++;
    }
}

int	ft_strlen(char *str)
{
	int	c;

	c = 0;
	while (str[c] != '\0')
		c++;
	return (c);
}

int	ft_atoi(char *a)
{
	int number;
	int	multiple;
	int	i;
	
	number = 0;
	multiple = 1;
	i = 0;
	while (i < ft_strlen(a) - 1)
	{
		multiple *= 10;
		i++;
	}
	i = 0;
	while (a[i] != '\0')
	{
		if (!is_num(a[i]))
			return (-1);
		number += (a[i] - '0') * multiple;
		multiple /= 10;
		i++;
	}
	return (number);	
}