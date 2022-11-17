#include "bingoboard.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#define N_SIZE 5
#define N_BINGO 2
#define BINGO_NUMSTATUS_ABSENT -1
#define BINGO_NUMSTATUS_PRESENT 0
#define BINGO_RES_UNFINISHED 0
#define BINGO_RES_FINISHED 1
static int bingoBoard[N_SIZE][N_SIZE];
static int numberStatus[N_SIZE*N_SIZE];

void bingo_printBoard(void){
    int row,col;
    printf("===========================\n");
     for(row = 0; row < N_SIZE; row++) {
        for(col = 0; col < N_SIZE; col++) {
            //board[row][col] = random = rand() % 25 + 1;
            if (bingoBoard[row][col] > 0){
                printf("%i\t", bingoBoard[row][col]);
            } else {
                printf("X\t");
            }
                
            
        }
        printf("\n");
    }
     printf("===========================\n\n");
    printf("number of completedLines : %i \n", bingo_countCompletedLine());
}

void bingo_init(void) {
    int i,j, k;
    int randNum;
    int maxNum = N_SIZE * N_SIZE;
    for (i=0; i<N_SIZE*N_SIZE; i++){
        numberStatus[i] = -1;
    }
    for (i = 0;i < N_SIZE; i++) {
        for (j = 0; j < N_SIZE; j++) {
            randNum = rand() % maxNum; 
            //0~maxNum-1 의 수 생성 
            int cnt = 0;
            for (k=0;k<N_SIZE*N_SIZE;k++){
                if (numberStatus[k] == -1){
                    if (cnt == randNum) {
                        break;
                    }
                    cnt++;
                }
                
            }
            bingoBoard[i][j] = k + 1;
            numberStatus[k] = N_SIZE*i + j;
            maxNum--;
        }
    }
    for (i=0; i<N_SIZE*N_SIZE; i++){
        printf("%d  ", numberStatus[i]);
    }
    printf("\n");
     for (i=1; i<=N_SIZE*N_SIZE; i++){
        printf("%d  ", i);
    }
    printf("\n");
}

void bingo_inputNum(int sel) {
    //printf("input a number to X");
    int a = numberStatus[sel-1];
    bingoBoard[a/N_SIZE][a%N_SIZE] = 0;
    numberStatus[sel-1] = -1;
    
}

int bingo_countCompletedLine(void) {
    int i,j;
    int cnt = 0;
    int checkBingo;
    
    for (i=0;i<N_SIZE; i++){
        checkBingo = 1;
        for (j=0; j<N_SIZE;j++){
            if (bingoBoard[i][j] > 0)  {
                checkBingo = 0;
                break;
            }
        }
        if (checkBingo == 1){
            cnt++;
        }
    }
    return cnt;
}

int get_number(void){
    //번호 선택
    int selNum = 0;
    do {
        printf("select a number : ");
        scanf("%d", &selNum);
        fflush(stdin);
        
        if(bingo_checkNum(selNum) == BINGO_NUMSTATUS_ABSENT){
            printf("%i is not on the board! select other one. \n", selNum);
            
        }
    } while(selNum < 1 || selNum > N_SIZE * N_SIZE || bingo_checkNum(selNum) == BINGO_NUMSTATUS_ABSENT);
    return selNum;
}

int bingo_checkNum(int selNum){
    if (numberStatus[selNum-1] != -1 ) {
        return BINGO_NUMSTATUS_PRESENT;
    }
    return BINGO_NUMSTATUS_ABSENT;
}

int check_gameEnd(void){
    int res = BINGO_RES_UNFINISHED;
    if (bingo_countCompletedLine() >= N_BINGO ) {
        return BINGO_RES_FINISHED;
    }
    return res;
}
