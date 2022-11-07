/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshsharma <toshsharma@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:23:13 by tsharma           #+#    #+#             */
/*   Updated: 2022/11/07 15:38:03 by toshsharma       ###   ########.fr       */
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

void	process_pipes(int argc, char **argv, char **envp)
{
	t_env	input;
	int		infile_fd;
	int		outfile_fd;

	input.argc = argc;
	input.argv = argv;
	input.envp = envp;
	infile_fd = get_infile(argv[1]);
	outfile_fd = get_outfile(argv[argc - 1]);
	execute_commands(infile_fd, outfile_fd, &input);
	close(infile_fd);
	close(outfile_fd);
}

int	main(int argc, char **argv, char **envp)
{
	if (argc >= 5)
		process_pipes(argc, argv, envp);
	else
		perror("Number of arguments is invalid\n");
	return (0);
}
