/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 15:21:14 by rbarber           #+#    #+#             */
/*   Updated: 2020/08/30 17:20:10 by rbarber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int		ft_strcmp(char *s1, char *s2)
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

int		number_check(char *num_str)
{
	int i;

	i = 0;
	while (num_str[i])
	{
		if (num_str[i] < '0' || num_str[i] > '9')
			return (-1);
		i++;
	}
	if (num_str[0] == '\0')
		return (-1);
	return (1);
}

void	display_error(int status)
{
	if (status == -1)
		write(1, "Error\n", 6);
	else if (status == -2)
		write(1, "Dict error\n", 11);
}

int		len(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
