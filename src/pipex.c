/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:22:06 by mosokina          #+#    #+#             */
/*   Updated: 2024/09/08 20:33:27 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	int		endfd[2];
	pid_t	pid;

	if (argc != 5)
	{
		ft_putstr_fd("\033[31mError: Wrong arguments\n\e[0m", 2);
		ft_putstr_fd("Ex: ./pipex <file1> <cmd1> <cmd2> <file2>\n", 1);
		return (0);
	}
	if (pipe(endfd) == -1)
		error();
	pid = fork();
	if (pid == -1)
		error();
	if (pid == 0)
		first_child_process(argv, envp, endfd);
	pid = fork();
	if (pid == -1)
		error();
	if (pid == 0)
		second_child_process(argv, envp, endfd);
	wait(NULL);
	close(endfd[1]);
	close(endfd[0]);
	return (0);
}

void	first_child_process(char **argv, char **envp, int *endfd)
{
	int	fd_infile;

	fd_infile = open(argv[1], O_RDONLY, 0777);
	if (fd_infile == -1)
		error();
	dup2(fd_infile, STDIN_FILENO);
	dup2(endfd[1], STDOUT_FILENO);
	close(endfd[0]);
	close(fd_infile);
	close(endfd[1]);
	execute(argv[2], envp);
}

void	second_child_process(char **argv, char **envp, int *endfd)
{
	int	fd_outfile;

	fd_outfile = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd_outfile == -1)
		error();
	dup2(fd_outfile, STDOUT_FILENO);
	dup2(endfd[0], STDIN_FILENO);
	close(endfd[1]);
	close(fd_outfile);
	close(endfd[0]);
	execute(argv[3], envp);
}
