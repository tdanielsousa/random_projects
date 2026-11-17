#include <stdio.h>

/*
Create a program that creates a rectangle filled with "*".
The height and width of the rectangle are values defined by the user.
*/
int main()
{
    int altura;
    int largura;
    int i;
    int j;
    i = 0;
    j = 0;

    while (1)
    {
        printf(" -------------------------  \n");
        printf(" Enter the height of the rectangle \n");
        printf(" -------------------------  \n");
        scanf("%d", &altura);

        if (altura <= 0)
        {
            printf(" Enter a valid value for the height \n");
        }
        else
            break;
    }

    while (1)
    {
        printf(" -------------------------  \n");
        printf(" Enter the width of the rectangle \n");
        printf(" -------------------------  \n");
        scanf("%d", &largura);

        if (largura <= 0)
        {
            printf(" Enter a valid value for the width\n");
        }
        else
            break;
    }

    while (i < altura)
    {
        while (j < largura)
        {
            printf("*");
            j++;
        }
        printf("\n");
        j = 0;
        i++;
    }

    return 0;
}