/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarcos <almarcos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:55:07 by almarcos          #+#    #+#             */
/*   Updated: 2024/01/03 16:52:18 by almarcos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H

# define PIPEX_H
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_pipex
{
	int		tube[2];
	pid_t	first_child;
	pid_t	second_child;
	char	**parent_argv;
	char	**parent_env;
	char	**argv_childs;
	char	**path;
}			t_pipex;

/* helpers.c */
void		init_pipex(t_pipex *pipex, int argc, char **argv, char **env);
void		open_tube(t_pipex *pipex);
void		close_tube(t_pipex *pipex);
void		get_path(t_pipex *pipex);
int			get_exit_status(int exit_status);

/* error_handler.c */
void		error_handler(t_pipex *pipex, int exit_status, char *msg);

#endif
