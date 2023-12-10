/*binary search iterative
time - O(logn)*/
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int bSearch(int arr[],int n, int target)
{
    int i = 0, j = n;
    while (i<=j)
    {
        int m = (i+j)/2;
        if (arr[m] == target)
        {
            return m;
        }
        if (arr[m] > target)
        {
            j = m-1;
        }
        else
        {
            i = m+1;
        }   
    }

    return -1;

}

int main()
{
    int arr[] = {43,56,67,68,76,89,90};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << bSearch(arr,n,56);
    
    return 0;
}