#include <bits/stdc++.h>
#include <vector>
using namespace std;

int findMax(vector<int> &weights)
{
    int maxi = INT_MIN;
    int n = weights.size();
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, weights[i]);
    }

    return maxi;
}

int findSum(vector<int> &weights)
{
    int sum = 0;
    for (int i = 0; i < weights.size(); i++)
    {
        sum = sum + weights[i];
    }
    return sum;
}

int findDay(vector<int> &weights, int capacity)
{
    int day = 1;
    int load = 0;
    for (int i = 0; i < weights.size(); i++)
    {
        if (load + weights[i] > capacity)
        {
            day = day + 1;
            load = weights[i];
        }
        else
        {
            load += weights[i];
        }
    }
    return day;
}
// time - O(n^2)
int shipWithinDaysBrute(vector<int> &weights, int days)
{
    int maxi = findMax(weights);
    int sum = findSum(weights);
    for (int c = maxi; c <= sum; c++)
    {
        int reqDays = findDay(weights, c);
        if (reqDays <= days)
        {
            return c;
        }
    }
}

// time - O(n*log n)
int shipWithinDays(vector<int> &weights, int days)
{
    int l = findMax(weights);
    int h = findSum(weights);
    int ans;
    while (l <= h)
    {
        int mid = (l+h)/2;
        int reqDays = findDay(weights, mid);

        if (reqDays <= days)
        {
            ans = mid;
            h = mid -1;
        }
        else
        {
            l = mid+1;
        }
        
    }
    return ans;
    
}

int main()
{
    vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
    int days = 5;
    cout << shipWithinDays(weights, days);

    return 0;
}