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

int		str_len(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int		parse_tr(char *num_str)
{
	int count_tr;
	int i;
	int temp;

	temp = 0;
	i = 0;
	count_tr = 0;
	while (num_str[i])
	{
		if (temp == 3)
		{
			count_tr++;
			temp = 0;
		}
		temp++;
		i++;
	}
	return (count_tr + 1);
}

char	*dict_search(int fd, int count_tr)
{
	char	*res;
	char	c;
	int		flag;
	int		count_z;
	int		flag2;

	flag2 = 0;
	count_z = 0;
	flag = 0;
	while (read(fd, &c, 1))
	{
		flag++;
		if (c == '\n')
			flag = 0;
		if (flag == 2 && c == '0')
		{
			while (c == 0)
			{
				count_z++;
				read(fd, &c, 1);
				skip_sh();
				if ((count_tr == (count_z - 1)) && c == ':')
				{
					flag2 = 1;
					break;
				}
			}
		}
		if (flag2)
			break;
	}
	if (c == 0 || read(fd, &c, 1) == 0)
		dict_err(res);
	else if (c == ':')
		
}

void	convert(char *filename, char *num_str)
{
	int fd;
	int len_num;
	int count_tr;

	len_num = 0;
	count_tr = parse_tr(num_str);
	fd = open(filename, O_RDONLY);
	if (check_number(num_str) == -1)
	{
		write(1, "Error\n", 6);
		return ;
	}
	
}
