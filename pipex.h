/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:23:49 by tsharma           #+#    #+#             */
/*   Updated: 2022/10/06 14:51:59 by tsharma          ###   ########.fr       */
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

void	process_pipes(char **argv);

#endif