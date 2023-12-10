/*binary search iterative
time - O(logn)*/
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int bSearch(int arr[],int i,int j, int target)
{
    while (i<=j)
    {
        int m = (i+j)/2;
        if (arr[m] == target)
        {
            return m;
        }
        if (arr[m] > target)
        {
            return bSearch(arr,i,m-1,target);
        }
        else
        {
            return bSearch(arr,m+1,j,target);
        }   
    }

    return -1;

}

int main()
{
    int arr[] = {43,56,67,68,76,89,90};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << bSearch(arr,0,n,56);
    
    return 0;
}