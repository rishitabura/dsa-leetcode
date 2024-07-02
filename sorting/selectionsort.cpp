#include<bits/stdc++.h>
#include<vector>
using namespace std;

int main()
{
    int arr[] = {45,3,13,56,67,32};
    int n = sizeof(arr)/ sizeof(arr[0]);

    int mini;
    for (int i = 0; i < n; i++)
    {
        mini = i;
        for (int j = i+1; j < n; j++)
        {
            if(arr[mini] > arr[j])
            {
                mini = j;
            }
        }
        if (mini != i)
        {
            swap(arr[mini], arr[i]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    
    
    return 0;
}