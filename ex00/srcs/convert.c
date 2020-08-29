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

int	parse_tr(char *input_num, int *begin)
{
	int count_tr;
	int i;

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
	if (*begin == 0)
	{
		*begin = 3;
		return(count_tr);
	}
	return (count_tr + 1);
}

char	*dict_search(t_dict **ents, int count_tr)
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
		j = 0;
		while (ents[i]->num_str[j] != '\0')
		{
			if (ents[i]->num_str[j] == '0')
				count_0++;
			j++;
		}
		if (count_tr <= 2 && (count_tr == count_0 - 1))
			return (ents[i]->word);
		if (count_tr > 2 && ((count_tr - 1) * 3 == count_0))
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
				break;
                        }
                }
        }
	i = -1;
	while (ents[++i])
	{
		if ((ents[i]->num_str[0] == num[it + 1]) && num[it + 1] != '0')
		{
			if (ents[i]->num_str[1] == '\0')
			{
				write(1, " ", 1);
				write(1, ents[i]->word, len(ents[i]->word));
				break;
			}
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
	else if (begin == 2 && num[it] == '1')
	{
		display_num2(num, ents, it);
		write(1, " ", 1);
	}
	else if (begin == 2)
	{
		display_num3(num, ents, it);
		write(1, " ", 1);
	}
	else if (begin == 3)
	{
		if (num[it] != '0')
		{
			display_num4(num, ents, it);
			write(1, " ", 1);
		}
		display_num(num, 2, ents, it + 1); 
	}
}

void	display_word(char *temp, int begin, int count_tr)
{
	if (count_tr == 0)
		return ;
	if (!((begin > 0 && begin < 3) && count_tr == 1))
	{
		write(1, temp, len(temp));
		write(1, " ", 1);
	}
}

int	is_zero(char *num_str, t_dict **dict)
{
	int i;

        i = 0;
        if (num_str[0] != '0')
		return (0);
        while(dict[i])
        {
                if (dict[i]->num_str[0] == '0')
                {
                        write(1, dict[i]->word, len(dict[i]->word));
                        break;
                }
        }
	return (1);
}

int	convert(t_dict **ents, char *input_num)
{
	int	count_tr;
	char	*temp;
	int	begin;
	int	iterator;

	iterator = 0;
	begin = 0;
	if (is_zero(input_num, ents))
		return (1);
	count_tr = parse_tr(input_num, &begin);
	printf("%d\n", count_tr);
	if (number_check(input_num) == -1)
		return (-1);
	temp = dict_search(ents, count_tr);
	printf("%s\n", temp);
	while (count_tr != 0)
	{
		if (!(temp = dict_search(ents, count_tr)))
			return (-2);
		display_num(input_num, begin, ents, iterator);
		if ((len(input_num) - iterator) > 3)
			display_word(temp, begin, count_tr);
		count_tr--;
		iterator = iterator + begin;
		begin = 3;
	}
	return (1);
}
