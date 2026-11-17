#include <stdio.h>

/*
 */
int main()
{
    float n1;
    float n2;
    int op;
    float res;

    while (1)
    {
        printf("\033[0;36m-------------------------------------  \n");
        printf("Invalid inputs end the program \n");
        printf("Ex: type mismatch, operation greater than 4... \n");
        printf("-------------------------------------  \033[0m\n");
        printf("\033[0;33m Enter the first value:  \n\033[0m");
        if (scanf("%f", &n1) != 1)
        {
            printf("\033[0;31mInvalid number\n\033[0m");
            break;
        }

        printf("\033[0;33m Enter the second value:  \n\033[0m");
        if (scanf("%f", &n2) != 1)
        {
            printf("\033[0;31mInvalid number\n\033[0m");
            break;
        }

        printf("\033[0;33m-------------------------  \n");
        printf("Choose the type of operation \n");
        printf("1 >  + \n");
        printf("2 >  - \n");
        printf("3 >  * \n");
        printf("4 >  / \n");
        printf("-------------------------  \033[0m\n");
        if ((scanf("%d", &op) != 1) || op < 1 || op > 4)
        {
            printf("\033[0;31mInvalid operation\n\033[0m");
            break;
        }
        if (op == 1)
            res = n1 + n2;
        else if (op == 2)
            res = n1 - n2;
        else if (op == 3)
        {
            if (n2 == 0)
            {
                printf("\033[0;32mResult: 0 \n\033[0m");
                continue;
            }
            res = n1 * n2;
        }
        else if (op == 4)
        {
            if (n2 == 0)
            {
                printf("\033[0;32mResult: Division by zero is undefined \n\033[0m");
                continue;
            }
            res = n1 / n2;
        }
        printf("\033[0;32mResult: %f \n\033[0m", res);
    }
    return 0;
}