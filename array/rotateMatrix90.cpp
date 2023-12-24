#include<bits/stdc++.h>
#include<vector>
using namespace std;


/*Brute force
time - O(n^2)
space - O(n^2)*/
vector<vector<int>> rotate(vector<vector<int>>& matrix) {
        
    int n = matrix.size();
    vector<vector<int>> ans(n, vector<int>(n,0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ans[j][n-1-i] = matrix[i][j]; 
        }
        
    }
    return ans;
    
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
    vector<vector<int>> ans = rotate(matrix);
    cout << "After :\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << ans[i][j] << "\t";
        }
        cout << endl;
    }

    
    return 0;
}