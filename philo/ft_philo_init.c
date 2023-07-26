/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschiavo <cschiavo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 11:01:53 by cschiavo          #+#    #+#             */
/*   Updated: 2023/07/26 12:38:25 by cschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_info(char **argv, t_info *info)
{
	size_t	i;

	info->num_philo = ft_atoi(argv[1]);
	info->dead_time = ft_atoi(argv[2]);
	info->time_eat = ft_atoi(argv[3]);
	info->sleep_time = ft_atoi(argv[4]);
	info->start_time = ft_time_ms();
	info->eat_times = __INT_MAX__;
	pthread_mutex_init(&info->print, NULL);
	pthread_mutex_init(&info->morto, NULL);
	pthread_mutex_init(&info->time, NULL);
	info->forks = malloc(sizeof(pthread_mutex_t) * info->num_philo);
	i = 0;
	while (i < info->num_philo)
	{
		pthread_mutex_init(&info->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&info->meals, NULL);
	i = 0;
	while (i < info->num_philo)
	{
		pthread_mutex_init(&info->forks[i], NULL);
		i++;
	}
}

void	ft_philo_init(t_philo *philo, size_t id)
{
	if (philo->info->num_philo % 2)
		philo->plus = philo->info->dead_time \
		- (philo->info->time_eat + philo->info->sleep_time) - 10;
	else
		philo->plus = 0;
	if (philo->plus < 0)
		philo->plus = 0;
	philo->id = id + 1;
	philo->eat_times = -1;
	philo->last_eat = ft_time_ms() - philo->info->start_time;
	if (!(id + 1 == philo->info->num_philo))
	{
		philo->lfork = &philo->info->forks[id];
		philo->rfork = &philo->info->forks[(id + 1)];
	}
	else
	{
		philo->rfork = &philo->info->forks[0];
		philo->lfork = &philo->info->forks[(philo->info->num_philo - 1)];
	}
	philo->death = false;
}
