#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void    pgcd(int    a, int  b)
{
    int rest = 0;

// Ensure A is always greater than or equal to B
    if (b > a)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    // Calculate the GCD using the Euclidean algorithm
    while (b != 0)
    {
        rest = a % b;
        a = b;
        b = rest;
    }
    printf("%d\n", a);
}

int main(int argc, char **argv)
{
    if (argc == 3)
    {
        pgcd(atoi(argv[1]), atoi(argv[2]));
        return (0);
    }
    write(1, "\n", 1);
    return (1);
}

/*
int findGCD(int a, int b)
{
    if (b == 0)
    {
        return a; // Base case: if b is 0, a is the GCD
    }
    else
    {
        return findGCD(b, a % b); // Recursive call with b and the remainder of a divided by b
    }
}*/