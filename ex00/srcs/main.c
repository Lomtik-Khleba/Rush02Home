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
	char filename[];
	
	filename = "numbers.dict";
	if (argc == 2)
		convert(filename, argv[1]);
	else if (argc == 3)
	{
		filename = argv[1];
		convert(filename, argv[2]);
	}
	return (0);
}
