#include<bits/stdc++.h>

int findKRotation(vector<int> &arr){
    int n = arr.size();
    int l = 0;
    int h= n-1;
    int ans = INT_MAX;
    int index = -1;
    while(l<=h)
    {
        int mid = (l+h)/2;
        
        if(arr[l]<=arr[h])
        {
            if(arr[l] < ans)
            {
                index = l;
                ans = arr[l];
            }
            break;
        }
        if(arr[l] <= arr[mid])
        {
            if(arr[l] < ans)
            {
                index = l;
                ans = arr[l];
            }
            l = mid+1;
        }
        else
        {
            h = mid-1;

            if(arr[mid] < ans)
            {
                index = mid;
                ans = arr[mid];
            }
        }
    }

    return index;   
}