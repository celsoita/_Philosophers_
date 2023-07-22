/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschiavo <cschiavo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:17:43 by cschiavo          #+#    #+#             */
/*   Updated: 2023/07/22 11:17:45 by cschiavo         ###   ########.fr       */
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
	t_info	*info;

	info->num_philo = ft_atoi(argv[1]);
	info->dead_time = ft_atoi(argv[2]);
	info->time_eat = ft_atoi(argv[3]);
	info->sleep_time = ft_atoi(argv[4]);
	info->start_time = ft_time_ms();
	pthread_mutex_init(&info->print, NULL);
}
 void	ft_mutex_printf(useconds_t time,t_philo *philo, char *str)
 {
	pthread_mutex_lock(&philo->info->print);
	printf("%u %zu %s\n", time, philo->id, str);
	pthread_mutex_unlock(&philo->info->print);
 }
void	*routine(void *ph)
{	
	t_philo	*philo;
	t_info	*info;
	
	philo->id = *(size_t *)ph;
	pthread_mutex_lock(&info->print);
		ft_mutex_printf(ft_time_ms() - info->start_time ,philo, "has take a fork");
	pthread_mutex_unlock(&info->print);
	return(NULL);
}

int	main(int argc, char **argv)
{
	t_philo	*guest;
	t_info	*info;
	size_t	i;

	if (ft_check_arg(argc, argv))
		return (ft_perror("invalid argument"));
	if ((argc == 6 || argc == 5) && atoi(argv[1]) >= 1)
	{
	i = 0;
	ft_info(argv);
		while(i < info->num_philo)
		{
			pthread_create(&guest->philo[i], NULL, routine, guest->philo[i]);
			i++;
		}
	}
	return(0);
}
/*int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
    void *(*start_routine)(void*), void *arg);
*/