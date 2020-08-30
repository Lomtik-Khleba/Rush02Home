/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 10:48:03 by rbarber           #+#    #+#             */
/*   Updated: 2020/08/30 17:00:28 by rbarber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int	main(int argc, char **argv)
{
	char	*filename;
	t_dict	**dict;
	int		status;

	dict = NULL;
	status = 1;
	filename = "numbers.dict.txt";
	if (argc == 3)
	{
		filename = argv[1];
		status = 2;
	}
	if (argc <= 3)
	{
		dict = file_to_dict(filename, cnt_dict_size(filename));
		status = convert(dict, argv[status]);
		if (status < 0)
			display_error(status);
		else
			write(1, "\n", 1);
	}
	empty_dict(dict);
	return (0);
}
