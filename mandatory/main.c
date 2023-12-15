/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisson <alisson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:55:10 by almarcos          #+#    #+#             */
/*   Updated: 2023/12/14 15:17:21 by alisson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *env[])
{
	t_pipex	pipex;
	int		exit_status;

	init_pipex(&pipex, argc, argv, env);
	first_child(&pipex, argv[2]);
	waitpid(pipex.first_child, NULL, 0);
	second_child(&pipex, argv[3]);
	close_tube(&pipex);
	waitpid(pipex.second_child, &exit_status, 0);
	free_split(pipex.path);
	exit(GET_EXIT_STATUS(exit_status));
}
