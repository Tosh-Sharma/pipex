/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshsharma <toshsharma@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:23:13 by tsharma           #+#    #+#             */
/*   Updated: 2022/10/18 10:55:32 by toshsharma       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	if (argc >= 5)
		process_pipes2(argc, argv, envp);
	else
		perror("Number of arguments is invalid\n");
	return (0);
}
