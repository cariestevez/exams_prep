#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>


int print_error(char *str)
{
    int i = 0;

    while (str[i] != '\0')
    {
        write(2, &str[i], 1);
        i++;
    }
    return (1);
}

int cd(char **argv, int i)
{
    if (i != 2)
        return (print_error("error: cd: bad arguments\n"));
    if (chdir(argv[1]) == -1)
        return (print_error("error: cd: cannot change directory to "), print_error(argv[1]), print_error("\n"));
    return (0);
}

//if pipe:
//1. create pipe to connect fds (this opens the fds!)
//2. fork to create child process to exec 1st cmd
//3. dup fd[1] to redirect std output to writing end of the pipe(fd[1])
//4. close fds before calling execve in case this doesn't return
//5. execute. doesn't return by success so everything needs to be cleaned up before!!! print error msg in case of failure
//6. meanwhile in the parent process, we have to wait for the child to end
//7. we redirect the stdin to fd[0], so the next process takes the input from here (When the parent process sets up the pipeline
//	and redirects its standard input (stdin) to read from the read end of the pipe (fd[0]), any subsequent processes
//	(such as the last command in the pipeline) inherit this redirection.)

int my_exec(char **argv, int i, char **envp)//i is at pipe, semicolon or end!! argv ptr is at cmd to execute
{
	int status = 0;
	int has_pipe = 0;
	int pid = 0;
	int fd[2];

	if (argv[i] && strcmp(argv[i], "|") == 0)
		has_pipe = 1;
	if (has_pipe && pipe(fd) == -1)
		return (print_error("error: fatal\n"));
	pid = fork();
	if (pid == 0)//child process
	{
        printf("IN CHILD\n");
        //if (has_pipe || strcmp(argv[i], ";" == 0))//the | or ; have to be set to 0, so execve knows when to stop executing and doesn't return error
        argv[i] = NULL;//to be done inside of the child, so it doesn't affect the main loop of the parent process!!!
		if (has_pipe && (close(fd[0]) == -1 || dup2(fd[1], 1) == -1 || close(fd[1]) == -1))//close reading end of pipe, redirect stdout to writing end & close
			return(print_error("error: fatal\n"));
		execve(*argv, argv, envp);
		return (print_error("error: cannot execute "), print_error(*argv), print_error("\n"));
	}
	waitpid(pid, &status, 0);//waits for the child process to finish & changes the value of status to the exit code of the child to inspect with WIFEXITED & WEXITSTATUS
	if (has_pipe && (close(fd[1]) == -1 || dup2(fd[0], 0) == -1 || close(fd[0]) == -1))//next command will be read from fd[0]
		return(print_error("error: fatal\n"));
	return (WIFEXITED(status) && WEXITSTATUS(status));//returns the status of the child process (cmd execution)
}

int main(int argc, char **argv, char **envp)
{
    int i = 0;
    int status = 0;

    if (argc > 1)
    {
		if (argv[i] && argv[i + 1])
            argv++;//move ptr after ./a.out; i stays at 0
        while (argv[i])
        {
			while (argv[i] && strcmp(argv[i], "|") != 0 && strcmp(argv[i], ";") != 0)
				i++;//move until we find pipe, semicolon or end
            if (strcmp(*argv, "cd") == 0)
                status = cd(argv, i);
            else
                status = my_exec(argv, i, envp);
        }
    }
    printf("returning status %d\n", status);
    return (status);
}