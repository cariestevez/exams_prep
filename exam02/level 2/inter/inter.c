#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    int i = 0;
    int j = 0;
    int k = 0;
    char *str1 = argv[1];
    char *str2 = argv[2];

    if (argc == 3)
    {
        while(str1[i] != '\0')
        {
            j = 0;
            while (str2[j] != '\0')
            {
                if (str1[i] == str2[j])
                {
                        k = i - 1;
                        while (k >= 0)
                        {
                            if (str2[j] == str1[k])
                                break;
                            k--;
                        }
                        if (k == -1)
                        {
                            write(1, &str1[i], 1);
                            break;
                        }
                }
                j++;
            }
            i++;
        }
    }
    write(1, "\n", 1);
}