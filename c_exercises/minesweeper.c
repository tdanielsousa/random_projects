/******************************************************************************
The goal is to develop a program that simulates a simplified version of the
game Minesweeper. The game consists of an array with 10 positions. Of these 10
positions,
    2 contain "bombs",
represented by the value
    -1. The remaining positions contain the value 0. At the start of the game,
the position of the bombs must be defined randomly. The contents of the array
must not be shown to the player. In each turn, the player chooses a position
of the array (for example,
    an index between 0 and 9).
 Rules:
o If they choose a bomb → they lose;
o Otherwise → show a number (it can be 0 or another simple value);
o The game continues until the player finds a bomb (defeat), or the player
discovers all the positions without a bomb (victory).
*******************************************************************************/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void map_declaration(int map[10][10])
{
    int r;
    int c;

    r = 0;
    while (r < 10)
    {
        c = 0;
        while (c < 10)
        {
            map[r][c] = 0;
            c++;
        }
        r++;
    }
}

void bomb_generator(int map[10][10])
{
    int i;

    i = 0;
    int added, last_index, generated;
    while (i < 10)
    {
        added = 0;
        last_index = -1;
        while (added < 2)
        {
            generated = rand() % 10;
            if (generated != last_index)
            {
                map[i][generated] = -1;
                last_index = generated;
                added++;
            }
        }
        i++;
    }
}

void display_map(int map[10][10], bool should_print)
{
    int r;
    int c;

    if (should_print)
    {
        r = 0;
        while (r < 10)
        {
            c = 0;
            while (c < 10)
            {
                printf("%d ", map[r][c]);
                c++;
            }
            printf("\n");
            r++;
        }
    }
}

void display_map_player(int map[10][10], bool show_bombs)
{
    int r;
    int c;

    r = 0;
    printf("\033[0;33m");
    printf("*********************************************\n");
    printf("|    0 - Not played, C - Played, 99 - exit  |\n");
    printf("*********************************************\n");
    printf("   1  2  3  4  5  6  7  8  9  10 \n");
    printf("\033[0m");
    while (r < 10)
    {
        if (r == 9)
        {
            printf("\033[0;33m%d\033[0m", r + 1);
        }
        else
        {
            printf("\033[0;33m%d \033[0m", r + 1);
        }
        c = 0;
        while (c < 10)
        {
            if (show_bombs)
            {
                printf("%d ", map[r][c]);
            }
            else if (map[r][c] == 0 || map[r][c] == -1)
            {
                printf("\033[0;36m O \033[0m");
            }
            else if (map[r][c] == 1)
            {
                printf("\033[1;33m C \033[0m");
            }
            c++;
        }
        printf("\n");
        r++;
    }
}

void check_bomb(int map[10][10], int r, int c)
{
    if (map[r - 1][c - 1] == -1)
    {
        printf("\033[0;35mBOOOOOOOM!  bomb at [%d][%d].\n\033[0m", r, c);
        printf("\033[1;35mGAME OVER\n\033[0m");
        exit(0);
    }
}

/*while (getchar() != '\n'); buff clear?*/
void handle_input(int map[10][10])
{
    int row_val, col_val;
    int status_row, status_col;
    while (1)
    {
        printf("\033[0;35mEnter row (1-10): \033[0m");
        status_row = scanf("%d", &row_val);
        if (row_val == 99)
        {
            printf("\033[0;35m99 to exit with success\n\033[0m");
            exit(0);
        }
        if (status_row != 1 || row_val < 1 || row_val > 10)
        {
            printf("\033[0;35mInvalid row\n\033[0m");
            while (getchar() != '\n')
                ;
            continue;
        }
        printf("\033[0;35mEnter column (1-10): \033[0m");
        status_col = scanf("%d", &col_val);
        if (col_val == 99)
        {
            printf("\033[0;35m99 to exit with success\n\033[0m");
            exit(0);
        }
        if (status_col != 1 || col_val < 1 || col_val > 10)
        {
            printf("\033[0;35mInvalid col\n\033[0m");
            while (getchar() != '\n')
                ;
            continue;
        }
        check_bomb(map, row_val, col_val);
        map[row_val - 1][col_val - 1] = 1;
        break;
    }
}

void game_loop(int map[10][10])
{
    while (1)
    {
        display_map_player(map, false);
        handle_input(map);
        printf("\033[H\033[J");
    }
}

int main(void)
{
    int map[10][10];
    srand(time(NULL));

    map_declaration(map);
    bomb_generator(map);
    display_map(map, false);
    game_loop(map);

    return (0);
}
