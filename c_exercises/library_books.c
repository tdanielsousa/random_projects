/******************************************************************************

Create a C program that uses structures (structs) to store
    information about the books of a library.
The program must allow the entry of data for multiple books and
    display the stored information.
The information for each book must include whatever you consider most
    relevant, such as the title, the author, etc.

The program must:
- Define a structure to store the information of each book.
- Ask the user how many books they want to register.
- Allow data entry for the books (one at a time).
- After the data has been entered, display the information of all the
    registered books in a formatted way.

Recommendations:
- Use functions to organize your code.
- The number of books to be registered must be at most 100.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct s_book
{
    char title[140];
    char author[140];
    int year;
} t_book;

void clear_buffer(void)
{
    while (getchar() != '\n')
        ;
}

int get_user_count(void)
{
    int count;

    count = 0;
    printf("\033[0;33m**************************************************\n\033[0m");
    printf("\033[0;35mHow many books do you want to register? \n\033[0m");
    if (scanf("%d", &count) != 1)
    {
        clear_buffer();
        return (0);
    }
    if (count < 1 || count > 100)
        return (0);
    return (count);
}

void fill_struct_members(t_book* books, int count)
{
    int i;

    i = 0;
    printf("\033[0;33m**************************************************\n\033[0m");
    while (i < count)
    {
        printf("\033[0;36m--- Book \033[0m%d \033[0;36m---\033[0m\n", i + 1);
        printf("\033[0;31mTitle: \033[0m");
        while (scanf(" %[^\n]s", books[i].title) == -1)
            clear_buffer();
        printf("\033[0;31mAuthor: \033[0m");
        while (scanf(" %[^\n]s", books[i].author) == -1)
            clear_buffer();
        printf("\033[0;31mYear: \033[0m");
        while (scanf("%d", &books[i].year) != 1)
        {
            printf("\033[1;31mInvalid year, enter it again:\n \033[0m");
            clear_buffer();
        }
        i++;
    }
}

void display_books(t_book* books, int count)
{
    int i;

    i = 0;
    printf("\n\033[0;33m**************************************************\n\033[0m");
    printf("\033[1;32mBook list:\n\n\033[0m");
    while (i < count)
    {
        printf("\033[0;33mBook \033[0;36m%d\033[0;33m: ", i + 1);
        printf("Title: [\033[0m%s\033[0;33m] by [\033[0m%s\033[0;33m] from the year: "
               "[\033[0m%d\033[0;33m]\n",
               books[i].title, books[i].author, books[i].year);
        i++;
    }
    printf("\033[0;33m**************************************************\033[0m\n");
}

int main(void)
{
    t_book* book_list;
    int book_count;
    int option;
    int set;

    book_list = NULL;
    set = 0;
    book_count = 0;
    while (1)
    {
        printf("\033[0;33m**************************************************\n\033[0m");
        printf("\033[0;36m--- 1 - Enter number of books:     ---\n");
        printf("--- 2 - Enter book data            ---\n");
        printf("--- 3 - Print book data            ---\n");
        printf("--- 4 - Exit                       ---\n");
        printf("--- Choose an option:              ---\033[0m\n");
        while (scanf("%d", &option) != 1 || option < 1 || option > 4)
        {
            printf("\033[1;31mError, invalid option, try again \n\033[0m");
            clear_buffer();
        }
        if (option == 1)
        {
            if (book_list != NULL)
                free(book_list);
            book_count = get_user_count();
            book_list = (t_book*)malloc(sizeof(t_book) * book_count);
            if (!book_list)
                return (1);
            set = 1;
        }
        else if (option == 2)
        {
            if (set < 1)
                printf("\033[1;31mSet the number of books first\n\033[0m");
            else
            {
                fill_struct_members(book_list, book_count);
                set = 2;
            }
        }
        else if (option == 3)
        {
            if (set < 2)
                printf("\033[1;31mEnter the data first\n\033[0m");
            else
                display_books(book_list, book_count);
        }
        if (option == 4)
            break;
    }
    free(book_list);
    return (0);
}
