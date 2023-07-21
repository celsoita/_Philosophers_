/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschiavo <cschiavo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:17:43 by cschiavo          #+#    #+#             */
/*   Updated: 2023/07/21 18:35:04 by cschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
• Any state change of a philosopher must be formatted as follows:
◦ timestamp_in_ms X has taken a fork
◦ timestamp_in_ms X is eating
◦ timestamp_in_ms X is sleeping
◦ timestamp_in_ms X is thinking
◦ timestamp_in_ms X died
*/
void	ft_info(char **argv)
{
	t_info	info;

	info->num_philo = ft_atoi(argv[0]);
	info->dead_time = ft_atoi(argv[1]);
}
void	routine(void *ph)
{
	t_philo	*philo;
	if(ph % 2 == 0)
	pthread_mutex_lock(philo->rfork);
	printf("%lu %i %s\n", , philo->phil, "has taken a fork");
	pthread_mutex_unlock(philo->rfork);

}

int	main(int argc, char **argv)
{
	t_philo	*guest;
	t_info	*info;
	int	i;

	i = 0;
	ft_info(argv);
	while(i < info->num_philo)
	{
		pthread_create(guest->phil[i], NULL, &routine, guest->phil[i]);
		i++;
	}
}
/*int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
    void *(*start_routine)(void*), void *arg);
*/