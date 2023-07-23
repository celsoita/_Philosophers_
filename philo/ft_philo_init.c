/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschiavo <cschiavo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 11:01:53 by cschiavo          #+#    #+#             */
/*   Updated: 2023/07/23 12:20:58 by cschiavo         ###   ########.fr       */
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
	info->forks = malloc(sizeof(pthread_mutex_t) * info->num_philo);
	
	i = 0;
	while(i < info->num_philo)
	{
		pthread_mutex_init(&info->forks[i],NULL);
		// printf("fork %p\n", &info->forks[i]);
		i++;
	}
}

void ft_philo_init(t_philo philo, size_t id)
{
	philo.id = id;
	printf("philo->id = %zu\n", philo.id);
	philo.eat_times = -1;
	philo.last_eat = philo.info->start_time;
	//printf("start_time = %u\n", philo.last_eat);
	philo.rfork = &philo.info->forks[id];
	// printf("rfork %p\n", philo.rfork);
	// if (id != philo.info->num_philo)
		philo.lfork = &philo.info->forks[(id +1) % philo.info->num_philo];

	// printf("lfork %p\n", philo.lfork);
}