/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschiavo <cschiavo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:17:43 by cschiavo          #+#    #+#             */
/*   Updated: 2023/07/23 14:42:40 by cschiavo         ###   ########.fr       */
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
// void	ft_info(char **argv, t_info *info)
// {
// 	size_t	i;

// 	info->num_philo = ft_atoi(argv[1]);
// 	info->dead_time = ft_atoi(argv[2]);
// 	info->time_eat = ft_atoi(argv[3]);
// 	info->sleep_time = ft_atoi(argv[4]);
// 	info->start_time = ft_time_ms();
// 	pthread_mutex_init(&info->print, NULL);
// 	info->forks = malloc(sizeof(pthread_mutex_t) * info->num_philo);
	
// 	i = 0;
// 	while(i < info->num_philo)
// 	{
// 		pthread_mutex_init(&info->forks[i],NULL);
// 		printf("fork %p\n", &info->forks[i]);
// 		i++;
// 	}
// }
// void ft_philo_init(t_philo philo, size_t id)
// {
// 	philo.id = id;
// 	printf("philo->id = %zu\n", philo.id);
// 	philo.eat_times = -1;
// 	philo.last_eat = philo.info->start_time;
// 	printf("start_time = %u\n", philo.last_eat);
// 	philo.rfork = &philo.info->forks[id];
// 	printf("rfork %p\n", philo.rfork);
// 	// if (id != philo.info->num_philo)
// 		philo.lfork = &philo.info->forks[(id +1) % philo.info->num_philo];

// 	printf("lfork %p\n", philo.lfork);
// }
//  void	ft_mutex_printf(useconds_t time,t_philo *philo, char *str)
//  {
// 	pthread_mutex_lock(&philo->info->print);
// 	printf("%u %zu %s\n", time, philo->id, str);
// 	pthread_mutex_unlock(&philo->info->print);
//  }
void	ft_init_fork(t_philo *philo)
{
	pthread_mutex_init(philo->rfork, NULL);
	pthread_mutex_init(philo->lfork, NULL);
}
void	*routine(void *ph)
{	
	t_philo	*philo;
	// t_info	*info;
	philo = (t_philo *) ph;

		ft_mutex_printf(ft_time_ms() - philo->info->start_time, philo, "has taken a fork");
	return(NULL);
}

int	main(int argc, char **argv)
{
	t_philo	*guest;
	t_info	info;
	size_t	i;

	guest = 0;
	if (ft_check_arg(argc, argv))
		return (ft_perror("invalid argument"));
	if ((argc == 6 || argc == 5) && ft_atoi(argv[1]) >= 1)
	{
	i = 0;
	guest = malloc(sizeof(t_philo) * ft_atoi(argv[1]));
	if (!guest)
			return (0);
	ft_info(argv,&info);
	guest->info = &info;
		while(i < info.num_philo)
		{
			guest[i].info = &info;
			ft_philo_init(guest[i],i);
			pthread_create(&guest[i].philo, NULL, &routine, &guest[i]);
			usleep(10);
			i++;
		}
	}
	else
		printf("few argoments\n");
	return(0);
}
/*int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
    void *(*start_routine)(void*), void *arg);
*/