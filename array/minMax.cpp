/*
goal : find the min and max element in an array
using inbuilt functions
time - O(n)
no of comparision - n
space - O(1)
*/

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int minE(int a[], int n)
{
    int minA = a[0];

    for (int i = 1; i < n; i++)
    {
        minA = min(minA, a[i]);
    }
    return minA;
}


int maxE(int a[], int n)
{
    int maxA = a[0];
    for (int i = 1; i < n; i++)
    {
        maxA = max(maxA, a[i]);
    }

    return maxA;
    
}
int main()
{
    int a[] = {45,64,23,12,67,88};
    int n = sizeof(a)/sizeof(a[0]);
    cout << "Min : " << minE(a,n) << endl; 
    cout << "Max : " << maxE(a,n); 
    return 0;
}