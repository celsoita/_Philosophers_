/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschiavo <cschiavo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:17:43 by cschiavo          #+#    #+#             */
/*   Updated: 2023/07/24 12:35:22 by cschiavo         ###   ########.fr       */
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
void	ft_init_fork(t_philo *philo)
{
	pthread_mutex_init(philo->rfork, NULL);
	pthread_mutex_init(philo->lfork, NULL);
}
//philo action 
/*il contatore pasti funziona ora devo implementare un controllo per obbligare a fare un tot numero di pasti*/
void	*routine(void *ph)
{	
	t_philo	*philo;
	size_t		num_of_meal;

	num_of_meal = 0;
	// t_info	*info;
	philo = (t_philo *) ph;
	while (1)
	{	
		pthread_mutex_lock(philo->rfork);
		ft_mutex_printf(ft_time_ms() - philo->info->start_time, philo, "has taken a Rfork");
		pthread_mutex_lock(philo->lfork);
		ft_mutex_printf(ft_time_ms() - philo->info->start_time, philo, "has taken a Lfork");
		ft_mutex_printf(ft_time_ms() - philo->info->start_time, philo, "is eating");
		philo->eat_times = num_of_meal++;
		 printf("num of meal {-%zu-} of philo [%zu]\n",philo->eat_times, philo->id);
		philo->last_eat = ft_time_ms() - philo->info->start_time;
		usleep(philo->info->time_eat * 1000);
		//printf("aggiornamento pasto philo [%zu] %u\n",philo->id, philo->last_eat);
		pthread_mutex_unlock(philo->rfork);
		pthread_mutex_unlock(philo->lfork);
		ft_mutex_printf(ft_time_ms() - philo->info->start_time, philo, "is sleeping");
		usleep(philo->info->sleep_time * 1000);
		ft_mutex_printf(ft_time_ms() - philo->info->start_time, philo, "is thinking");
		//qui ho aggiunto philo->eat_times == philo->info->eat_times per capire quando hanno mangiato tutti e farlo uscire
		if (philo->death == true || philo->eat_times == philo->info->eat_times)
			return (NULL);
	}

	return(NULL);
}
/*
	ho settato un contatore che aumenta ad ogni pasto del philosofo ora devo mettere 
	un controllo che mi vede se il philosofo [?] ha eseguito tutti i pasti;
	potrei mettere il controllo nella morte;
*/
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
	i = 0;
	while (i < philo->info->num_philo)
	{
		pthread_mutex_destroy(philo[i].rfork);
		pthread_mutex_destroy(philo[i].lfork);
		i++;
	}
	pthread_mutex_destroy(&philo->info->print);
	
	i = 0;
	while (i < philo->info->num_philo)
	{
		pthread_mutex_destroy(&philo->info->forks[i]);
		i++;
	}
	free(philo->info->forks);
	free(philo);	
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
		if (argc == 6)
			info.eat_times = ft_atoi(argv[5]);
		ft_info(argv,&info);
		while(i < info.num_philo)
		{
			guest[i].info = &info;
			ft_philo_init(&guest[i],i);
			pthread_create(&guest[i].philo, NULL, &routine, (void *)&guest[i]);
			usleep(10);
			i++;
		}
	}
	pthread_create(&guest->info->death, NULL, &deathcheck, (void *)guest);
	ft_free_program(guest);
	return(0);
}
/*
sembro aver risolto tutti i leak nel valgrind normale ora devo controllare i data race
*/
