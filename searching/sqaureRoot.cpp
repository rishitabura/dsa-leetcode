#include<bits/stdc++.h>
#include<vector>
using namespace std;

// brute force

int sqrRoot(int n)
{
    int ans = 1;
    for (int i = 1; i < n; i++)
    {
        if(i*i <= n){
            ans = i;
        }
        else{
            break;
        }
    }
    return ans;
    
}

// binary search
int sqrRootBinary(int n)
{
    int l = 0;
    int h = n;
    while (l<=h)
    {
        int mid = (l+h)/2;
        
        if(mid*mid > n)
        {
            h = mid -1;
        }
        else if(mid*mid <= n){
            l = mid+1;
        }
    }
    
    return h;
    
}


int main()
{
    cout << sqrRootBinary(40);
    
    return 0;
}