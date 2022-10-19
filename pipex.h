/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshsharma <toshsharma@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:23:49 by tsharma           #+#    #+#             */
/*   Updated: 2022/10/18 11:07:06 by toshsharma       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdarg.h>
# include <stdlib.h>
# include <fcntl.h>

// TO BE REMOVED.
# include <stdio.h>

# include "libft/libft.h"

typedef struct s_env
{
	int	    argc;
	char    **argv;
    char    **envp;
}	t_env;

void	process_pipes(char **argv, char **envp);
void	process_pipes2(int argc, char **argv, char **envp);

#endif