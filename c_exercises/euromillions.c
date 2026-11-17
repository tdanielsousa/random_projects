#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_COUNT 5
#define STAR_COUNT 2
#define NUM_MAX 50
#define STAR_MAX 12

bool is_unique(int* arr, int size, int value)
{
    int i;

    i = 0;
    while (i < size)
    {
        if (arr[i] == value)
        {
            return (false);
        }
        i++;
    }
    return (true);
}

void generate_numbers(int* numbers, int count, int max)
{
    int i;
    int n;

    i = 0;
    while (i < count)
    {
        n = (rand() % max) + 1;
        if (is_unique(numbers, i, n) == true)
        {
            numbers[i] = n;
            i++;
        }
    }
}

void print_array(int* arr, int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        printf("\033[1;36m%d \033[0m", arr[i]);
        i++;
    }
}

int main(void)
{
    int numbers[NUM_COUNT];
    int stars[STAR_COUNT];

    srand(time(NULL));
    generate_numbers(numbers, NUM_COUNT, NUM_MAX);
    generate_numbers(stars, STAR_COUNT, STAR_MAX);
    printf("\033[1;33mNumbers: \033[0m");
    print_array(numbers, NUM_COUNT);
    printf("\n");
    printf("\033[1;33mStars: \033[0m");
    print_array(stars, STAR_COUNT);
    printf("\n");
    return (0);
}
