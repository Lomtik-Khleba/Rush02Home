/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_to_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 17:05:39 by rbarber           #+#    #+#             */
/*   Updated: 2020/08/30 17:47:19 by rbarber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int		g_error = 0;

void			process_error(void)
{
	g_error = 1;
	write(1, ERR_MSG, sizeof(ERR_MSG));
}

char			read_dict_value(int fd, char *value, int value_order)
{
	char symbol;

	symbol = EOF;
	*value = 0;
	while (read(fd, &symbol, sizeof(symbol)) > 0 &&
			is_isspace(symbol))
	{
	}
	if (!is_useless_symbol(symbol) || (symbol == ':' && value_order))
	{
		*value++ = symbol;
		while (read(fd, &symbol, sizeof(symbol)) > 0
				&& !is_useless_symbol(symbol))
			*value++ = symbol;
		*value = 0;
		if (is_isspace(symbol))
			while (read(fd, &symbol, sizeof(symbol)) > 0
					&& is_isspace(symbol))
			{
			}
	}
	return (symbol);
}

t_dict			*obtain_dict_elem(int fd)
{
	t_dict		*elem;
	char		*num;
	char		last_character;

	last_character = 0;
	num = malloc(NUM_SIZE);
	num[0] = 0;
	elem = process_key(fd, last_character, num);
	return (elem);
}

t_dict			**file_to_dict(char *dict_path, int dict_size)
{
	t_dict		**dict;
	int			fd;
	int			i;

	i = 0;
	dict = malloc((dict_size + 1) * sizeof(*dict));
	while (i < dict_size + 1)
		dict[i++] = 0;
	fd = open(dict_path, O_RDONLY);
	i = 0;
	while ((dict[i] = obtain_dict_elem(fd)))
	{
		if (dict[i]->num_str[0] == '\n')
			continue;
		i++;
	}
	if (g_error)
	{
		empty_dict(dict);
		return (NULL);
	}
	dict[i] = 0;
	return (dict);
}
