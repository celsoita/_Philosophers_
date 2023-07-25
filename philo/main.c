/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschiavo <cschiavo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:17:43 by cschiavo          #+#    #+#             */
/*   Updated: 2023/07/25 10:42:06 by cschiavo         ###   ########.fr       */
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
		info.eat_times = __INT_MAX__;
		if (argc == 6)
			info.eat_times = ft_atoi(argv[5]);
		ft_info(argv,&info);
		while(i < info.num_philo)
		{
			guest[i].info = &info;
			ft_philo_init(&guest[i],i);
			i++;
		}
		i = 0;
		if(info.num_philo == 1)
		{
			pthread_create(&guest[i].philo, NULL, &ft_philo_alone, (void *)&guest[i]);
			ft_free_program(guest);
			return (0);
		}
		while(i < info.num_philo)
		{
			pthread_create(&guest[i].philo, NULL, &routine, (void *)&guest[i]);
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
