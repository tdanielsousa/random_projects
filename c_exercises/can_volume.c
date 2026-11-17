#include <stdio.h>

/*
Create an algorithm that calculates the volume of an oil can,
using the formula Volume = 3.14159 * Radius^2 * Height.
The values for the radius and height of the can must be requested from the user.
*/
int main()
{
    float raio;
    float altura;
    float volume;

    printf(" -------------------------  \n");
    printf(" Enter the radius of the can:  \n");
    printf(" -------------------------  \n");
    scanf("%f", &raio);

    printf(" -------------------------  \n");
    printf(" Enter the height of the can:  \n");
    printf(" -------------------------  \n");
    scanf("%f", &altura);

    volume = (3.14159 * (raio * raio) * altura);
    printf(" -------------------------  \n");
    printf(" The volume is: %.2f \n", volume);
    printf(" -------------------------  \n");

    return 0;
}