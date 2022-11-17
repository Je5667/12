#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N_SIZE 5
#define N_BINGO 1


int main()
{
    int board[5][5];
    srand( (unsigned)time(NULL));
    printf("******************************\n");
    printf("******************************\n");
    printf("********** BINGO GAME ********\n");
    printf("******************************\n");
    printf("******************************\n");
    //generate numbers
    int random = 0;
    
    int row, col;
    
    for(row = 0; row < N_SIZE; row++) {
        for(col = 0; col < N_SIZE; col++) {
            board[row][col] = random = rand() % 25 + 1;
            printf("  %d ", board[row][col]);
            
        }
        printf("\n");
    }
    //initialize bingo board
    
    
    //while game not end 
        //bingo board printf
        //pint no comleted lnes
        //put the number on the board
        

    return 0;
}

