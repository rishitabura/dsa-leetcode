#include<bits/stdc++.h>
using namespace std;

void heapifyI(int arr[], int n , int i)
{
    int parent = (i-1)/2;
    if (parent>=0)
    {
        if (arr[i] > arr[parent])
        {
            swap(arr[i], arr[parent]);
            heapifyI(arr,n,parent);
        }
        
        
    }
    
}

//O(logn)
void insertNode(int arr[], int &n, int k)
{
    n  = n+1;
    arr[n-1] = k;
    heapifyI(arr,n,n-1);
}


void heapifyD(int arr[], int n, int i)
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

        heapifyD(arr,n,largest);
    }
}


// O(log n)
void deleteNode(int arr[],int n)
{
    int last = arr[n-1];
    arr[0] = last;
    
    n = n-1;
    heapifyD(arr,n,0);
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
    
    insertNode(arr,n,7);
    printArray(arr,n);

    deleteNode(arr,n);

    printArray(arr,n);
    
    return 0;
}