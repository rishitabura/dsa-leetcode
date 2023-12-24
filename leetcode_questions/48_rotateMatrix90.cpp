#include<bits/stdc++.h>
#include<vector>
using namespace std;

/*constant space
time - O(n*n)+O(n*n)
space - O(1)*/

void rotate(vector<vector<int>>& matrix) {

    int n = matrix.size();

    // step 1 - transpose
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
        
    }

    // step 2 - reverse every row
    for (int i = 0; i < n; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}


int main()
{
    vector<vector<int>> matrix = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    rotate(matrix);
    cout << "After :\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    
    return 0;
}