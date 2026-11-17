#include <stdio.h>
#include <stdlib.h>

#define LIBRAS 0.8672
#define DOLARES 1.1517
#define REAIS 6.0535

/*
Write an algorithm that asks the user to enter a monetary value in euros.
At the end, the program must display on the screen the entered value converted
to dollars, pounds sterling and reais.
Use the Banco de Portugal website to look up the exchange rates of the
currencies mentioned:
https://www.bportugal.pt/page/conversor-de-moeda
*/
int main()
{
    float euros;
    float temp;

    printf(" -------------------------  \n");
    printf(" Enter the amount in euros:  \n");
    printf(" -------------------------  \n");
    scanf("%f", &euros);

    if (euros <= 0)
    {
        printf(" Enter a valid amount \n");
        exit(0);
    }
    printf(" ------------------------  \n");
    printf(" Currency converter  \n");
    printf(" ------------------------  \n");
    printf(" Amount entered in euros: %f \n", euros);
    printf("  ------------------------  \n");
    printf(" Converted values:  \n");
    temp = (euros * LIBRAS);
    printf(" In Pounds: %.2f \n", temp);
    temp = (euros * DOLARES);
    printf(" In Dollars: %.2f \n", temp);
    temp = (euros * REAIS);
    printf(" In Reais: %.2f \n", temp);
    printf(" ------------------------ \n");

    return 0;
}
