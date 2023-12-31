/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_death_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschiavo <cschiavo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 11:03:05 by cschiavo          #+#    #+#             */
/*   Updated: 2023/07/26 14:40:40 by cschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*ft_deathcheck_died(t_philo *philo, size_t i)
{
	while (i < philo->info->num_philo)
	{
		pthread_mutex_lock(&philo->info->time);
		if (ft_time_ms() - philo[i].info->start_time \
		- philo[i].last_eat > philo[i].info->dead_time)
		{
			pthread_mutex_unlock(&philo->info->time);
			ft_mutex_printf(ft_time_ms() \
			- philo[i].info->start_time, &philo[i], DIED);
			i = 0;
			while (i < philo->info->num_philo)
			{
				pthread_mutex_lock(&philo->info->morto);
				philo[i++].death = true;
				pthread_mutex_unlock(&philo->info->morto);
			}
			return (NULL);
		}
		pthread_mutex_unlock(&philo->info->time);
		i++;
	}
	return (philo);
}

void	*ft_deathcheck(void *ph)
{
	t_philo	*philo;
	size_t	i;

	philo = (t_philo *)ph;
	while (1)
	{
		i = 0;
		pthread_mutex_lock(&philo->info->meals);
		if (philo->eat_times == philo->info->eat_times)
		{
			pthread_mutex_unlock(&philo->info->meals);
			return (NULL);
		}
		pthread_mutex_unlock(&philo->info->meals);
		if (ft_deathcheck_died(philo, i) == NULL)
			return (NULL);
		ft_msleep(5);
	}
	return (NULL);
}
