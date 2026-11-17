/******************************************************************************

In a data analysis system,
    it is often necessary to identify common elements
between different sets of information.
In this exercise,
    you will work with two integer vectors and determine
which values appear in both.

Develop a C program that:
- Declares two integer vectors A and B,
    each with capacity to store 10
elements.
- Asks the user to enter the values of each vector.
- Creates a third vector C, where the elements that exist
simultaneously in both vectors (intersection) must be stored.
- Displays the contents of vector C on the screen.

Important rules:
- Each value must appear only once in the intersection vector,
    even if it is
repeated in the original vectors.
- If there are no common elements, the program must display a
message indicating this.
- Using external libraries other than the basic ones (stdio.h) is not allowed.

*******************************************************************************/

#include <stdbool.h>
#include <stdio.h>

int read_data(int* vector, char name)
{
    int i, status;
    printf("\033[0;33m**********************************\033[0m\n");
    printf("\033[0;35mEnter the 10 values of vector %c:\033[0m\n", name);
    for (i = 0; i < 10; i++)
    {
        printf("Vector %c[%d]: ", name, i);
        status = scanf("%d", &vector[i]);
        if (status != 1)
        {
            printf("\033[1;31mError reading input\n\033[0m");
            i--;
            while (getchar() != '\n')
                ;
            continue;
        }
    }
    while (getchar() != '\n')
        ;
    return (0);
}

int check_intersection(int* A, int* B, int* C)
{
    int i;
    int j;
    int c_count;
    int index_check;
    bool exists;

    c_count = 0;
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            if (A[i] == B[j])
            {
                exists = false;
                for (index_check = 0; index_check < c_count; index_check++)
                {
                    if (C[index_check] == A[i])
                    {
                        exists = true;
                        break;
                    }
                }
                if (!exists)
                {
                    C[c_count] = A[i];
                    c_count++;
                }
                break;
            }
        }
    }
    return (c_count);
}

void print_c_arr(int* C, int size)
{
    printf("\033[0;33m**********************************\033[0m\n");
    if (size == 0)
    {
        printf("\033[1;31mThere are no common elements in the vectors \n\033[0m");
    }
    else
    {
        printf("\033[0;32mIntersection (Vector C): \033[0m");
        for (int i = 0; i < size; i++)
        {
            printf("%d ", C[i]);
        }
        printf("\n");
    }
    printf("\033[0;33m**********************************\033[0m\n");
}

int main(void)
{
    int A[10];
    int B[10];
    int C[10];
    int size_c;

    if (read_data(A, 'A') != 0)
        return (1);
    if (read_data(B, 'B') != 0)
        return (1);
    size_c = check_intersection(A, B, C);
    print_c_arr(C, size_c);
    return (0);
}
