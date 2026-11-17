#include <stdio.h>

/*
Create an algorithm that receives the ages of 10 people, then displays a
message stating whether each of these people is an "adult" or a "minor".
Consider ages from 18 (inclusive) as adult.
At the end, the program must tell the user how many adults and minors
they entered.
*/

int main()
{
    int arr[9];
    int i;
    int maiores;
    int menores;
    i = 0;
    maiores = 0;
    menores = 0;

    while (i <= 9)
    {
        printf(" -------------------------  \n");
        printf(" Enter the age of person %d: \n", (i + 1));
        printf(" -------------------------  \n");
        scanf("%d", &arr[i]);
        if (arr[i] < 0 || arr[i] > 125)
        {
            printf(" Enter a realistic value for person %d !\n", (i + 1));
            continue;
        }
        if (arr[i] >= 18)
        {
            printf(" Person %d is an adult\n", (i + 1));
            maiores++;
        }
        else
        {
            printf(" Person %d is a minor\n", (i + 1));
            menores++;
        }
        i++;
    }
    printf(" -------------------------  \n");
    printf(" ----- Final summary -----  \n");
    printf(" In total, %d people are adults \n", maiores);
    printf(" In total, %d people are minors \n", menores);
    printf(" -------------------------  \n");

    return 0;
}
