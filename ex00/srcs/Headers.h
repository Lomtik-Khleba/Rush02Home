#ifndef HEADERS_H
# define HEADERS_H

#include "stdlib.h"
#include "fcntl.h"
#include "unistd.h"

typedef struct	s_dict
{
	char	*num_str;
	char	*word;
}		t_dict;

int	number_check(char *num_str);

void	display_error(int status);

int	len(char *s);

int	parse_tr(char *input_num, int *begin);

char	*dict_search(t_dict **ents, int input_num, int count_tr);

void	display_num1(char *num, t_dict **ents, int it);

void	display_num2(char *num, t_dict **ents, int it);

void	display_num3(char *num, t_dict **ents, int it);

void	display_num4(char *num, t_dict **ents, int it);

void	display_num(char *num, int begin, t_dict **ents, int it);

int	convert(char *filename, t_dict **ents, char *input_num);

void	dict_init(t_dict **ents, char *filename);

#endif
