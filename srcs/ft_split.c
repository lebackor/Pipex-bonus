/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebackor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:33:27 by lebackor          #+#    #+#             */
/*   Updated: 2022/05/17 14:33:31 by lebackor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static int	create_tab(char const *s, char c)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (s[i])
	{
		if (((s[i - 1] == c || i == 0) && s[i] != c) && s[i])
			size++;
		i++;
	}
	return (size);
}

static char	*put_str_in_tab(const char *s, char c)
{
	size_t	i;
	char	*str;

	str = NULL;
	i = 0;
	while (s[i] != c && s[i])
		i++;
	str = (char *) malloc(sizeof(*str) * (i + 2));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_free_table(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
	str = NULL;
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	string;
	char	**tab;

	i = 0;
	string = 0;
	if (!s)
		return (NULL);
	tab = (char **) malloc(sizeof(*tab) * (create_tab(s, c) + 1));
	if (tab == NULL)
		return (NULL);
	while (s[i])
	{
		if (((s[i - 1] == c || i == 0) && s[i] != c) && s[i])
		{
			tab[string] = put_str_in_tab(&s[i], c);
			if (!tab[string])
				return (ft_free_table(tab));
			string++;
		}
		i++;
	}
	tab[string] = NULL;
	return (tab);
}
/*int	is_not_sep(char const s, char c)
{
	if (s == c)
		return (0);
	return (1);
}

int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (((!is_not_sep(s[i - 1], c) || i == 0)
				&& is_not_sep(s[i], c)) && s[i])
			count++;
		i++;
	}
	return (count);
}

char	**ft_free_table(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

char	*put_str_in_tab(char const *s, char c)
{
	int		i;
	char	*tab;

	i = 0;
	while (s[i] && is_not_sep(s[i], c))
		i++;
	tab = malloc(sizeof(*tab) * (i + 1));
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (s[i] && is_not_sep(s[i], c) && s[i] != '\n')
	{
		tab[i] = s[i];
		i++;
	}
	tab[i] = 0;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		string;

	i = 0;
	string = 0;
	if (!s)
		return (NULL);
	tab = malloc(sizeof(*tab) * (count_words(s, c) + 1));
	if (!tab)
		return (NULL);
	while (s[i])
	{
		if (((!is_not_sep(s[i - 1], c) || i == 0)
				&& is_not_sep(s[i], c)) && s[i])
		{
			tab[string] = put_str_in_tab(&s[i], c);
			if (!tab || tab == NULL)
				return (ft_free_table(tab));
			string++;
		}
		i++;
	}
	tab[string] = NULL;
	return (tab);
}*/
