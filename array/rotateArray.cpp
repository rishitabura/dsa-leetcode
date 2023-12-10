#include<bits/stdc++.h>
#include<vector>
using namespace std;

void rotateArray(int arr[], int k, int n) {

    int temp[k];

    for(int i = 0; i<k; i++)
    {
        temp[i] = arr[i];
    }

    for(int i = 0; i<n-k; i++)
    {
        arr[i] = arr[i+k];
    }

    for(int i = n-k; i<n; i++)
    {
        arr[i] = temp[i-n+k];
    }
}


int main()
{
    int arr[] = {1,2,3,4,5};
    int k = 3;
    int n = sizeof(arr)/sizeof(arr[0]);

    rotateArray(arr, k, n);
    for(int i = 0; i<n ;i++)
    {
        cout << arr[i] << " ";
    }
    
    return 0;
}