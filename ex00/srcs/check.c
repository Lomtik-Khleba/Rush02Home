/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 10:56:50 by rbarber           #+#    #+#             */
/*   Updated: 2020/08/29 11:16:43 by rbarber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Headers.h"

int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0'
			&& s1[i] == s2[i])
	{
		i++;	
	}
	return (s1[i] - s2[i]);
}

/*void	is_zero(char *num_str, t_dict **dict)
{
	int i;

	i = 0;
	while(num_str[i])
	{
		if (num_str[i] != '0')
			return ;
		i++;
	}
	i = 0;
	while(dict[i])
	{
		if (dict[i]->num_str[0] == '0')
		{
			write(1, dict[i]->word, len(dict[i]->word));
			break;
		}
	}
	num_str[0] = '\0';
}*/

int	number_check(char *num_str)
{
	int i;

	i = 0;
	while (num_str[i])
	{
		if (num_str[i] < '0' || num_str[i] > '9')
			return (-1);
		i++;
	}
	return (1);
}

void	display_error(int status)
{
	if (status == -1)
		write(1, "Error", 6);
	else if (status == -2)
		write(1, "Dict error", 11);
}
