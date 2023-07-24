/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_death_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschiavo <cschiavo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 11:03:05 by cschiavo          #+#    #+#             */
/*   Updated: 2023/07/24 12:35:25 by cschiavo         ###   ########.fr       */
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
		i = 0;
		while (i < philo->info->num_philo)
		{
			if (ft_time_ms() - philo[i].info->start_time - philo[i].last_eat > philo[i].info->dead_time)
			{
				ft_mutex_printf(ft_time_ms() - philo[i].info->start_time, philo, "dead");
				i = 0;
				while (i < philo->info->num_philo)
					philo[i++].death = true;
				return (NULL);
			}
		i++;
		}	
		usleep(1);
	}
	return (NULL);
}