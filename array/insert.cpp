/*insert in sorted array
time - O(n)*/
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int insert(int arr[], int n, int k)
{
    int i;
    for (i = n-1; i >= 0 && arr[i] > k; i--)
    {
        arr[i+1] = arr[i];
    }
    arr[i+1] = k;

    return n+1;
    
}

int main()
{
    int arr[] = {1,2,4,5,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;

    cout << "Before :";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    
    n = insert(arr,n,k);
    cout << "\nAfter :";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    

    return 0;
}