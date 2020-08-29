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
	char	filename[];
	t_dict	**dict;
	int	status;
	
	status = 0;
	filename = "numbers.dict";
	dict_init(dict, filename);
	if (argc == 2)
		status = convert(filename, argv[1]);
	else if (argc == 3)
	{
		filename = argv[1];
		status = convert(filename, argv[2]);
	}
	display_error(status);
	return (0);
}
