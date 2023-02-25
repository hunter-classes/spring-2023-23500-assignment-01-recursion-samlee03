#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>


void print_board(int board[5][5]){
//   std::cout << "[0;0H\n";
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            if (board[i][j] == 0){
                std::cout << "  :";
            } else if (board[i][j] < 10){
                std::cout << " " << board[i][j] << ":";
            } else {
                std::cout << board[i][j] << ":";
            }
        }
        std::cout << "\n";
    }
    return;
}

// SOLVE FUNCTION
void solve(int board[5][5], int row, int column, bool &solved, int move){

    int visited = -1; 
    if (board[row][column] == 24){
        solved = true;
        // Final Product is printed here
        print_board(board);
        return;
    }
    if (row > 4 || row < 0 || column < 0 || column > 4){
        return;
    }
    if ((board[row][column] != 0 && (board[row][column] <= move))){
        return;
    }
    if (board[row][column] == visited){
        return;
    }
    
    board[row][column] = move;
    // usleep(80000);
    // print_board(board);
    

    // Possible Moves
    if (!solved) solve(board, row-2, column+1, solved, move+1);
    if (!solved) solve(board, row-1, column+2, solved, move+1);
    if (!solved) solve(board, row+1, column+2, solved, move+1);
    if (!solved) solve(board, row+2, column+1, solved, move+1);
    if (!solved) solve(board, row+2, column-1, solved, move+1);
    if (!solved) solve(board, row+1, column-2, solved, move+1);
    if (!solved) solve(board, row-1, column-2, solved, move+1);
    if (!solved) solve(board, row-2, column-1, solved, move+1);

    if (!solved) board[row][column] = 0;
}
int main(){
    int board[5][5] = 
    {
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0}
    };

    bool solved = false;

    solve(board, 0, 0, solved, 1);

    return 0;
}
