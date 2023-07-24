/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschiavo <cschiavo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 11:01:53 by cschiavo          #+#    #+#             */
/*   Updated: 2023/07/24 15:34:31 by cschiavo         ###   ########.fr       */
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
	pthread_mutex_init(&info->print, NULL);
	pthread_mutex_init(&info->time, NULL);
	pthread_mutex_init(&info->meals, NULL);
	info->forks = malloc(sizeof(pthread_mutex_t) * info->num_philo);
	
	i = 0;
	while(i < info->num_philo)
	{
		pthread_mutex_init(&info->forks[i],NULL);
		// printf("fork %p\n", &info->forks[i]);
		i++;
	}
}

void ft_philo_init(t_philo *philo, size_t id)
{
	philo->id = id;
	philo->eat_times = -1;
	philo->last_eat =  ft_time_ms() - philo->info->start_time;
	if (id % 2 == 0)
	{
		philo->rfork = &philo->info->forks[id];
		philo->lfork = &philo->info->forks[(id +1) % philo->info->num_philo];
	}
	else
	{
		philo->lfork = &philo->info->forks[id];
		philo->rfork = &philo->info->forks[(id +1) % philo->info->num_philo];
	}
	philo->death = false;
}