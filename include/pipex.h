/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 19:43:49 by mosokina          #+#    #+#             */
/*   Updated: 2024/09/05 13:52:27 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <unistd.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>

void	parent_process(char **argv, char **envp, int *endfd);
void	child_process(char **argv, char **envp, int *endfd);
void	execute(char *argv_cmd, char **envp);
// char	*find_path(char *cmd, char **envp);
void	error(void);

#endif
