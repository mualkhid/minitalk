/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mualkhid <mualkhid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:32:39 by mualkhid          #+#    #+#             */
/*   Updated: 2024/05/15 14:25:59 by mualkhid         ###   ########.fr       */
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

void	sighandle(pid_t pid)
{
	perr("server interupted :D", 2);
	kill(pid, SIGINT);
}

void	ft_btoa(int sig)
{
	static int	bit;
	static int	i;

	if (sig == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		bit = 0;
		i = 0;
	}
	usleep (450);
}

int	main(int ac, char **av)
{
	int	pid;

	(void)av;
	if (ac != 1)
	{
		ft_printf("Error\n");
		return (1);
	}
	pid = getpid();
	ft_printf("%d\n", pid);
	while (ac == 1)
	{
		signal(SIGINT, sighandle);
		signal(SIGUSR1, ft_btoa);
		signal(SIGUSR2, ft_btoa);
		pause();
	}
}
