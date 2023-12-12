/*
goal : to sort the array using quicksort
using divide and conquer
best case time - O(nlogn)
worst case time - O(n^2)
space - O(1)
*/

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int c = 0;
int parition(int arr[], int l, int h, int n)
{
    int i = l;
    int j = h;
    int p = arr[l];

    while (i<j)
    {
        do
        {
            i++;
        } while (arr[i] <= p);
        do
        {
            j--;
        } while (arr[j] > p);
        if (i<j)
        {
            cout << "\nswap values " << arr[i] << " and " << arr[j] << endl;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            
            c++;
        }
    }

    cout << "\nswap values " << arr[l] << " and " << arr[j] << endl;
    int temp = arr[l];
    arr[l] = arr[j];
    arr[j] = temp;
    c++;
    cout << "\nAfter partition : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    
    return j;
}

void quickSort(int arr[], int l , int h, int n)
{
    if (l<h)
    {
        int j = parition(arr,l,h, n);
        quickSort(arr,l,j, n);
        quickSort(arr,j+1, h, n);
    }
    
}
int main()
{
    int arr[] = {10,16,8,12,15,6,3,9,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "\nUnsorted array : " ;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // int c = 0;
    quickSort(arr,0,n, n);
    cout << "\nSorted array : " ;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\nTotal number of swaps : " << c;
    
    return 0;
}