/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 15:09:06 by rbarber           #+#    #+#             */
/*   Updated: 2020/08/30 17:20:36 by rbarber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADERS_H
# define HEADERS_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

# define ERR_MSG "Dict Error\n"

enum { NUM_SIZE = 100, WORD_SIZE = 100 };

typedef struct	s_dict
{
	char		*num_str;
	char		*word;
}				t_dict;

int				is_isspace(char c);

void			process_error(void);

t_dict			*process_word(int fd, char last_character, char *num);

t_dict			*process_key(int fd, char last_character, char *num);

void			empty_dict(t_dict **dict);

char			read_dict_value(int fd, char *value, int value_order);

t_dict			*obtain_dict_elem(int fd);

int				is_zero(char *num_str, t_dict **dict);

void			display_word(char *temp, int begin, int count_tr);

int				ft_strcmp(char *s1, char *s2);

int				number_check(char *num_str);

void			display_error(int status);

int				len(char *s);

int				parse_tr(char *input_num, int *begin);

char			*dict_search(t_dict **ents, int count_tr);

void			display_num1(char *num, t_dict **ents, int it);

void			display_num2(char *num, t_dict **ents, int it);

void			display_num3(char *num, t_dict **ents, int it);

void			display_num4(char *num, t_dict **ents, int it);

void			display_num(char *num, int begin, t_dict **ents, int it);

int				convert(t_dict **ents, char *input_num);

int				cnt_dict_size(char *path);

int				is_useless_symbol(char c);

t_dict			*create_dict_elem(char *num, char *translation);

t_dict			**file_to_dict(char *dict_path, int dict_size);

void			print_dict(t_dict **dict);

#endif
