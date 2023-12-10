#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int print_str(char *str, const char type)
{
    int i = 0;
    int printed = 0;

    if (str == NULL && type != 'x')
        return (write(1, "(null)", 6));
    while (str[i] != '\0')
    {
        printed += write(1, &str[i], 1);
        i++;
    }
    if (type == 'x')
        free(str);
    return (printed);
}

int print_decimal(int num)
{
    int decimal = 0;
    int printed = 0;

    if (num == -2147483648)
        return (write(1, "-2147483648", 11));
    else
    {
        if (num < 0)
        {
            num *= -1;
            printed += write(1, "-", 1);
        }
        if (num > 9)
            printed += print_decimal(num / 10);
        decimal = num % 10 + '0';
        printed += write(1, &decimal, 1);
    }
    return (printed);
}

int print_hexa(unsigned int num)
{
    int length = 0;
    unsigned int copy = num;
    char *hexa_num = NULL;
    char *str = "0123456789abcdef";
    
    if (copy == 0)
        length = 1;
    while (copy != 0)
    {
        copy /= 16;
        length++;
    }
    hexa_num = (char *)malloc(sizeof(char) * length + 1);
    if (hexa_num == NULL)
        return (0);
    if (num == 0)
    {   
        hexa_num[0] = '0';
        hexa_num[1] = '\0';
    }
    else if (num != 0)
    {
        hexa_num[length] = '\0';
        while (length > 0)
        {
            hexa_num[length - 1] = str[num % 16];
            num /= 16;
            length--;
        }
    }
    return (print_str(hexa_num, 'x'));
}

//PROBLEM when using this external function instead of doing it directly from ft_printf
//when multiple formats to be printed in the main, it was just printing the 1st
//maybe issue with va_arg, not moving to the next argument?
// int typecast_print(const char type, va_list arg_list)
// {
//     if (type == 's')
//         return (print_str(va_arg(arg_list, char *), type));
//     if (type == 'd')
//         return (print_decimal(va_arg(arg_list, int)));
//     if (type == 'x')
//         return (print_hexa(va_arg(arg_list, unsigned int)));
//     else
//         return (-1);//original would return an error message bc of a non exixtent specified str
// }

int ft_printf(const char *str, ... )// =the str in between double quotes
{
    int i = 0;
    int printed = 0;
    va_list arg_list;//list of all the variables to print (separed by a comma after the double quotes in the printf call) 

    va_start(arg_list, str);
    while (str && str[i] != '\0')
    {
        if (str[i] == '%' && (str[i + 1] == 's' || str[i + 1] == 'd' || str[i + 1] == 'x'))
        {
            if (str[i + 1] == 's')
                printed += print_str(va_arg(arg_list, char *), 's');
            if (str[i + 1] == 'd')
                printed += print_decimal(va_arg(arg_list, int));
            if (str[i + 1] == 'x')
                printed += print_hexa(va_arg(arg_list, unsigned int));
            i++;
        }
        else
           printed += write(1, &str[i], 1);
        i++;

    }
    va_end(arg_list);
    return (printed);
}

// int main()
// {
//     char *str = NULL;

//     printf("%d\n", ft_printf("%s\n", str));
//     printf("%d\n", printf("%s\n", str));
//     ft_printf("Magic %s is %d\n", "number", 42);
//     printf("Magic %s is %d\n", "number", 42);
//     ft_printf("Number is %d\n", 42);
//     printf("Number is %d\n", 42);
//     ft_printf("Magic %d\n", 42);
//     printf("Magic %d\n", 42);
//     ft_printf("Hexadecimal for 42 is %x\n", 42);
//     printf("Hexadecimal for 42 is %x\n", 42);
// }