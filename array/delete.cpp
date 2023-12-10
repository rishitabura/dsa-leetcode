/*delete in sorted array
time - O(n)*/
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


int deleteEle(int arr[], int n, int k)
{
    int pos = bSearch(arr,0,n-1,k);

    if (pos == -1)
    {
        cout << "Element not found";
        return n;    
    }

    

    for (int i = pos; i < n-1; i++)
    {
        arr[i] = arr[i+1];
    }
    return n-1;
    
}

int main()
{
    int arr[] = {1,2,3,4,5,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;

    cout << "Before :";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    
    n = deleteEle(arr,n,k);
    cout << "\nAfter :";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    
    
    return 0;
}