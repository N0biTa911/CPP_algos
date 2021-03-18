//Rat in Maize Code

#include <iostream>
using namespace std;

bool isOne(int x, int y, int maze[4][4]){
    if (maze[x][y] == 1){
        return true;
    }
    return false;
}

bool isInWrong(int n, int m, int wrongMoves[60][2], int wrongMovesInd){
    if (n != 0 && m != 0){
        for (int i = 0; i < wrongMovesInd; i++){
            if (wrongMoves[i][0] == n && wrongMoves[i][1] == m){
                return true;
            }
        }
    }
    return false;
}


void search(int n, int m, int maze[4][4], int moves[60][2], int movesInd, int wrongMoves[60][2], int wrongMovesInd, int targetX, int targetY){
    if (n == targetX && m == targetY){
        cout << "R" << " " << "C" << endl;
        for (int i = 0; i < movesInd; i++){
            cout << moves[i][0] + 1 << " " << moves[i][1] + 1 << endl;
        }
    }else if (isOne(n, m+1, maze) && !isInWrong(n, m+1, wrongMoves, wrongMovesInd) && n > -1 && m+1 > -1 && n <= targetX && m+1 <= targetY){
        moves[movesInd][0] = n;
        moves[movesInd][1] = m+1;
        movesInd++;
        search(n, m+1, maze, moves, movesInd, wrongMoves, wrongMovesInd, targetX, targetY);
    }else if (isOne(n+1, m, maze) && !isInWrong(n+1, m, wrongMoves, wrongMovesInd) && n+1 > -1 && m > -1 && n+1 <= targetX && m <= targetY){
        moves[movesInd][0] = n+1;
        moves[movesInd][1] = m;
        movesInd++;
        search(n+1, m, maze, moves, movesInd, wrongMoves, wrongMovesInd, targetX, targetY);
    }else if(isOne(n-1, m, maze) && !isInWrong(n-1, m, wrongMoves, wrongMovesInd) && n-1 > -1 && m > -1 && n-1 <= targetX && m <= targetY){
        moves[movesInd][0] = n;
        moves[movesInd][1] = m-1;
        movesInd++;
        search(n, m-1, maze, moves, movesInd, wrongMoves, wrongMovesInd, targetX, targetY);
    }else{
        wrongMoves[wrongMovesInd][0] = n;
        wrongMoves[wrongMovesInd][1] = m;
        wrongMovesInd++;
        movesInd--;
        moves[movesInd][0] = 0;
        moves[movesInd][1] = 0;
        search(moves[movesInd - 1][0], moves[movesInd - 1][1], maze, moves, movesInd, wrongMoves, wrongMovesInd, targetX, targetY);
    }
}

int main(){
    int i, j, n, m;
    //cin >> n;
    //cin >> m;
    n = 4;
    m = 4;
    //int maze[30][30];
    int maze[4][4] = {{1, 1, 0, 0}, {0, 1, 1, 1}, {0, 1, 0, 0}, {1, 1, 1, 1}};
    int moves[60][2];
    int movesInd = 0;
    int wrongMoves[60][2];
    int wrongMovesInd = 0;
    /*
    for (i = 0; i < n; i++){
        for (j = 0; j < m; j++){
            cin >> maze[n][m];
        }
    }
    */
   
    search(0, 0, maze, moves, movesInd, wrongMoves, wrongMovesInd, m - 1, n - 1);
    return 0;
}
