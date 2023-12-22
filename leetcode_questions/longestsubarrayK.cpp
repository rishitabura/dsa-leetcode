#include<bits/stdc++.h>
#include <algorithm>
using namespace std;

int longestSubarrayWithSumK(vector<int> a, long long k) {
    int n = a.size();
    int left = 0;
    int right = 0;
    int sum = a[0];
    int maxlen = 0;
    while(right<n)
    {

        if(sum == k)
        {
            maxlen = max(maxlen,right-left+1);
            right++;
            if(right<n)
            {
                sum += a[right];
            }
        }
        else if(sum <k)
        {
            right++;
            if(right<n)
            {
                sum+=a[right];
            }
        }
        else{
            sum -= a[left];
            left++;
        }
        
    }
    return maxlen;

    

    
}

int main()
{

    vector<int> a = {1, 1, 0, 1, 1 };
    int n = 5;
    long long k = 2;
    cout<< longestSubarrayWithSumK(a, k);
    return 0;
}