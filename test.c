/* Tic Tac Toe Exercise in C Progeamming */
/* Author - Binghuan W Li    */
/* Date   - 19 December 2021 */


#include <stdio.h>
#include <Windows.h>
#include <ctype.h>
#include <stdlib.h>

char board[10] = {'0','1','2','3','4','5','6','7','8','9'};
unsigned char player;


// switch plater: X->O, O->X
char switchPlayer(unsigned char player){
    if (player == 'X'){
        player = 'O';
    }
    else{
        player = 'X';
    }

    return player;
}

// board formatting
void printBoard(){

    printf("|---|---|---| \n");
    printf("| %c | %c | %c |\n", board[1],board[2],board[3]);
    printf("|---|---|---| \n");

    printf("| %c | %c | %c |\n", board[4],board[5],board[6]);
    printf("|---|---|---| \n");

    printf("| %c | %c | %c |\n", board[7],board[8],board[9]);
    printf("|---|---|---| \n");
}

// check winning condition
int checkWin(){
    if (board[1] == board[2] && board[1] == board[3]){
        return 1;
    }
    else if (board[4] == board[5] && board[5] == board[6]){
        return 1;
    }
    else if (board[7] == board[8] && board[8] == board[9]){
        return 1;
    }
    else if (board[1] == board[4] && board[4] == board[7]){
        return 1;
    }
    else if (board[2] == board[5] && board[5] == board[8]){
        return 1;
    }
    else if (board[3] == board[6] && board[6] == board[9]){
        return 1;
    }
    else if (board[1] == board[5] && board[5] == board[9]){
        return 1;
    }
    else if (board[3] == board[5] && board[5] == board[7]){
        return 1;
    }
    else if(board[1] != '1' && board[2] != '2' && board[3] != '3' &&
        board[4] != '4' && board[5] != '5' && board[6] != '6' && board[7]
        != '7' && board[8] != '8' && board[9] != '9'){
        printf("It is a tie! \n");
        return 1;
        }
    else{
        return -1;
    }
}

// check input compliance and update board
int updateBoard(unsigned char position){
    int pos;

    // is it an int?
    if(isdigit(position) == 1){

        // type conversion: char -> int
        pos = position - '0';

        // is this position unoccupied?
        if(board[pos] == 'X' || board[pos] == 'O'){
            printf("\n");
            printf("Sorry, this position has been taken. Please re-enter a position. \n");
            printf("Hi, player %c, it is your turn. Which position would you like to take? \n", player);

            return 3;
        }
        else{
            // all good, update board
            board[pos] = player;

            return 4;
        }
    }
    // not a digit, ask for re-enter
    else if (isdigit(position) == 0){
        printf("\n");
        printf("Not a digit! Please re-enter a number from 1-9. \n");
        printf("Hi, player %c, it is your turn. Which position would you like to take? \n", player);

        return 3;
   }
}


int main() {
    printf("Tic Tac Toe \n");
    printBoard();

    player = 'X';
    int game = -1;
    unsigned char position;

    do{
        printf("\n");
        printf("Hi, player %c, it is your turn. Which position would you like to take? \n", player);
        scanf("%s", &position);

        // receive state from updateBoard function
        int state = updateBoard(position);
        while(state != 4){
            // not good, ask for re-entering a position
            scanf("%s", &position);
            state = updateBoard(position);
        }

        printf("\n");
        printBoard();
        game = checkWin();

        player = switchPlayer(player);
    }while(game != 1);

    if (game == 1){
        printf("\nPlayer %c win!\n", player);
    }

    return 0;

}

