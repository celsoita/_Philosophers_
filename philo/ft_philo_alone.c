/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_alone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschiavo <cschiavo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:38:45 by cschiavo          #+#    #+#             */
/*   Updated: 2023/07/26 14:39:20 by cschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_philo_alone(void *ph)
{
	t_philo	*philo;

	philo = (t_philo *) ph ;
	ft_mutex_printf(ft_time_ms() - philo->info->start_time, philo, TAKE_FORKS);
	ft_msleep(philo->info->dead_time);
	ft_mutex_printf(ft_time_ms() - philo->info->start_time, philo, DIED);
	return (NULL);
}
