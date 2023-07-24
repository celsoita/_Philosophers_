/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_program.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschiavo <cschiavo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:31:42 by cschiavo          #+#    #+#             */
/*   Updated: 2023/07/24 17:42:14 by cschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free_program(t_philo *philo)
{
	size_t	i;

	i = 0;
	while(i < philo->info->num_philo)
	{
		pthread_join(philo[i].philo, NULL);
		i++;
	}
	pthread_join(philo->info->death, NULL);
	pthread_mutex_destroy(&philo->info->print);
	pthread_mutex_destroy(&philo->info->time);
	pthread_mutex_destroy(&philo->info->morto);
	pthread_mutex_destroy(&philo->info->meals);
	i = 0;
	while (i < philo->info->num_philo)
	{
		pthread_mutex_destroy(&philo->info->forks[i]);
		i++;
	}
	free(philo->info->forks);
	free(philo);	
}