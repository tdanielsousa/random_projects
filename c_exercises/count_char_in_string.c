/******************************************************************************

Create a program that has a function called contarChar that
receives two parameters: a string and a character.
The function must count and return how many times the given character appears in the string.

Details:
- The string may contain letters, numbers, spaces and symbols.
- The search for the character must not be case-sensitive (for
example, 'a' and 'A' are the same character).
- If the character does not appear in the string, the function must return zero.

*******************************************************************************/

#include <stdio.h>

char* conversor(char* old_str, char* new_str)
{
    int i;

    i = 0;
    while (old_str[i] != '\0')
    {
        if (old_str[i] >= 65 && old_str[i] <= 90)
            new_str[i] = old_str[i] + 32;
        else
            new_str[i] = old_str[i];
        i++;
    }
    new_str[i] = '\0';
    return (new_str);
}

int contarChar(char* str, char c)
{
    int count;
    int i;

    count = 0;
    i = 0;
    while (str[i])
    {
        if (str[i] == c)
            count++;
        i++;
    }
    return (count);
}

int main(void)
{
    int status;
    char str[100];
    char new_str[100];
    char c;
    int count;
    char new_c;

    printf("\033[0;33m**********************************\033[0m\n");
    printf("\033[0;35mEnter the string: \033[0m");
    status = scanf(" %[^\n]", str);
    if (status != 1)
    {
        printf("\033[1;34mError reading the string\n\033[0m");
        return (1);
    }
    while (getchar() != '\n')
        ;
    printf("\033[0;33m**********************************\033[0m\n");
    printf("\033[0;35mEnter the character: \033[0m");
    status = scanf("%c", &c);
    if (status != 1)
    {
        printf("\033[1;34mError reading the character\n\033[0m");
        return (1);
    }
    printf("\033[0;33m**********************************\033[0m\n");

    conversor(str, new_str);

    if (c >= 65 && c <= 90)
        new_c = c + 32;
    else
        new_c = c;

    count = contarChar(new_str, new_c);
    printf("\033[0;35mThe character \"%c\" appears in the string \"%s\" %d times! \n\033[0m",
           c, str, count);

    printf("\033[0;33m**********************************\033[0m\n");

    return (0);
}
