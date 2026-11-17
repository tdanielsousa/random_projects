/******************************************************************************
 *
How the system works
The vault key is made up of 5 digits, stored internally by the system. The user
will try to guess this key by also entering 5 digits, in the same order.

 The program must:

1. Define the secret key
- An array of 5 positions with integer values predefined in the code
Example (they may be values drawn by the program):
Secret key: {1, 3, 0, 9, 2}

2. Ask the user for their attempt
- The program must ask for 5 digits:
Enter the vault key (5 integers):

3. Compare the two keys
- The program must compare:
✓ position by position
✓ value by value
- And calculate:
✓ how many digits are correct
✓ how many digits are wrong
✓ whether the key was discovered

 Validation rules
- A digit is considered correct only if it has:
✓ the same value
✓ and the same position
- A wrong digit does not count as correct in any position

 The program must display:
- key entered by the user
- number of correct positions
- number of incorrect positions
- final result message

 Example run
=== TORRADUS THE DRAGON'S VAULT ===
--- GUESS/ATTEMPT ---
Enter the key (5 digits):
1 2 7 8 2
--- ANALYSIS RESULT ---
Correct key:
1 3 0 9 2
Attempt:
1 2 7 8 2
Correct positions: 2 of 5
Incorrect positions: 3 of 5
Vault status: STILL CLOSED

 Special case
- If the user gets all the values right:
- Congratulations! The key has been deciphered.
- The dragon wakes up furious... but the vault is open.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void clear_buffer(void)
{
    while (getchar() != '\n')
        ;
}

void print_integer_array(char* label, int array[])
{
    printf("\033[0;36m%s: [ \033[0m", label);

    for (int i = 0; i < 5; i++)
    {
        printf("%d", array[i]);
        if (i < 4)
        {
            printf(", ");
        }
    }
    printf("\033[0;36m ]\033[0m\n");
}

void code_generator(int (*code)[5])
{
    int i = 0;
    int random_num;

    while (i < 5)
    {
        random_num = rand() % 10;
        (*code)[i] = random_num;
        i++;
    }
}

void get_user_code(int (*user_code)[5])
{
    int i = 0;
    int status;
    int temp;

    while (i < 5)
    {
        printf("\033[0;33m**********************************\033[0m\n");
        printf("\033[0;31mEnter the value for position %d : \033[0m", (i + 1));
        status = scanf("%d", &temp);
        while (status != 1 || temp < 0 || temp > 9)
        {
            printf("\033[1;35mError in the number entered\n\033[0m");
            clear_buffer();
            printf("\033[0;31mEnter the value for position %d : \033[0m", (i + 1));
            status = scanf("%d", &temp);
        }
        (*user_code)[i] = temp;
        i++;
    }
    printf("\033[0;33m**********************************\033[0m\n");
}

void compare_codes(int (*code)[5], int (*user_code)[5], int (*code_result)[5])
{
    int i = 0;

    while (i < 5)
    {
        if ((*code)[i] == (*user_code)[i])
        {
            (*code_result)[i] = 0;
        }
        else
            (*code_result)[i] = 1;
        i++;
    }
}

void print_diferential_code(int (*code_result)[5])
{
    int i = 0;
    int correct = 0;
    int wrong = 0;

    while (i < 5)
    {
        if ((*code_result)[i] == 0)
        {
            correct++;
        }
        else
            wrong++;
        i++;
    }
    printf("\033[1;32m\n Correct positions: %d\033[0m\n", correct);
    printf("\033[1;31m Incorrect positions: %d\033[0m\n", wrong);

    if (correct != 5)
    {
        printf("\033[1;31m\n --------------------------------------\033[0m\n");
        printf("\033[1;31m --- Vault status: STILL CLOSED ---\033[0m");
        printf("\033[1;31m\n --------------------------------------\033[0m\n");
    }
    else
    {
        printf(
            "\033[1;31m\n ---------------------------------------------------------\033[0m\n");
        printf("\033[1;34m\n --- Congratulations! The key has been deciphered ---\033[0m\n");
        printf("\033[1;34m\n --- The dragon wakes up furious... but the vault is open. "
               "---\033[0m\n");
        printf(
            "\033[1;31m\n ---------------------------------------------------------\033[0m\n");
    }
}

int main()
{
    srand(time(NULL));
    int code[5];
    int user_code[5];
    int code_result[5];

    code_generator(&code);

    printf("\033[0;33m**********************************\033[0m\n");
    printf("\033[1;33m   === TORRADUS THE DRAGON'S VAULT === \033[0m\n");

    get_user_code(&user_code);

    compare_codes(&code, &user_code, &code_result);

    print_integer_array("Secret code        ", code);
    print_integer_array("User code          ", user_code);

    print_diferential_code(&code_result);

    return 0;
}
