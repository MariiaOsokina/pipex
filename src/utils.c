/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 19:26:02 by mosokina          #+#    #+#             */
/*   Updated: 2024/09/06 21:16:50 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	execute(char *argv_cmd, char **envp)
{
	char	**cmd_arr;
	char	*path;

	cmd_arr = ft_split(argv_cmd, ' ');
	path = find_path(cmd_arr[0], envp);
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
	int		i;

	i = 0;
	while (!(ft_strnstr(envp[i], "PATH", 4)))
		i ++;
	printf("envp line: %s\n", envp[i]);
	paths_arr = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths_arr[i])
	{
		path = ft_strjoin(ft_strjoin(paths_arr[i], "/"), cmd);
		if (access(path, F_OK) == 0)
		{
			free_str_arr(paths_arr);
			printf("path: %s\n", path);
			return (path);
		}
		i ++;
	}
	free_str_arr(paths_arr);
	return (NULL);
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
