/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 19:26:02 by mosokina          #+#    #+#             */
/*   Updated: 2024/09/08 18:00:44 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	execute(char *argv_cmd, char **envp)
{
	char	**cmd_arr;
	char	*path;

	cmd_arr = ft_split(argv_cmd, ' ');
	path = find_path(cmd_arr[0], envp);
	if (!path)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(cmd_arr[0], 2);
		free_str_arr(cmd_arr);
		exit (1);
	}
	if (execve(path, cmd_arr, envp) == -1)
	{
		free_str_arr(cmd_arr);
		error();
	}
}

char	*find_path(char *cmd, char **envp)
{
	char	**paths_arr;
	char	*path;
	char	*path_part;
	int		i;

	i = 0;
	while (!(ft_strnstr(envp[i], "PATH", 4)))
		i ++;
	paths_arr = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths_arr[i])
	{
		path_part = ft_strjoin(paths_arr[i], "/");
		path = ft_strjoin(path_part, cmd);
		free (path_part);
		if (access(path, F_OK) == 0)
		{
			free_str_arr(paths_arr);
			return (path);
		}
		free (path);
		i ++;
	}
	free_str_arr(paths_arr);
	return (0);
}

void	free_str_arr(char **paths_arr)
{
	int	i;

	i = 0;
	if (!paths_arr)
		return ;
	while (paths_arr[i])
	{
		free(paths_arr[i]);
		i ++;
	}
	free(paths_arr);
}
