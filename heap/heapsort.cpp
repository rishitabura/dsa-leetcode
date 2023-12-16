#include<bits/stdc++.h>
using namespace std;

void heapify (int arr[], int n, int i)
{
    int largest = i;
    int l = 2*i+1;
    int r = 2*i+2;

    if (arr[largest] < arr[l] && l<n)
    {
        largest = l;
    }
    if (arr[largest] < arr[r] && r<n)
    {
        largest = r;
    }
    if (largest!=i)
    {
        swap(arr[i], arr[largest]);

        heapify(arr,n,largest);
    }
}

void heapsort(int arr[], int n)
{
    for (int i = (n/2)-1; i >= 0; i--)
    {
        heapify(arr,n,i);
    }

    for (int i = n-1; i >0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr,n,0);
    }
    
    
}

void printArray(int arr[], int n)
{
     for (int i = 0; i < n; ++i)
    {    
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = { 10, 5, 3, 2, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);

    heapsort(arr,n);
    printArray(arr,n);

    
    return 0;
}