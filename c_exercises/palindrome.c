#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

char ft_tolower(char c)
{
    if (c >= 'A' && c <= 'Z')
    {
        return (c + 32);
    }
    return (c);
}

bool ft_isalnum(char c)
{
    if (c >= 'a' && c <= 'z')
    {
        return (true);
    }
    if (c >= 'A' && c <= 'Z')
    {
        return (true);
    }
    if (c >= '0' && c <= '9')
    {
        return (true);
    }
    return (false);
}

/*
changed from isspace to isalnum
*/
bool check_palindrome(char* str)
{
    int s;
    int size;

    s = 0;
    size = 0;
    while (str[size] != '\0')
        size++;
    size--;
    while (s < size)
    {
        while (s < size && (ft_isalnum(str[s]) == false))
            s++;
        while (s < size && (ft_isalnum(str[size]) == false))
            size--;
        if (ft_tolower(str[s]) != ft_tolower(str[size]))
        {
            return (false);
        }
        s++;
        size--;
    }
    return (true);
}

int main(void)
{
    char buffer[22];

    write(1, "Enter a sentence (max 20): ", 27);
    if (fgets(buffer, 22, stdin) != NULL)
    {
        if (check_palindrome(buffer) == true)
        {
            write(1, "It is a palindrome \n", 20);
        }
        else
        {
            write(1, "Not a palindrome \n", 18);
        }
    }
    return (0);
}
