/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 15:22:41 by rbarber           #+#    #+#             */
/*   Updated: 2020/08/30 17:30:15 by rbarber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void	display_num1(char *num, t_dict **ents, int it)
{
	int i;

	i = 0;
	while (ents[i])
	{
		if (ents[i]->num_str[0] == num[it])
		{
			if (ents[i]->num_str[1] == '\0')
			{
				write(1, ents[i]->word, len(ents[i]->word));
				break ;
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
				break ;
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
				write(1, ents[i]->word, len(ents[i]->word));
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
				break ;
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
				break ;
			}
	}
	i = -1;
	while (ents[++i])
	{
		if (!(ft_strcmp(ents[i]->num_str, "100")))
		{
			write(1, ents[i]->word, len(ents[i]->word));
			break ;
		}
	}
}

void	display_num(char *num, int begin, t_dict **ents, int it)
{
	if (begin == 1)
	{
		display_num1(num, ents, it);
	}
	else if (begin == 2 && num[it] == '1')
	{
		display_num2(num, ents, it);
	}
	else if (begin == 2)
	{
		display_num3(num, ents, it);
	}
	else if (begin == 3)
	{
		if (num[it] != '0')
		{
			display_num4(num, ents, it);
			if (num[it + 1] != '0')
				write(1, " ", 1);
		}
		display_num(num, 2, ents, it + 1);
		return ;
	}
	if (len(num) - it > 3)
		write(1, " ", 1);
}
