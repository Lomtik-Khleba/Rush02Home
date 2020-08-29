#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

enum { NUM_SIZE = 100, WORD_SIZE = 100 };

typedef struct	s_dict
{
	char *num_str;
	char *word;
}				t_dict;

int cnt_dict_size(char *path)
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

int		is_useless_symbol(char c)
{
	return (c == ' ' || c == '\n' || c == ':');
}

t_dict		*create_dict_elem(char *num, char *translation)
{
	t_dict *elem;

	elem = malloc(sizeof(*elem));
	elem->num_str = num;
	elem->word = translation;
	return (elem);
}

t_dict		*read_data(int fd)
{
	t_dict *elem;
	char	symbol;
	int		i;
	elem = NULL;
	char *num;
	char *translation;

	num = malloc(NUM_SIZE);
	translation = malloc(WORD_SIZE);
	i = 0;
	while (read(fd, &symbol, sizeof(symbol)) > 0 && !is_useless_symbol(symbol))
		num[i++] = symbol;
	num[i] = 0;
	i = 0;

	while (read(fd, &symbol, sizeof(symbol)) > 0 && is_useless_symbol(symbol));

	translation[i++] = symbol;

	while (read(fd, &symbol, sizeof(symbol)) > 0 && !is_useless_symbol(symbol))
		translation[i++] = symbol;
	translation[i] = 0;

	if (*num && *translation)
		elem = create_dict_elem(num, translation);
	return (elem);
}

t_dict		**file_to_dict(char *dict_path, int dict_size)
{
	t_dict **dict;
	int			fd;
	int i;

	i = 0;
	dict = malloc((dict_size + 1) * sizeof(*dict));
	fd = open(dict_path, O_RDONLY);

	while ((dict[i++] = read_data(fd)));

	dict[i] = 0;
	return (dict);
}

void	print_dict(t_dict **dict)
{
	while (*dict)
	{
		printf("%s : %s\n", (*dict)->num_str, (*dict)->word);
		dict++;
	}
}

/*int		main(int argc, char **argv)
{
	char *dict_path;
	//char *value;

	if (argc == 2)
	{
		dict_path = "numbers.dict.txt";
		//value = argv[1];
	}
	else if (argc == 3)
	{
		dict_path = argv[1];
		//value = argv[2];
	}

	t_dict **dict = file_to_dict(dict_path, cnt_dict_size(dict_path));

	print_dict(dict);
}*/
