#include<bits/stdc++.h>
#include <algorithm>
using namespace std;

int longestSubarrayWithSumK(vector<int> a, long long k) {
     int n = a.size();
    int left = 0;
    int right = 0;
    int sum = a[0];
    int maxlen = 0;
    int start, end;
    while(right<n)
    {

        while(sum>k && left<=right)
        {
            sum-=a[left];
            left++;

        }
        if(sum == k)
        {
            start = left;
            end = right;
            maxlen = max(maxlen,right-left+1);
        }
        right++;
        if(right<n)
        {
            sum += a[right];
        }
    }

    for (int i = start; i <= end; i++)
    {
        cout << a[start] << " ";
    }
    cout << endl;
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