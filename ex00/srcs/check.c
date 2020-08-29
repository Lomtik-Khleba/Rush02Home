/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 10:56:50 by rbarber           #+#    #+#             */
/*   Updated: 2020/08/29 11:16:43 by rbarber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	number_check(char *num_str)
{
	int i;

	i = 0;
	while (num_str[i])
	{
		if (num_str[i] < '0' || num_str[i] > '9')
			return (-1);
		i++;
	}
	return (1);
}

void	display_error(int status)
{
	if (status == -1)
		write(1, "Error\n", 6);
	else if (status == -2)
		write(1, "Dict error\n", 11);
}
