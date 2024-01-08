#include <bits/stdc++.h>
#include <vector>
using namespace std;

int findMin(vector<int> &bloomDay)
{
    int mini = INT_MAX;
    int n = bloomDay.size();
    for (int i = 0; i < n; i++)
    {
        mini = min(mini, bloomDay[i]);
    }

    return mini;
}

int findMax(vector<int> &bloomDay)
{
    int maxi = INT_MIN;
    int n = bloomDay.size();
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, bloomDay[i]);
    }

    return maxi;
}

bool possible(vector<int> &bloomDay, int day, int m, int k)
{
    int count = 0;
    int noOfBloomDay = 0;

    for (int i = 0; i < bloomDay.size(); i++)
    {
        if (bloomDay[i] <= day)
        {
            count++;
        }
        else
        {
            noOfBloomDay += (count / k);
            count = 0;
        }
    }

    noOfBloomDay += (count / k);

    if (noOfBloomDay >= m)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int minDaysBrute(vector<int> &bloomDay, int m, int k)
{
    long long val = m * 1ll * k * 1ll;
    int n = bloomDay.size();
    if (val > n)
        return -1;
    int l = findMin(bloomDay);
    int h = findMax(bloomDay);

    for (int i = l; i <= h; i++)
    {
        if (possible(bloomDay, i, m, k))
        {
            return i;
        }
    }

    return -1;
}

int minDays(vector<int> &bloomDay, int m, int k)
{
    long long val = m * 1ll * k * 1ll;
    int n = bloomDay.size();
    if (val > n)
        return -1;

    int l = findMin(bloomDay);
    int h = findMax(bloomDay);
    int ans;

    while (l <= h)
    {
        int mid = (l + h) / 2;
        if (possible(bloomDay, mid, m, k))
        {
            ans = mid;
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    return ans;
}

int main()
{
    vector<int> bloomDay = {1, 10, 3, 10, 2};
    int m = 3;
    int k = 1;
    cout << minDays(bloomDay, m, k);

    return 0;
}