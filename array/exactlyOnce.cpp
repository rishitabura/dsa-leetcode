#include<bits/stdc++.h>
#include<iostream>
using namespace std;

/*using xor 
time - O(n)*/
int XOR(int arr[], int n)
{
    int xo = 0;
    for (int i = 0; i < n; i++)
    {
        xo = xo^arr[i];
    }
    return xo;
    
}

/*Using linear search
if sorted array - O(n)
if not sorted - O(n logn)*/
int search(int arr[], int n)
{
    int ans ;
    sort(arr,arr+n);
    for (int i = 0; i < n; i+=2)
    {
        if (arr[i] != arr[i+1])
        {
            ans = arr[i];
        }
        
    }
    return ans;
    
}

int main()
{
    int arr[] = {3,4,5,3,1,4};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << search(arr,n);
    return 0;
}