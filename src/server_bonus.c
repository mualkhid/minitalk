/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mualkhid <mualkhid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 18:32:29 by mualkhid          #+#    #+#             */
/*   Updated: 2024/05/15 14:10:06 by mualkhid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	perr(char *errmsg, int fd)
{
	int	offset;

	offset = 0;
	write (fd, "\nerror: ", 8);
	while (errmsg[offset] != '\0')
		write (fd, &errmsg[offset++], 1);
	exit (1);
}

void	ft_btoa(int sig, siginfo_t *info, void *context)
{
	static int	bit;
	static int	i;

	(void)context;
	if (sig == SIGINT)
	{
		if (kill(info->si_pid, SIGINT) == -1)
			perr("kill error :D", 2);
		perr("server interupted :D", 2);
	}
	if (sig == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		if (i == 0)
			kill(info->si_pid, SIGUSR2);
		ft_printf("%c", i);
		if (!i)
			ft_printf("\n");
		bit = 0;
		i = 0;
	}
	usleep (450);
}

int	main(int ac, char **av)
{
	int					pid;
	struct sigaction	act;

	(void)av;
	if (ac != 1)
	{
		ft_printf("Error\n");
		return (1);
	}
	pid = getpid();
	ft_printf("%d\n", pid);
	act.sa_sigaction = ft_btoa;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	while (ac == 1)
	{
		sigaction(SIGINT, &act, NULL);
		sigaction(SIGUSR1, &act, NULL);
		sigaction(SIGUSR2, &act, NULL);
		pause();
	}
	return (0);
}
