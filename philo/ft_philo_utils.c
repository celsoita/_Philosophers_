/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschiavo <cschiavo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:48:06 by cschiavo          #+#    #+#             */
/*   Updated: 2023/07/24 20:11:21 by cschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
	{
		str++;
	}
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		str++;
	}
	return (res * sign);
}

int	ft_time_ms(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

 void	ft_mutex_printf(useconds_t time,t_philo *philo, char *str)
 {
	bool morto;

	pthread_mutex_lock(&philo->info->morto);
	morto = philo->death;
	pthread_mutex_unlock(&philo->info->morto);

	pthread_mutex_lock(&philo->info->print);
	
	if (morto == false)
		printf("%u %zu %s\n", time, philo->id, str);
	pthread_mutex_unlock(&philo->info->print);
 }