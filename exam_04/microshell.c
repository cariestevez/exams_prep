#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

//Allowed functions:
//malloc, free, write, close, fork, waitpid, 
//signal, kill, exit, chdir, execve, dup, dup2, pipe,
//strcmp, strncmp

//QUESTIONS
//why using dup2, if old and new fds are the same both in parent and child process??
//why after execve in child process returning error???

int print_error(char *str)
{
    int i = 0;

    while (str[i])
    {
        write(2, &str[i], 1); //loop writing each char to STDERR --> 2!!
        i++;
    }
    return (1);
}

int cd (char **argv, int i)
{
    if (i < 2)
        return (print_error("error: cd: bad arguments\n"));
    else if (chdir(argv[1]) == -1)
        return (print_error("error: cd: cannot change directory to "), print_error(argv[1]), print_error("\n"));
    return (0); //if cmd exec succesfully
}

int my_exec(char **argv, int i, char **envp)
{
    int status = 0;
    int has_pipe = 0;
    int pid = 0;
    int fd[2];

    if (argv[i] && (strcmp(argv[i], "|") == 0))
        has_pipe = 1;
    if (has_pipe && pipe(fd) == -1) // tries to create a pipe between fd[0](read) && fd[1](write)
        return (print_error("error: fatal\n")); // if pipe creation fails
    pid = fork(); // create child process
    if (!pid) //child executes cmd
    {
        // argv[i] = 0; // Set the element after the pipe or semicolon to null
        // if (has_pipe && (dup2(fd[1], 1) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
        //     return err("error: fatal\n"); // Return an error if pipe redirection or closing fails
        // execve(*argv, argv, envp); // Execute the command
        // return err("error: cannot execute "), err(*argv), err("\n"); // Return an error if execution fails
    }
    waitpid(pid, &status, 0); // parent waits for child to finish (passing status as ptr to change value)
    if (has_pipe && (dup2(fd[0], 0) == -1) || close(fd[0]) == -1 || close(fd[1]) == -1)
        return (print_error("error: fatal\n"));
    //return WIFEXITED(status) && WEXITSTATUS(status);
}

int main(int argc, char **argv, char **envp)
{
    int i = 1;
    int status = 0;
    
    if (argc > 1)
    {
        while (argv[i] && argv[i + 1])
        {
            //move ptr to the next cmd
            argv++;
            //iterate until next pipe or semicolon or end of args
            while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
                i++;
            //execute the 1st cmd argv is pointing to (before pipe, semicolon or end)
            if (strcmp(*argv, "cd") == 0)
                status = cd(argv, i); //execute cd built-in cmd
            else
                status = my_exec(argv, i, envp); //exec other cmds
        }
    }
    return (status);
}