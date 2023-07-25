/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschiavo <cschiavo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:43:32 by cschiavo          #+#    #+#             */
/*   Updated: 2023/07/25 15:51:07 by cschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_philo_alone(void *ph)
{
	t_philo	*philo;

	philo = (t_philo *) ph ;
	ft_mutex_printf(ft_time_ms() - philo->info->start_time, philo, TAKE_FORKS);
	usleep(philo->info->dead_time * 1000);
	ft_mutex_printf(ft_time_ms() - philo->info->start_time, philo, DIED);
	return (NULL);
}

void	*routine(void *ph)
{
	t_philo	*philo;
	size_t	num_of_meal;

	num_of_meal = 0;
	philo = (t_philo *) ph;
	usleep(50 * ((philo->id) % 2));
	while (1)
	{
		if (philo->id == philo->info->num_philo)
		{
			pthread_mutex_lock(philo->rfork);
			ft_mutex_printf(ft_time_ms() \
			- philo->info->start_time, philo, TAKE_FORKS);
			pthread_mutex_lock(philo->lfork);
			ft_mutex_printf(ft_time_ms() \
			- philo->info->start_time, philo, TAKE_FORKS);
		}
		else
		{
			pthread_mutex_lock(philo->lfork);
			ft_mutex_printf(ft_time_ms() \
			- philo->info->start_time, philo, TAKE_FORKS);
			pthread_mutex_lock(philo->rfork);
			ft_mutex_printf(ft_time_ms() \
			- philo->info->start_time, philo, TAKE_FORKS);
		}
		ft_mutex_printf(ft_time_ms() - philo->info->start_time, philo, EATING);
		pthread_mutex_lock(&philo->info->time);
		philo->last_eat = ft_time_ms() - philo->info->start_time;
		pthread_mutex_unlock(&philo->info->time);
		usleep(philo->info->time_eat * 1000);
		pthread_mutex_unlock(philo->rfork);
		pthread_mutex_unlock(philo->lfork);
		pthread_mutex_lock(&philo->info->meals);
		philo->eat_times = num_of_meal++;
		if (philo->eat_times == philo->info->eat_times)
		{
			pthread_mutex_unlock(&philo->info->meals);
			return (NULL);
		}
		pthread_mutex_unlock(&philo->info->meals);
		ft_mutex_printf(ft_time_ms() \
		- philo->info->start_time, philo, SLEEPING);
		usleep(philo->info->sleep_time * 1000);
		ft_mutex_printf(ft_time_ms() \
		- philo->info->start_time, philo, THINKING);
		usleep(philo->plus * 1000);
		pthread_mutex_lock(&philo->info->morto);
		if (philo->death == true || philo->eat_times == philo->info->eat_times)
		{
			pthread_mutex_unlock(&philo->info->morto);
			return (NULL);
		}
		pthread_mutex_unlock(&philo->info->morto);
	}
	return (NULL);
}
