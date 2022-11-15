/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 10:45:10 by toshsharma        #+#    #+#             */
/*   Updated: 2022/11/15 15:44:37 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_appropriate_path(char **command, char **address)
{
	char	*path;
	char	*path2;
	int		i;
	int		result;

	i = 0;
	while (address[i] != NULL)
	{
		result = -1;
		path2 = ft_strjoin(address[i], "/");
		path = ft_strjoin(path2, command[0]);
		free(path2);
		result = access(path, X_OK);
		if (result != -1)
			return (path);
		free(path);
		i++;
	}
	if (result == -1)
	{
		perror("command not found");
		exit(127);
	}
	return (path);
}

void	execute_first(t_env *input, int *fd, int infile_fd, char **address)
{
	char	*exec_path;
	char	**command1;

	close(fd[0]);
	command1 = ft_split(input->argv[2], ' ');
	if (access(command1[0], X_OK) != -1)
		exec_path = command1[0];
	else
		exec_path = find_appropriate_path(command1, address);
	dup2(infile_fd, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	execve(exec_path, command1, input->envp);
	perror("Execve returned an error\n");
}

void	execute_second(t_env *input, int *fd, int outfile_fd, char **address)
{
	char	**command2;
	char	*exec_path;

	command2 = ft_split(input->argv[3], ' ');
	if (access(command2[0], X_OK) != -1)
		exec_path = command2[0];
	else
		exec_path = find_appropriate_path(command2, address);
	dup2(fd[0], STDIN_FILENO);
	dup2(outfile_fd, STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	execve(exec_path, command2, input->envp);
	perror("Second execve returned an error\n");
}

void	execute_commands(int infile_fd, int outfile_fd, t_env *input)
{
	int		fd[2];
	int		id;
	char	**address;

	address = ft_split(getenv("PATH"), ':');
	if (pipe(fd) == -1)
	{
		perror("Could not create pipe\n");
		exit(EXIT_FAILURE);
	}
	id = fork();
	if (id == -1)
	{
		perror("Could not create fork\n");
		exit(EXIT_FAILURE);
	}
	if (id == 0)
		execute_first(input, fd, infile_fd, address);
	waitpid(0, NULL, WNOHANG);
	execute_second(input, fd, outfile_fd, address);
}
