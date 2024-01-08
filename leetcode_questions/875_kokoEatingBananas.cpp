#include <bits/stdc++.h>
#include <vector>
using namespace std;

// brute force O(max(Arr)*n)
int findMax(vector<int> &piles)
{
    int maxi = INT_MIN;
    int n = piles.size();
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, piles[i]);
    }

    return maxi;
}

int calculateTime(vector<int> &piles, int hour)
{
    int totalH = 0;
    for (int i = 0; i < piles.size(); i++)
    {
        totalH += ceil((double)piles[i]/ (double) hour);
    }
    return totalH;
    
}
int minEatingSpeedBrute(vector<int> &piles, int h)
{
    int maxi = findMax(piles);

    for (int i = 1; i <= maxi; i++)
    {
        int reqTime = calculateTime(piles, i);

        if (reqTime <= h)
        {
            return i;
        }
    }
    return maxi;
}

//binary search
int minEatingSpeed(vector<int> &piles, int h)
{
    int maxi = findMax(piles);
    int l = 1;
    int h = maxi;
    while (l<=h)
    {
        /* code */
    }
    
    return maxi;
}

int main()
{
    vector<int> piles = {30,11,23,4,20};
    int h = 5;
    cout << minEatingSpeed(piles,h);

    return 0;
}