/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschiavo <cschiavo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:20:53 by cschiavo          #+#    #+#             */
/*   Updated: 2023/07/24 20:21:29 by cschiavo         ###   ########.fr       */
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

# define TAKE_LFORKS "\e[1;37mhas taken a left fork\e[0m"
# define TAKE_RFORKS "\e[1;37mhas taken a right fork\e[0m"
# define THINKING "\e[1;32mis thinking\e[0m"
# define SLEEPING "\e[1;34mis sleeping\e[0m"
# define EATING "\e[1;35mis eating\e[0m"
# define DIED "\e[1;31mdied\e[0m"

typedef struct s_info
{
	size_t	num_philo;
	size_t	dead_time;
	size_t	time_eat;
	size_t	sleep_time;
	size_t	eat_times;
	useconds_t	start_time;
	pthread_mutex_t print;
	pthread_mutex_t time;
	pthread_mutex_t *forks;
	pthread_mutex_t	meals;
	pthread_mutex_t morto;
	pthread_t death;
}		t_info;

typedef struct  s_philo
{
	size_t		id;
	//num of times each philo eat
	size_t		eat_times;
	//last eat of philo
	useconds_t last_eat;
	//number of meal total
	size_t num_of_meal;
	pthread_t	philo;
	pthread_mutex_t *rfork;
	pthread_mutex_t *lfork;
	bool		death;
	t_info		*info;
	int			plus;
	
}		t_philo;

//ft_philo_utils
int		ft_atoi(const char *str);
int		ft_time_ms(void);
void	ft_mutex_printf(useconds_t time,t_philo *philo, char *str);
//ft_check_arg
int		ft_isdigit(char *str);
int		ft_check_arg(int argc, char **argv);
bool	ft_perror(char *str);
//ft_philo_init
void	ft_info(char **argv, t_info *info);
void ft_philo_init(t_philo *philo, size_t id);
//ft_death_check
void	*deathcheck(void *ph);
//ft_free_program
void	ft_free_program(t_philo *philo);
//ft_routine
void	*routine(void *ph);
void	ft_init_fork(t_philo *philo);

#endif