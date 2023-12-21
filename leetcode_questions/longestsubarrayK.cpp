#include<bits/stdc++.h>
#include <algorithm>
using namespace std;

int longestSubarrayWithSumK(vector<int> a, long long k) {
    long long sum = 0;
    int len = -1;
    int maxlen = -1;
    int start , ansstart,ansend;
    for (int i = 0; i < a.size(); i++)
    {
        if(sum == 0)
        {
            start = i;
        }
        if(sum==k)
        {
             if (len > maxlen) {
                maxlen = len;
                start = i - len;
                end = i - 1;
            }
            sum = 0;
            len = 0;
        }
        
        if (sum < k)
        {
            sum += a[i];
            len++;
            
        }
        if(sum>k)
        {
            sum = 0;
            len = 0;
            
        }   
         if(a[i]==k)
        {
            maxlen=1;
            ansstart = i;
            ansend = i;
        }    
    }
    
     for (int i = ansstart; i <= ansend; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    
    return maxlen;
}

int main()
{

    vector<int> a = {1,2,3,1,1,1,1};
    int n = 7;
    long long k = 3;
    cout<< longestSubarrayWithSumK(a, k);
    return 0;
}