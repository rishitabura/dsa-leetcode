#include<bits/stdc++.h>
#include<vector>
#include <algorithm>
using namespace std;

int longestSubarrayWithSumK(vector<int> a, long long k) {
    long long sum = 0;
    int len = 0;
    int maxlen = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if(sum==k)
        {
            maxlen = max(maxlen,len);
            cout << maxlen << endl;
            sum = 0;
            len=0;
        }
        
        if (sum < k)
        {
            sum += a[i];
            len ++;
        }
        if(sum > k)
        {
            sum = 0;
            len = 0;
            
        }       
        if(a[i]==k)
        {
            maxlen=1;
        }
    }
    
    return maxlen;
}

int main()
{
    vector<int> nums = {1, 2, 1,3};
    long long k = 2;
    cout << longestSubarrayWithSumK(nums,k);

    return 0;

}