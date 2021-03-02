#include<bits/stdc++.h>
using namespace std;
#define M 1050
int board[M][M], cnt, n;

bool isSafe(int row, int col)
{
    int i, j;
    for(i = 1; i < col; i++) if(board[row][i]) return false;
    for(i = row, j = col; i and j; i--, j--) if(board[i][j]) return false;
    for(i = row, j = col; j and i <= n; i++, j--) if(board[i][j]) return false;
    return true;
}

bool solve(int col)
{
    if(col == n+1) ///if all of the n queens are placed
    {
        cnt++; /// a new solution is found, increase no. of solutions.
        return true;
    }
    ///if not all the queens have not been placed, we have job to do.
    bool res = false;
    for(int i = 1; i <= n; i++) ///traverse through all rows of current column, so that we can find a safe cell to place a queen.
    {
        if(isSafe(i, col)) ///if we find a safe cell
        {
            board[i][col] = 1; ///place a queen here.
            res = solve(col + 1) || res; ///let's see if it leads us to a solution
            board[i][col] = 0; ///if it doesn't lead to a solution, undo it.
        }
    }
    return res; ///return if any solution is possible anyway.
}

int main()
{
    cin >> n; /// n * n is the size of the chessboard
    if(solve(1) == false) printf("Solution does not exist"); ///we passed 1 as the parameter
    else cout << cnt << endl; ///print no. of solutions.
}
