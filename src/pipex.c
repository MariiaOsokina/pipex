/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:22:06 by mosokina          #+#    #+#             */
/*   Updated: 2024/09/01 21:07:03 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"


/* after calling pipe() endfd arr contains 2 fds: 
endfd[0] is for READING from the pipe
endfd[1] is for WRITING to the pipe.
all fds are OPEN */

/* 
fuction fork() returns:
in parent process -  process ID for child process;
in child process - 0;
in case of error - 1 
*/

/*waitpid(child_pid, &status, options);
Use -1 to wait for any child process
*/
int	main(int argc, char *argv[], char *envp[])
{
	int		endfd[2];
	pid_t	pid1;
	int		status;

	if (argc == 5)
	{
		if (pipe(endfd) == -1)
			error();
		pid1 = fork();
		if (pid1 == -1)
			error();
		if (pid1 == 0)
			child_process(argv, envp, endfd);
		else
		{
			waitpid(pid1, &status, 0);
			parent_process(argv, envp, endfd);			
		}
	}
	else
	{
		// ft_putstr_fd("\033[31mError: Bad arguments\n\e[0m", 2);
		// ft_putstr_fd("Ex: ./pipex <file1> <cmd1> <cmd2> <file2>\n", 1);
	}
	return (0);
}

void	error(void)
{
	perror("\033[31mError");
	exit(1);
}

/*child process:
- fd_infile becomes the new stdin;
- endfd[1] (the end for wtite) becomes the new stdout;
- execute cmd2;
*/
void	child_process(char **argv, char **envp, int *endfd)
{
	int	fd_infile;
	// THISNK ABOUT RIGHTS!!!
	fd_infile = open(argv[1], O_RDONLY);
	if (fd_infile == -1)
		error();
	dup2(fd_infile, STDIN_FILENO);
	dup2(endfd[1], STDOUT_FILENO);
	//THE ORDER?? 
	close(endfd[0]);
	close(fd_infile);
	close(endfd[1]);
	execute(argv[2], envp);
}

/*parent process:
- fd_outfile becomes stdout;
- endfd[0](the end for read) becomes stdin;
- execute cmd2;
*/
void	parent_process(char **argv, char **envp, int *endfd)
{
	int	fd_outfile;
	// THISNK ABOUT RIGHTS!!!
	fd_outfile = open("argv[4]", O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd_outfile == -1)
		error();
	dup2(fd_outfile, STDOUT_FILENO);
	dup2(endfd[0], STDIN_FILENO);
	close(endfd[1]);
	close(fd_outfile);
	close(endfd[0]);
	execute(argv[3], envp);
}

void	execute(char *argv_cmd, char **envp)
{
	char	**cmd_arr;
	char	*path;
	int		i;

	//ADD FREE!!!!
	cmd_arr = ft_split(argv_cmd, " ");
	path = find_path(cmd_arr[0], envp);
	i = 0;
	if (!path)
		while (cmd_arr[i])
		{
			//FREE PATH
			i++;
		}
	if (execve(path, cmd_arr, envp) == -1)
		error();
}

char	*find_path(char *cmd, char **envp)
{
	
}
