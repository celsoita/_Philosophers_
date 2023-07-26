/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschiavo <cschiavo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:17:43 by cschiavo          #+#    #+#             */
/*   Updated: 2023/07/26 11:28:01 by cschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
• Any state change of a philosopher must be formatted as follows:
◦ timestamp_in_ms X has taken a fork
◦ timestamp_in_ms X is eating
◦ timestamp_in_ms X is sleeping
◦ timestamp_in_ms X is thinking
◦ timestamp_in_ms X died
*/

static void	ft_main_philo_init(t_philo *guest, size_t i, t_info info)
{
	while (i < info.num_philo)
	{
		guest[i].info = &info;
		ft_philo_init(&guest[i], i);
		i++;
	}
}

static bool	ft_main_philo_alone(t_philo *guest, size_t i)
{
	pthread_create(&guest[i].philo, NULL, &ft_philo_alone, \
	(void *)&guest[i]);
	ft_free_program(guest);
	return (0);
}

static void	ft_main_routine(t_philo *guest, t_info info, size_t i)
{
	while (i < info.num_philo)
	{
		pthread_create(&guest[i].philo, NULL, &routine, (void *)&guest[i]);
		i++;
	}
}

static void	ft_main_end(t_philo *guest, t_info info, size_t i)
{
	ft_main_routine(guest, info, i);
	pthread_create(&guest->info->death, NULL, &deathcheck, (void *)guest);
	ft_free_program(guest);
}

int	main(int argc, char **argv)
{
	t_philo	*guest;
	t_info	info;
	size_t	i;

	guest = 0;
	if (ft_check_arg(argc, argv))
		return (ft_perror("invalid argument"));
	if ((argc == 6 || argc == 5) && ft_atoi(argv[1]) >= 1)
	{
		i = 0;
		guest = malloc(sizeof(t_philo) * ft_atoi(argv[1]));
		if (!guest)
			return (0);
		ft_info(argv, &info);
		if (argc == 6)
			info.eat_times = ft_atoi(argv[5]);
		ft_main_philo_init(guest, i, info);
		i = 0;
		if (info.num_philo == 1)
			return (ft_main_philo_alone(guest, i));
		ft_main_end(guest, info, i);
	}
	else
		return (ft_perror("few_argument"));
}
