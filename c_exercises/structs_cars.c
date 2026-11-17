/******************************************************************************
 *
Exercise 3 - Structures

Create a program that uses records/structures (structs) to store
data about cars.

a. The structure must have the following data: car brand, model, year and
engine displacement.

b. Your program must have the usual options for inserting and listing
the data.

valgrind --leak-check=full ./a.out

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_cars
{
    char brand[60];
    char model[60];
    int year;
    int hp;
    struct s_cars* next;
} t_cars;

void clear_buffer(void)
{
    while (getchar() != '\n')
        ;
}

void free_car_list(t_cars** head_pointer)
{
    t_cars* current = *head_pointer;
    t_cars* next_car = NULL;

    while (current != NULL)
    {
        next_car = current->next;
        free(current);
        current = next_car;
    }

    *head_pointer = NULL;
}

void car_list_printer(t_cars* car_list)
{
    t_cars* current = car_list;

    printf("\033[0;34m\n--- List of cars in the list ---\033[0m\n");

    while (current != NULL)
    {
        printf("Brand: %s | Model: %s | Year: %d | HP: %d\n", current->brand, current->model,
               current->year, current->hp);

        current = current->next;
    }

    printf("\033[0;34m---------------------------\033[0m\n");
}

t_cars* create_car(char* brand, char* model, int year, int hp)
{
    t_cars* new_car = malloc(sizeof(t_cars));
    if (new_car == NULL)
    {
        return NULL;
    }
    strcpy(new_car->brand, brand);
    strcpy(new_car->model, model);
    new_car->year = year;
    new_car->hp = hp;
    new_car->next = NULL;
    return new_car;
}

void creator(t_cars** car_list)
{
    char brand[60];
    char model[60];
    int year;
    int hp;
    int status;

    printf("\033[0;33m**********************************\033[0m\n");
    printf("\033[0;31mEnter the brand name: \033[0m");
    status = scanf("%59s", brand);

    while (status != 1)
    {
        printf("\033[1;35mError entering data\n\033[0m");
        clear_buffer();
        printf("\033[0;31mEnter the brand name: \033[0m");
        status = scanf("%59s", brand);
    }
    clear_buffer();

    ///////////////////////////////////////////////////////////////////////
    printf("\033[0;33m**********************************\033[0m\n");
    printf("\033[0;31mEnter the model name \033[0m");
    status = scanf("%59s", model);

    while (status != 1)
    {
        printf("\033[1;35mError entering data\n\033[0m");
        clear_buffer();
        printf("\033[0;31mEnter the model name: \033[0m");
        status = scanf("%59s", model);
    }
    clear_buffer();

    ///////////////////////////////////////////////////////////////////////
    printf("\033[0;33m**********************************\033[0m\n");
    printf("\033[0;31mEnter the year \033[0m");
    status = scanf("%d", &year);

    while (status != 1)
    {
        printf("\033[1;35mError entering data\n\033[0m");
        clear_buffer();
        printf("\033[0;31mEnter the year \033[0m");
        status = scanf("%d", &year);
    }
    clear_buffer();

    ///////////////////////////////////////////////////////////////////////
    printf("\033[0;33m**********************************\033[0m\n");
    printf("\033[0;31mEnter the engine displacement \033[0m");
    status = scanf("%d", &hp);

    while (status != 1)
    {
        printf("\033[1;35mError entering data\n\033[0m");
        clear_buffer();
        printf("\033[0;31mEnter the engine displacement \033[0m");
        status = scanf("%d", &hp);
    }
    clear_buffer();

    ///////////////////////////////////////////////////////////////////////

    t_cars* new_car = create_car(brand, model, year, hp);

    if (new_car != NULL)
    {
        new_car->next = *car_list;
        *car_list = new_car;
    }
}

int main(void)
{
    t_cars* car_list;
    int option;
    int car_nr;

    car_list = NULL;
    car_nr = 0;
    while (1)
    {
        printf("\033[0;33m**************************************************\n\033[0m");
        printf("\033[0;36m--- 1 - Add new car                     ---\n");
        printf("--- 2 - Print car data                  ---\n");
        printf("--- 3 - Exit                            ---\n");
        printf("--- Choose an option:                   ---\033[0m\n");
        while (scanf("%d", &option) != 1 || option < 1 || option > 3)
        {
            printf("\033[1;31mError, invalid option, try again \n\033[0m");
            clear_buffer();
        }
        if (option == 1)
        {
            creator(&car_list);
            printf("\033[0;33m**************************************************\n\033[0m");
            printf("\033[1;31mCar added successfully\n\033[0m");
            car_nr++;
        }
        else if (option == 2)
        {
            if (car_nr < 1)
            {
                printf(
                    "\033[0;33m**************************************************\n\033[0m");
                printf("\033[1;31mThe list is empty\n\033[0m");
                continue;
            }
            car_list_printer(car_list);
        }
        else if (option == 3)
        {
            printf("\033[1;31mExited successfully!\n\033[0m");
            break;
        }
    }

    free_car_list(&car_list);
    return (0);
}
