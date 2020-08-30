/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 17:06:50 by rbarber           #+#    #+#             */
/*   Updated: 2020/08/30 17:23:11 by rbarber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int				cnt_dict_size(char *path)
{
	char	buf;
	int		fd;
	int		size;

	size = 0;
	fd = open(path, O_RDONLY);
	while (read(fd, &buf, sizeof(buf)) > 0)
		size += (buf == '\n');
	close(fd);
	return (size);
}

t_dict			*create_dict_elem(char *num, char *translation)
{
	t_dict *elem;

	elem = malloc(sizeof(*elem));
	elem->num_str = num;
	elem->word = translation;
	return (elem);
}

int				is_isspace(char c)
{
	return (c == ' ' || c == '\f' || c == '\r' || c == '\t' || c == '\v');
}

int				is_useless_symbol(char c)
{
	return (is_isspace(c) || c == '\n' || c == ':' || c == EOF);
}
