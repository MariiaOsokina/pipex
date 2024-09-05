/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 19:26:02 by mosokina          #+#    #+#             */
/*   Updated: 2024/09/05 13:59:31 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/pipex.h"

void	execute(char *argv_cmd, char **envp)
{
	char	**cmd_arr;
	char	*path;
	int		i;

	//ADD FREE!!!!
	cmd_arr = ft_split(argv_cmd, ' ');
	path = "/usr/bin/grep";

	// path = find_path(cmd_arr[0], envp);
	// i = 0;
	// if (!path)
	// 	while (cmd_arr[i])
	// 	{
	// 		//FREE PATH
	// 		i++;
	// 	}
	if (execve(path, cmd_arr, envp) == -1)
		error();
}

// char	*find_path(char *cmd, char **envp)
// {
// 	char	**paths_arr;
// 	char	*path;
// 	int		i;

// 	i = 0;
// 	while (ft_strnstr(envp[i], "PATH", 4) == 0)
// 		i ++;
// 	paths_arr = ft_split((envp[i] + 5), ':');
// 	i = 0;
// 	while (paths_arr[i])
// 	{
// 		// if (ft_strncmp (paths_arr[i], cmd_arr[0]));
// 		i ++;
// 	}
// 	i = -1;
// 	while (paths[i++])
// 		free(paths[i]);
// 	free(paths);
// 	return (0);
// }
