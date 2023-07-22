/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschiavo <cschiavo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:43:38 by cschiavo          #+#    #+#             */
/*   Updated: 2023/07/22 10:13:44 by cschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(char *str)
{
	int	i;

	i = 0;
	while (str[i] == 32 || str[i] == 9)
		i++;
	if (str[i] == '+')
		i++;
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (1);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			break ;
		i++;
	}
	while (str[i] == 32 || str[i] == 9)
		i++;
	if (str[i])
		return (1);
	return (0);
}

int	ft_check_arg(int argc, char **argv)
{
	int	i;

	i = 0;
	while (++i < argc)
	{
		if (ft_isdigit(argv[i]))
			return (1);
	}
	return (0);
}

bool	ft_perror(char *str)
{
	printf("%s\n", str);
	return (1);
}
