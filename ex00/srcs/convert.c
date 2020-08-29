/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 11:20:05 by rbarber           #+#    #+#             */
/*   Updated: 2020/08/29 12:12:36 by rbarber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Headers.h"

int		len(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int		parse_tr(char *input_num, int *begin)
{
	int count_tr;
	int i;
	char **arr;

	i = 0;
	count_tr = 0;
	while (input_num[i])
	{
		(*begin)++;
		if (*begin == 3)
		{
			count_tr++;
			*begin = 0;
		}
		i++;
	}
	return (count_tr + 1);
}

char	*dict_search(t_dict **ents, int input_num, int count_tr)
{
	int i;
	int count_0;
	int j;

	j = 0;
	count_0 = 0;
	i = 0;
	while (ents[i] != 0)
	{
		count_0 = 0;
		while (ents[i]->num_str[j] != '\0')
		{
			if (ents[i]->num_str[j] == 0)
				count_0++;
			j++;
		}
		if (count_0 - 1 == count_tr)
			return (ents[i]->word);
		i++;
	}
	return (0);
}

void	display_num1(char *num, t_dict **ents, int it)
{
	int i;

	i = 0;
	while(ents[i])
	{
		if (ents[i]->num_str[0] == num[it])
		{
			if (ents[i]->num_str[1] == '\0')
			{
				write(1, ents[i]->word, len(ents[i]->word));
				break;
			}
		}
		i++;
	}
}

void	display_num2(char *num, t_dict **ents, int it)
{
	int i;

	i = 0;
	while (ents[i])
	{
		if (ents[i]->num_str[0] == '1')
		{
			if (ents[i]->num_str[1] == num[it + 1])
			{
				write(1, ents[i]->word, len(ents[i]->word));
				break;
			}
		}
		i++;
	}
}

void	display_num3(char *num, t_dict **ents, int it)
{
	int i;

	i = -1;
	while (ents[++i])
        {
                if (ents[i]->num_str[0] == num[it])
                {
                        if (ents[i]->num_str[1] == '0')
                        {
                                write(1, ents[i]->word, len(ents[i]->word));
				write(1, " ", 1);
				break;
                        }
                }
        }
	i = -1;
	while (ents[++i])
	{
		if (ents[i]->num_str[0] == num[it + 1])
			if (ents[i]->num_str[1] == '\0')
			{
				write(1, ents[i]->word, len(ents[i]->word));
				break;
			}
	}
}

void	display_num4(char *num, t_dict **ents, int it)
{
	int i;

	i = -1;
	while (ents[++i])
	{
		if (ents[i]->num_str[0] == num[it])
			if (ents[i]->num_str[1] == '\0')
			{
				write(1, ents[i]->word, len(ents[i]->word));
				write(1, " ", 1);
				break;
			}
	}
	i = -1;
	while (ents[++i])
	{
		if (!(ft_strcmp(ents[i]->num_str, "100")))
		{
			write(1, ents[i]->word, len(ents[i]->word));
			break;
		}
	}
}

void	display_num(char *num, int begin, t_dict **ents, int it)
{
	if (begin == 1)
	{
		display_num1(num, ents, it);
		write(1, " ", 1);
	}
	else if (begin == 2 && num[it] == 1)
	{
		display_num2(num, ents, it);
		write(1, " ", 1);
	}
	else if (begin == 2)
	{
		display_num3(num, ents, it);
		write(1, " ", 1);
	}
	else if (begin == 3 || begin == 0)
	{
		display_num4(num, ents, it);
		write(1, " ", 1);
		display_num(num, 2, ents, it); 
	}
}

int	convert(char *filename, t_dict **ents, char *input_num)
{
	int	count_tr;
	char	*temp;
	int	begin;
	int	iterator;

	iterator = 0;
	begin = 0;
	count_tr = parse_tr(input_num, &begin);
	if (check_number(num_str) == -1)
		return (-1);
	while (count_tr != 0)
	{
		if (!(temp = dict_search(ents, input_num, count_tr)))
			return (-2);
		display_num(input_num, begin, ents, iterator);
		write(1, temp, len(temp));
		write(1, " ", 1);
		iterator = iterator + begin;
		begin = 3;
		count_tr--;
	}
	return (1);
}
