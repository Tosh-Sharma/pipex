/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshsharma <toshsharma@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:23:49 by tsharma           #+#    #+#             */
/*   Updated: 2022/11/07 15:38:37 by toshsharma       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdarg.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# include "libft/libft.h"

typedef struct s_env
{
	int		argc;
	char	**argv;
	char	**envp;
}	t_env;

void	execute_commands(int infile_fd, int outfile_fd, t_env *input);

#endif