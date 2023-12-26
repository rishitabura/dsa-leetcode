/*Q1. Given row and col no, find the element at that place in pascal triangle
1. Brute force - generate triangle and then find
2. Use formula - (r-1)C(c-1) if row and col starts from 1

Q2. Print nth row element of pascan triangle
1. Brute force - use the formula method - O(n*r)
2. */
#include<bits/stdc++.h>
using namespace std;


int binomialCoefficient(int n, int r)
{
    int res = 1;
    for (int i = 0; i < r; i++)
    {
        res = res * (n-i);
        res = res/(i+1);
    }
    return res;
}

void BruteprintNthRow(int n)    //O(n*r )
{
    for (int c = 1; c <=n; c++) // O(n)
    {
        cout << binomialCoefficient(n-1,c-1)<< " "; // O(r)
    }
    
}

void OptprintNthRow(int n)
{
    int ans = 1;
    cout << ans << " ";
    for (int c = 1; c < n; c++)
    {
        ans = ans*(n-c);
        ans = ans/c;
        cout << ans << " ";
    }
    
}

int main()
{
    int n = 4;
    int r = 2;
    // cout << binomialCoefficient(n-1,r-1);
    BruteprintNthRow(5);
    cout << endl;
    OptprintNthRow(5);
    
    return 0;
}