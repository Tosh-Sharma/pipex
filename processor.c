/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 12:59:50 by tsharma           #+#    #+#             */
/*   Updated: 2022/10/06 17:46:25 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	get_file(char *file_path)
{
	int	id;

	id = open(file_path, O_RDONLY);
	if (id == -1)
	{
		printf("Could not open file\n");
		exit(EXIT_FAILURE);
	}
	return (id);
}

void	process_pipes(char **argv)
{
	int		fd[2];
	int		file_des;
	int		id;
	char	**command;

	file_des = get_file(argv[1]);
	dup2(file_des, 0);
	if (pipe(fd) == -1)
	{
		printf("Could not create pipe\n");
		exit(EXIT_FAILURE);
	}
	command = ft_split(argv[2], ' ');
	printf("Command is %s, %s\n",
		command[0], command[1]);
	id = fork();
	if (id == -1)
	{
		printf("Could not create fork\n");
		exit(EXIT_FAILURE);
	}
	if (id == 0)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		/*	The way to run the execve command is as follows
			1. Get all executable paths.
			2. Split them up into individual paths.
			3. Find the appropriate Path that works for the command provided.
			4. Use access command for the above step.
			5. If none of the commands succeed, exit the code.
			6. If any of them does succeed, use that path to run the code.
			7. Ensure the information goes ahead and reaches the Pipe
			8. Use dup2 command for the above step.
		*/
		close(fd[1]);
	}
}
