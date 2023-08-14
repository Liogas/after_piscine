
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
			write(1, "[space]", 7);
		else
			write(1, &str[i], 1);
		i++;
	}
}

int	is_charset(char *str, char *charset, int indice)
{
	int	i;

	i = 0;
	while(str[indice] != '\0' && str[indice] == charset[i] && charset[i] != 0)
	{
		i++;
		indice++;
	}
	if (i == ft_strlen(charset))
		return (1);
	return (0);
}

int	count_word(char *str, char *charset)
{
	int	i;
	int	count;
	int	nw;

	i = 0;
	count = 0;
	nw = 1;
	while (str[i] != '\0')
	{
		if (is_charset(str, charset, i))
		{
			i += ft_strlen(charset) - 1;
			if (!nw)
				nw = 1;
		}
		else if (nw)
		{
			count++;
			nw = 0;
		}
		i++;
	}
	return (count);
}

char	*get_word(char *str, int start, int end)
{
	char	*word;
	int		i;

	printf("end(%d) - start(%d) + 2 = %d\n", end, start, end - start + 2);
	word = (char *)malloc((end - start + 2) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (start < end)
	{
		word[i] = str[start];
		start++;
		i++;
	}
	word[i] = '\0';
	return (word);
}

char **ft_split(char *str, char *charset)
{
	int		nb_words;
	int		i;
	int		k;
	int		start;
	char	**tab;

	nb_words = count_word(str, charset);
	tab = (char **)malloc((nb_words + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	start = -1;
	i = 0;
	k = 0;
	while (str[i] != '\0')
	{
		if (!is_charset(str, charset, i) && start == -1)
				start = i + 1;
		else if (is_charset(str, charset, i) && start != -1)
		{
			tab[k] = get_word(str, start, i);
			if (!tab[k])
				return (NULL);
			start = -1;
			k++;
		}
		i++;
	}
	tab[k] = 0;
	return (tab);
}


int	main(void)
{
	char	*str;
	char	*charset;
	char	**tab;
	int		i;

	str = " :) batman :) septembre :) joshua :) :) : :) :) :) ";
	charset = ":)";
	tab = ft_split(str, charset);
	if (!tab)
		return (1);
	// AFFICHAGE DU TABLEAU :
	i = 0;
	while (tab[i])
	{
		putstr(tab[i]);
		write(1, "\n", 1);
		i++;
	}
	i = 0;
	while (tab[i])
	{
		printf("Tentative de free\n");
		free(tab[i]);
		i++;
	}
	free(tab);
	return (0);
}