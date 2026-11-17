#include <stdio.h>

/*
In a competition, the swimmer is awarded a prize according to the maximum
distance covered.
If the swimmer covers a distance of less than 800 meters,
they receive a prize of 100.00€.
If they cover a distance between 800 and 1500 meters, they receive 200.00€.
And if they cover a distance greater than 1500 meters, they receive 500.00€
as a prize.
Write a program that reads the distance covered and displays on the screen the
prize amount the swimmer will receive.
*/
int main()
{
    float distancia;

    printf(" -------------------------  \n");
    printf(" Enter the distance covered by the swimmer: \n");
    printf(" -------------------------  \n");
    scanf("%f", &distancia);

    if (distancia < 800 && distancia > 0)
        printf(" You will receive a prize of 100.00€ \n");
    else if (distancia >= 800 && distancia <= 1500)
        printf(" You will receive a prize of 200.00€ \n");
    else if (distancia > 1500)
        printf(" You will receive a prize of 500.00€ \n");
    else
        printf(" Error in the distance covered\n");

    return 0;
}
