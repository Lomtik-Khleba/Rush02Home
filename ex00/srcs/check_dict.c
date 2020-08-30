/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dict.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 17:08:25 by rbarber           #+#    #+#             */
/*   Updated: 2020/08/30 17:35:31 by rbarber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void			print_dict(t_dict **dict)
{
	while (*dict)
	{
		printf("%s : %s\n", (*dict)->num_str, (*dict)->word);
		dict++;
	}
}

t_dict			*process_key(int fd, char last_character, char *num)
{
	t_dict *elem;

	elem = NULL;
	last_character = read_dict_value(fd, num, 0);
	if (last_character == '\n')
	{
		if (*num)
			process_error();
		else
		{
			num[0] = '\n';
			elem = create_dict_elem(num, "");
		}
	}
	else
	{
		if (last_character == EOF)
		{
			if (*num)
				process_error();
		}
		else
			elem = process_word(fd, last_character, num);
	}
	return (elem);
}

t_dict			*process_word(int fd, char last_character, char *num)
{
	char		*translation;
	t_dict		*elem;

	translation = malloc(WORD_SIZE);
	translation[0] = 0;
	elem = NULL;
	if (last_character != ':')
		process_error();
	else
	{
		last_character = read_dict_value(fd, translation, 1);
		if (last_character != '\n')
			process_error();
		else
		{
			if (*num && *translation)
				elem = create_dict_elem(num, translation);
			else
				process_error();
		}
	}
	return (elem);
}

void			empty_dict(t_dict **dict)
{
	t_dict	**dict_head;

	dict_head = dict;
	while (*dict)
	{
		free((*dict)->word);
		free((*dict)->num_str);
		free(*dict);
		dict++;
	}
	free(dict_head);
}
