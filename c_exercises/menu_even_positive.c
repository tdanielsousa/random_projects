/******************************************************************************
 *
Using functions, write a program that asks the user for an integer and
performs the corresponding calculation/processing.
Consider the following menu of options:

--- Main Menu ---
1 – Check whether a number is even or odd
2 – Check whether a number is positive or negative
3 – Exit

*******************************************************************************/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool is_even(int nr)
{
    if (nr == 0)
        return true;
    if ((nr % 2) == 0)
    {
        return true;
    }
    return false;
}

bool is_positive(int nr)
{
    if (nr >= 0)
    {
        return true;
    }
    return false;
}

void picker(int choice, int nr)
{
    if (choice == 1)
    {
        if (is_even(nr) == true)
            printf("\033[0;35m %d is an even number\n\033[0m", nr);
        else
            printf("\033[0;35m %d is an odd number\n\033[0m", nr);
    }
    if (choice == 2)
    {
        if (is_positive(nr) == true)
            printf("\033[0;35m %d is a positive number\n\033[0m", nr);
        else
            printf("\033[0;35m %d is a negative number\n\033[0m", nr);
    }
}

int main(void)
{
    int choice;
    int nr;
    int status;

    while (1)
    {
        printf("\033[0;33m**********************************\033[0m\n");
        printf("\033[1;33m    --- Main Menu --- \033[0m\n");
        printf("\033[0;33m**********************************\033[0m\n");
        printf("\033[0;33m 1 - Check whether a number is even or odd \033[0m\n");
        printf("\033[0;33m 2 - Check whether a number is positive or negative\033[0m\n");
        printf("\033[0;33m 3 - Exit\033[0m\n");
        printf("\033[0;33m**********************************\033[0m\n");
        printf("\033[0;31mEnter your choice: \033[0m");
        status = scanf("%d", &choice);
        if (status != 1)
        {
            printf("\033[1;35mError reading the choice\n\033[0m");
            return (1);
        }
        if (choice < 1 || choice > 3)
        {
            printf("\033[1;35m >> Enter a menu option\n\033[0m");
            continue;
        }
        if (choice == 3)
        {
            printf("\033[1;35mExited successfully!\n\033[0m");
            exit(0);
        }
        printf("\033[0;33m**********************************\033[0m\n");
        printf("\033[0;31mEnter your value: \033[0m");
        status = scanf("%d", &nr);
        if (status != 1)
        {
            printf("\033[1;35mError reading the number\n\033[0m");
            return (1);
        }
        printf("\033[0;33m**********************************\033[0m\n");

        picker(choice, nr);

        printf("\033[0;33m**********************************\033[0m\n");
    }
}
