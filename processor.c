/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshsharma <toshsharma@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 10:45:10 by toshsharma        #+#    #+#             */
/*   Updated: 2022/10/19 11:52:55 by toshsharma       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	get_infile(char *file_path)
{
	int	id;

	id = open(file_path, O_RDONLY, 0777);
	if (id == -1)
	{
		perror("Could not open file\n");
		exit(EXIT_FAILURE);
	}
	return (id);
}

int	get_outfile(char *file_path)
{
	int	id;

	id = open(file_path, O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (id == -1)
	{
		perror("Could not open write file\n");
		exit(EXIT_FAILURE);
	}
	return (id);
}

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
			return path;
		free(path);
		i++;
	}
    if (result == -1)
    {
        perror("command not found");
        exit(EXIT_FAILURE);
    }
	return path;
}

void    execute_commands(int infile_fd, int outfile_fd, t_env *input)
{
    int     i;
    int     fd[2];
    int     id;
    char    *exec_path;
    char    **address;
    char    **command1;
    char    **command2;
    
    i = 2;
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
    {
        close(fd[0]);
        command1 = ft_split(input->argv[i], ' ');
        exec_path =  find_appropriate_path(command1, address);
        dup2(infile_fd, STDIN_FILENO);  // This sends input from Infile to STDIN.
        dup2(fd[1], STDOUT_FILENO); // This sends the output from STDOUT to Outfile.
        close(fd[1]);
        execve(exec_path, command1, input->envp);
        perror("Execve returned an error\n");
    }
    waitpid(0, NULL, 0);
    command2 = ft_split(input->argv[3], ' ');
    exec_path = find_appropriate_path(command2, address);
    dup2(fd[0], STDIN_FILENO);
    dup2(outfile_fd, STDOUT_FILENO);
    close(fd[0]);
    close(fd[1]);
    execve(exec_path, command2, input->envp);
    perror("Second execve returned an error\n");
}

void	process_pipes2(int argc, char **argv, char **envp)
{
    int     infile_fd;
    int     outfile_fd;
    t_env   input;

    input.argc = argc;
    input.argv = argv;
    input.envp = envp;
    infile_fd = get_infile(argv[1]);
    outfile_fd = get_outfile(argv[argc - 1]);
    execute_commands(infile_fd, outfile_fd, &input);
    close(infile_fd);
    close(outfile_fd);
}