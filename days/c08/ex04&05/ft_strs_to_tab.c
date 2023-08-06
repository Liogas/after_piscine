#include "ft_stock_str.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int ft_strlen(char *str)
{
	int	i;

	i = 0;
	while(str[i] != '\0')
		i++;
	return (i);
}

void	ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	
	dest[i] = '\0';
}

struct s_stock_str *ft_strs_to_tab(int ac, char **av)
{
    int	i;
	t_stock_str *tab;
	tab = (t_stock_str *)malloc((ac + 1) * sizeof(t_stock_str));
	if (!tab)
		return (NULL);
	i = 0;
	while(i < ac)
	{
		tab[i].size = ft_strlen(av[i]);
		tab[i].str = (char *)malloc((tab[i].size + 1) * sizeof(char));
		if (!tab[i].str)
			return (NULL);
		tab[i].copy = (char *)malloc((tab[i].size + 1) * sizeof(char));
		if (!tab[i].copy)
			return (NULL);
		ft_strcpy(tab[i].str, av[i]);
		ft_strcpy(tab[i].copy, tab[i].str);
		i++;
	}
	tab[i].str = 0;
	return (tab);
}

void	show_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	show_int(int nb)
{
	char	c;
	if (nb >= 10)
	{
		show_int(nb / 10);
		show_int(nb % 10);
	}
	else
	{
		c = nb + '0';
		write(1, &c, 1);
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while(par[i].str)
	{
		show_str(par[i].str);
		show_int(par[i].size);
		write(1, "\n", 1);
		show_str(par[i].copy);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stock_str *tab = ft_strs_to_tab(argc, argv);
	int i = 0;
	ft_show_tab(tab);
	while (i < argc)
	{
		free(tab[i].copy);
		free(tab[i].str);
		i++;
	}
	free(tab);
	return (0);
}