/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:09:25 by jin-lee           #+#    #+#             */
/*   Updated: 2021/10/18 19:47:12 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Mandatory Part
**	./pipex file1 cmd1 cmd2 file2
**	< file1 cmd1 | cmd2 > file2
**	argc == 5
*/

#include "../includes/pipex.h"

void	execute(char *cmd, char **envp)
{
	char	**cmdv;
	char	**pathv;
	char	*temp;
	char	*path;
	int		i;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	pathv = ft_split(envp[i] + 5, ':');
	cmdv = ft_split(cmd, ' ');
	i = 0;
	while (pathv[i])
	{
		temp = ft_strjoin(pathv[i++], "/");
		path = ft_strjoin(temp, cmdv[0]);
		free(temp);
		if (access(path, F_OK) == 0)
		{
			if (execve(path, cmdv, envp) == -1)
				print_error("exec");
		}
	}
}

void	exec_cmd1(int *pipe_fd, int *file_fd, char *cmd, char **envp)
{
	dup2(file_fd[0], STDIN_FILENO);
	dup2(pipe_fd[WRITE], STDOUT_FILENO);
	close(pipe_fd[READ]);
	execute(cmd, envp);
}

void	exec_cmd2(int *pipe_fd, int *file_fd, char *cmd, char **envp)
{			
	dup2(pipe_fd[READ], STDIN_FILENO);
	dup2(file_fd[1], STDOUT_FILENO);
	close(pipe_fd[WRITE]);
	execute(cmd, envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		file_fd[2];
	int		pipe_fd[2];
	pid_t	pid;

	if (argc < 5)
		print_error("Bad arguments");
	file_fd[0] = open(argv[1], O_RDONLY, 0777);
	file_fd[1] = open(argv[4], O_WRONLY | O_CREAT, 0777);
	if (file_fd[0] == -1 || file_fd[1] == -1)
		print_error("open");
	if (pipe(pipe_fd) == -1)
		print_error("pipe");
	pid = fork();
	if (pid == -1)
		print_error("fork");
	if (!pid)
		exec_cmd1(pipe_fd, file_fd, argv[2], envp);
	else
	{
		wait(NULL);
		exec_cmd2(pipe_fd, file_fd, argv[3], envp);
	}
	close(file_fd[0]);
	close(file_fd[1]);
	return (EXIT_SUCCESS);
}
