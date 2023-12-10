/*
linear search
time - O(n^2)*/
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int search(int arr[], int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        if(arr[i] == target )
        {
            return i;
        }
    }
    
    return -1;
}
int main()
{
    int arr[] = {35,342,13,57,45};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << search(arr,n,35);
    return 0;
}