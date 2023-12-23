#include<bits/stdc++.h>
#include<vector>
using namespace std;


void markRow(vector<vector<int>>& matrix, int row,int col,int i){
    
    for (int j = 0; j < col; j++)
    {
        if(matrix[i][j] !=0)
        {
            matrix[i][j] = -1;
        }
    }
    
}

void markCol(vector<vector<int>>& matrix, int row, int col, int j)
{
    for (int i = 0; i < row; i++)
    {
        if(matrix[i][j] !=0)
        {
            matrix[i][j] = -1;
        }
        
    }
    
}

/*brute force 
time- O(n^3)
not so efficient*/
void BrutesetZeroes(vector<vector<int>>& matrix) {

    int row = matrix.size();
    int col = matrix[0].size();

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if(matrix[i][j] == 0)
            {
                markRow(matrix,row,col,i);
                markCol(matrix,row,col,j);
            }
        }
        
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if(matrix[i][j] == -1)
            {
                matrix[i][j] = 0;
            }
        }
        
    }
    
        
}

int main()
{
    vector<vector<int>> matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    int row = matrix.size();
    int col = matrix[0].size();
    setZeroes(matrix);

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
        
    }
    
    return 0;
}