/******************************************************************************
The program must:

 Read the following data:
- customer name;
- number of pizzas eaten;
- liters of soda consumed.

 Classify the customer according to the following rules:
===========================================
 Professional Customer
If the customer:
- ate more than 2 pizzas
AND
- drank more than 2 liters
of soda,
display:
Professional pizza customer!
===========================================
 VIP Customer
If the customer:
- ate more than 2 pizzas
OR
- drank more than 2 liters
of soda,
display:
VIP pizza customer!
===========================================
 Normal Customer
If none of the previous
conditions occur,
display:
Normal customer.
===========================================

Example:
Input data:
- Name: Ricardo
- Pizzas: 3
- Soda: 3

Expected result:
Ricardo, is a Professional pizza customer!

*******************************************************************************/

#include <stdio.h>

int main(void)
{
    float nr_pizza;
    float nr_drink;
    char name[60];
    int status;

    printf("\033[0;33m**********************************\033[0m\n");
    printf("\033[0;31mEnter the customer's name: \033[0m");
    status = scanf("%s", name);
    if (status != 1)
    {
        printf("\033[1;35mError in customer name\n\033[0m");
        return (1);
    }
    while (getchar() != '\n')
        ;
    ///////////////////////////////////////////////////////////////////////
    printf("\033[0;33m**********************************\033[0m\n");
    printf("\033[0;31mEnter the number of pizzas: \033[0m");
    status = scanf("%f", &nr_pizza);
    if (status != 1)
    {
        printf("\033[1;35mError in number of pizzas\n\033[0m");
        return (1);
    }
    while (getchar() != '\n')
        ;
    //////////////////////////////////////////////////////////////////////
    printf("\033[0;33m**********************************\033[0m\n");
    printf("\033[0;31mEnter the liters of soda: \033[0m");
    status = scanf("%f", &nr_drink);
    if (status != 1)
    {
        printf("\033[1;35mError in number of liters\n\033[0m");
        return (1);
    }
    while (getchar() != '\n')
        ;
    ////////////////////////////////////////////////////////////////////
    printf("\033[0;33m**********************************\033[0m\n");
    if (nr_pizza > 2.0 && nr_drink > 2.0)
    {
        printf("\033[0;35m%s, is a Professional pizza customer!\n\033[0m", name);
        printf("\033[0;33m**********************************\033[0m\n");
        return 0;
    }
    else if (nr_pizza > 2.0 || nr_drink > 2.0)
    {
        printf("\033[0;35m%s, is a VIP pizza customer!\n\033[0m", name);
        printf("\033[0;33m**********************************\033[0m\n");
        return 0;
    }
    else
    {
        printf("\033[0;35m%s, is a Normal customer.\n\033[0m", name);
        printf("\033[0;33m**********************************\033[0m\n");
        return 0;
    }
}
