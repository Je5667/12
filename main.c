#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bingoboard.h"


int main()
{
    srand( (unsigned)time(NULL));
    printf("******************************\n");
    printf("******************************\n");
    printf("********** BINGO GAME ********\n");
    printf("******************************\n");
    printf("******************************\n");
        //generate numbers
    bingo_init();
    bingo_printBoard();
    do {
        bingo_inputNum(get_number());
        bingo_printBoard();
    } while(check_gameEnd() == 0);
    
    printf("******************************\n");
    printf("******************************\n");
    printf("***CCCCCCONGRATULATIONNNNNN***\n");
    printf("******************************\n");
    printf("******************************\n");
    
    return 0;
}
