/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:23:13 by tsharma           #+#    #+#             */
/*   Updated: 2022/10/06 14:51:41 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv)
{
	if (argc == 5)
		process_pipes(argv);
	else
	{
		if (argc < 5)
		{
			// Throw error. Terminate code.
			return (0);
		}
		else
		{
			// BONUS STUFF
		}
	}
	return (0);
}
