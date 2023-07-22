/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschiavo <cschiavo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:20:53 by cschiavo          #+#    #+#             */
/*   Updated: 2023/07/22 11:16:35 by cschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdbool.h>

typedef struct s_info
{
	size_t	num_philo;
	size_t	dead_time;
	size_t	time_eat;
	size_t	sleep_time;
	useconds_t	start_time;
	pthread_mutex_t print;

}		t_info;

typedef struct  s_philo
{
	size_t		id;
	size_t		num_eat;
	useconds_t last_eat;
	size_t num_of_meal;
	pthread_t	*philo;
	pthread_mutex_t rfork;
	pthread_mutex_t lfork;
	t_info		*info;
	
}		t_philo;

//ft_philo_utils
int		ft_atoi(const char *str);
int		ft_time_ms(void);
//ft_check_args
int		ft_isdigit(char *str);
int		ft_check_arg(int argc, char **argv);
bool	ft_perror(char *str);

#endif