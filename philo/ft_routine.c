/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschiavo <cschiavo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:43:32 by cschiavo          #+#    #+#             */
/*   Updated: 2023/07/26 14:41:19 by cschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_norm_routine(t_philo	*philo)
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
}

static void	ft_norm_routine_val(t_philo	*philo)
{
	ft_mutex_printf(ft_time_ms() - philo->info->start_time, philo, EATING);
	pthread_mutex_lock(&philo->info->time);
	philo->last_eat = ft_time_ms() - philo->info->start_time;
	pthread_mutex_unlock(&philo->info->time);
	ft_msleep(philo->info->time_eat);
	pthread_mutex_unlock(philo->rfork);
	pthread_mutex_unlock(philo->lfork);
}

static void	ft_sleep_think(t_philo	*philo)
{
	ft_mutex_printf(ft_time_ms() \
	- philo->info->start_time, philo, SLEEPING);
	ft_msleep(philo->info->sleep_time);
	ft_mutex_printf(ft_time_ms() \
	- philo->info->start_time, philo, THINKING);
	ft_msleep(philo->plus);
}

static	t_philo	*ft_cheat(void *ph)
{
	t_philo	*philo;

	philo = (t_philo *) ph;
	usleep(100 * ((philo->id + 1) % 2));
	return (philo);
}

void	*routine(void *ph)
{
	t_philo	*philo;

	philo = ft_cheat(ph);
	while (1)
	{
		ft_norm_routine(philo);
		ft_norm_routine_val(philo);
		pthread_mutex_lock(&philo->info->meals);
		philo->eat_times++;
		if (philo->eat_times == philo->info->eat_times)
		{
			pthread_mutex_unlock(&philo->info->meals);
			return (NULL);
		}
		pthread_mutex_unlock(&philo->info->meals);
		ft_sleep_think(philo);
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
