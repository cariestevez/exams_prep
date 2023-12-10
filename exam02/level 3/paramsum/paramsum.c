#include <unistd.h>

void    putnum(int  i)
{
    int num;

    if (i > 9)
        putnum(i / 10);
    num = i % 10 + '0';
    write(1, &num, 1);
}

// putnum123
// putnum12
// putnum1
// write1
// write2
// write3

int main(int argc, char **argv)
{
    int i = 0;

    (void)argv;
    if (argc == 1)
        write (1, "0", 1);
    else
    {
        i = argc - 1;
        putnum(i);
    }
    write (1, "\n", 1);
    return (0);
}