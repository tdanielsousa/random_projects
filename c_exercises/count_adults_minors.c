/******************************************************************************

Create a program that receives the ages of 10 individuals, showing after each
entry a message stating whether the individual is an "adult" or a "minor".
Consider ages from 18 (inclusive) as adult.
At the end, the program should tell the user how many adults and minors
they entered.

*******************************************************************************/

#include <stdio.h>

int main(void)
{
    int i;
    int status;
    int counter_new;
    int counter_old;
    int temp_nr;

    counter_new = 0;
    counter_old = 0;
    i = 0;

    while (i < 10)
    {
        printf("\033[0;33m**********************************\033[0m\n");
        printf("\033[0;35mEnter the age of person %d: \033[0m", (i + 1));
        status = scanf("%d", &temp_nr);
        if (status != 1 || temp_nr < 1 || temp_nr > 125)
        {
            printf("\033[1;34mEnter a valid age\n\033[0m");
            while (getchar() != '\n')
                ;
            continue;
        }
        if (temp_nr >= 18)
        {
            printf("\033[0;31m  Person %d is an adult\n\033[0m", (i + 1));
            counter_old++;
        }
        else
        {
            printf("\033[0;31m  Person %d is a minor\n\033[0m", (i + 1));
            counter_new++;
        }
        i++;
    }
    printf("\033[0;33m**********************************\033[0m\n");
    printf("\033[0;32mResult:\n\033[0m");
    printf("\033[0;32m %d adults were entered.\n\033[0m", counter_old);
    printf("\033[0;32m %d minors were entered.\n\033[0m", counter_new);
    printf("\033[0;33m**********************************\033[0m\n");
    return (0);
}
