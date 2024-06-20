
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>


// int main()
// {
// 	int fd;
 
// 	fd = open("example.txt", O_WRONLY | O_CREAT, 0644);
// 	dup2(fd, STDOUT_FILENO);
// 	close(fd);
// 	printf("This is printed in example.txt!\n");
 
// 	return (0);
// }

 
// int main()
// {
// 	if (access("example.txt", R_OK) != -1)
// 		printf("I have permission\n");
// 	else
// 		printf("I don't have permission\n");
 
// 	return (0);
// }


// int main()
// {
// 	pid_t id;
 
// 	id = fork();
// 	if (id == -1)
// 	{
// 		perror("fork");
// 		exit(EXIT_FAILURE);
// 	}
// 	if (id == 0)
// 		printf("This is the child process. (id: %d)\n", getpid());
// 	else
// 		printf("This is the parent process. (id: %d)\n", getpid());
 
// 	return (0);
// }



int main()
{
	int fd[2];
	pid_t pid;
	char buffer[13];
 
	if (pipe(fd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
 
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
 
	if (pid == 0)
	{
		close(fd[0]); // close the read end of the pipe
		write(fd[1], "Hello parent!", 13);
		close(fd[1]); // close the write end of the pipe
		exit(EXIT_SUCCESS);
	}
	else
	{
		close(fd[1]); // close the write end of the pipe
		read(fd[0], buffer, 13);
		close(fd[0]); // close the read end of the pipe
		printf("Message from child: '%s'\n", buffer);
		exit(EXIT_SUCCESS);
	}
}
