/******************************************************************************

1. Write a program that reads an integer and
displays its double, triple and square, with each
result appearing on a different line.

*******************************************************************************/

#include <stdio.h>

int main(void)
{
    int nr;
    int status;

    printf("\033[0;33m**********************************\033[0m\n");
    printf("\033[0;31mEnter an integer: \033[0m");

    status = scanf("%d", &nr);
    if (status != 1)
    {
        printf("\033[1;35mError in reading, insert an int nr\n\033[0m");
        return (1);
    }

    printf("\033[0;33m**********************************\033[0m\n");
    printf("For the number %d:\n", nr);
    printf("Double: %d\n", (nr * 2));
    printf("Triple: %d\n", (nr * 3));
    printf("Square: %d\n", (nr * nr));
    printf("\033[0;33m**********************************\033[0m\n");

    return (0);
}
