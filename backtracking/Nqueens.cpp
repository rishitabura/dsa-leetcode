// #include <bits/stdc++.h>
// #include <vector>
// using namespace std;

// bool isSafe(vector<vector<int>> &board, int row, int col, int n)
// {
//     for (int c = 0; c < col; c++)
//     {
//         if (board[row][c] == 1)
//         {
//             return false;
//         }
//     }
//     for (int r = row, c = col; r >= 0 && c >= 0; r--, c--)
//     {
//         if (board[r][c] == 1)
//         {
//             return false;
//         }
//     }
//     for (int r = row, c = col; r < n && c >= 0; r++, c--)
//     {
//         if (board[r][c] == 1)
//         {
//             return false;
//         }
//     }

//     return true;
// }

// printSolution(vector<vector<int>> &board, int n)
// {
//     vector<int>ans(n,0);
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             if (board[i][j] == 1)
//             {
//                 ans[i] = j;
//             }
            
//         }
//     }
//     for (int i = 0; i < n; i++)
//     {
//         cout << ans[i] << " ";
//     }
// }

// bool solve(vector<vector<int>> &board, int col, int n)
// {
//     if (col == n)
//     {
//         printSolution(board, n);
//         return true;
//     }
    
//     for (int row = 0; row < n; row++)
//     {
//         if (isSafe(board, row, col, n))
//         {
//             board[row][col] = 1;
//             if (solve(board, col + 1, n))
//             {
//                 return true;
//             }
//             board[row][col] = 0;
//         }
//     }
//     return false;
// }

// int main()
// {
//     int n = 4;
//     vector<vector<int>> board(n, vector<int>(n, 0));
//     solve(board, 0,n);

//     return 0;
// }

#include <bits/stdc++.h>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>> &board, int row, int col, int n)
{
    for (int c = 0; c < col; c++)
    {
        if (board[row][c] == 1)
        {
            return false;
        }
    }
    for (int r = row, c = col; r >= 0 && c >= 0; r--, c--)
    {
        if (board[r][c] == 1)
        {
            return false;
        }
    }
    for (int r = row, c = col; r < n && c >= 0; r++, c--)
    {
        if (board[r][c] == 1)
        {
            return false;
        }
    }

    return true;
}

printSolution(vector<vector<int>> &board, int n)
{
    vector<int>ans(n,0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 1)
            {
                ans[i] = j;
            }
            
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
}

void solve(vector<vector<int>> &board, int col, int n)
{
    if (col == n)
    {
        return ;
    }
    
    for (int row = 0; row < n; row++)
    {
        if (isSafe(board, row, col, n))
        {
            board[row][col] = 1;
            solve(board, col + 1, n);
            board[row][col] = 0;
        }
    }
}

int main()
{
    int n = 4;
    vector<vector<int>> board(n, vector<int>(n, 0));
    solve(board, 0,n);

    return 0;
}