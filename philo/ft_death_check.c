/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_death_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschiavo <cschiavo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 11:03:05 by cschiavo          #+#    #+#             */
/*   Updated: 2023/07/24 16:12:39 by cschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//fuction check death status
//some data race in deathcheck need to find and fix it
void	*deathcheck(void *ph)
{
	t_philo *philo;

	philo = (t_philo *)ph;
	size_t	i;
	
	while (1)
	{
		pthread_mutex_lock(&philo->info->meals);
		if(philo->eat_times == philo->info->eat_times)
			{
				pthread_mutex_unlock(&philo->info->meals);
				return (NULL);
			}		
		pthread_mutex_unlock(&philo->info->meals);
		i = 0;
		while (i < philo->info->num_philo)
		{
			pthread_mutex_lock(&philo->info->time);
			if (ft_time_ms() - philo[i].info->start_time - philo[i].last_eat > philo[i].info->dead_time)
			{
				pthread_mutex_unlock(&philo->info->time);
				ft_mutex_printf(ft_time_ms() - philo[i].info->start_time, philo, DIED);
				i = 0;
				while (i < philo->info->num_philo)
				{
					pthread_mutex_lock(&philo->info->print);
					philo[i++].death = true;
					pthread_mutex_unlock(&philo->info->print);
				}
				return (NULL);
			}
			pthread_mutex_unlock(&philo->info->time);
			i++;
		}	
		usleep(1);
	}
	return (NULL);
}