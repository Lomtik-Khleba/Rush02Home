/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 10:48:03 by rbarber           #+#    #+#             */
/*   Updated: 2020/08/29 10:55:57 by rbarber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Headers.h"

int	main(int argc, char **argv)
{
	char	*filename;
	t_dict	**dict;
	int	status;

	status = 0;
	filename = "numbers.dict.txt";
	if (argc == 2)
	{
		dict = file_to_dict(filename, cnt_dict_size(filename));
		status = convert(dict, argv[1]);
	}
	else if (argc == 3)
	{
		filename = argv[1];
		dict = file_to_dict(filename, cnt_dict_size(filename));
		status = convert(dict, argv[2]);
	}
	display_error(status);
	write(1, "\n", 1);
	return (0);
}
