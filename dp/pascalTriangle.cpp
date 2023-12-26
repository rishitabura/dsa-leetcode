/*Q1. Given row and col no, find the element at that place in pascal triangle
1. Brute force - generate triangle and then find
2. Use formula - (r-1)C(c-1) if row and col starts from 1

Q2. Print nth row element of pascan triangle
1. Brute force - use the formula method - O(n*r)
2. Optimal - O(n)

Q3. Print the triangle
1. Brute force - O(n^3)
2. Optimal - O(n^2)
*/
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int binomialCoefficient(int n, int r)
{
    int res = 1;
    for (int i = 0; i < r; i++)
    {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}

void BruteprintNthRow(int n) // O(n*r )
{
    for (int c = 1; c <= n; c++) // O(n)
    {
        cout << binomialCoefficient(n - 1, c - 1) << " "; // O(r)
    }
}

void OptprintNthRow(int n) // O(n)
{
    int ans = 1;
    cout << ans << " ";
    for (int c = 1; c < n; c++)
    {
        ans = ans * (n - c);
        ans = ans / c;
        cout << ans << " ";
    }
}

vector<vector<int>>BrutepascalTriangle(int n)
{
    vector<vector<int>> ans;
    for (int r = 1; r <= n; r++)
    {
        vector<int> temp;
        for (int c = 1; c <= r; c++)
        {
            temp.push_back(binomialCoefficient(r - 1, c - 1));
        }
        ans.push_back(temp);
    }
    return ans;
}

vector<int> generateRow(int r)
{
    int ans = 1;
    vector<int>temp;
    temp.push_back(ans);
    for (int c = 1; c < r; c++)
    {
        ans = ans * (r-c);
        ans = ans/c;
        temp.push_back(ans);
    }
    return temp;
}
vector<vector<int>>OptpascalTriangle(int n)
{
    vector<vector<int>>ans;
    for (int r = 1; r <=n; r++)
    {
        ans.push_back(generateRow(r));

    }

    return ans;
    
}

int main()
{
    int n = 4;
    int r = 2;
    // cout << binomialCoefficient(n-1,r-1);
    // BruteprintNthRow(5);
    // OptprintNthRow(5);
    vector<vector<int>> ans = BrutepascalTriangle(n);
    // vector<vector<int>> ans = OptpascalTriangle(n);

    for (auto it : ans)
    {
        for (auto el : it)
        {
            cout << el << " ";
        }
        cout << endl;
    }

    return 0;
}