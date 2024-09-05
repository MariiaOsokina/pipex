#include <unistd.h>
#include <stdio.h>
#include "libft/libft.h"

// int main(int ac, char **av, char **envp)
// {
//     (void) ac;
//     const char *filename = "/usr/bin/grep";
//     char *const argv[] = {"grep", "a", "infile", NULL};

//     execve(filename, argv, envp);
// }


int main(int argc, char **argv, char **envp)
{
    (void) argc;
    int i = 0;

    // while (envp[i])
    // {
    //     printf("%s\n", envp[i]);
    //     i ++;
    // }
    char **cmd_arr;
    char **paths_arr;
    char *path;

    cmd_arr = ft_split(argv[2], ' ');

    while (ft_strnstr(envp[i], "PATH", 4) == 0)
    {
        i ++;
    }
    // printf("%s\n", envp[i]);
    paths_arr = ft_split((envp[i] + 5), ':');
    
    i = 0;

    while (paths_arr[i])
    {
        if (ft_strncmp (paths_arr[i], cmd_arr[0]));
        i ++;
    }
    path = paths_arr[i]
    return (0);

}
