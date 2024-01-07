#include <bits/stdc++.h>
#include <vector>
using namespace std;

// brute force O(n) O(logn)
int func(int i, int n)
{
    return pow(i, n);
}

int nthRoot(int n, int m)
{
    for (int i = 1; i < m; i++)
    {
        if (func(i, n) == m)
        {
            return i;
        }
        else if (func(i, n) > m)
        {
            break;
        }
    }
    return -1;
}

int nthRootBinary(int n, int m)
{
    int l = 1;
    int h = m;
    while (l <= h)
    {
        int mid = (l + h) / 2;
        if (pow(mid, n) == m)
        {
            return mid;
        }
        else if (pow(mid, n) < m)
        {
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
    }
    return -1;
}

int main()
{
    cout << nthRoot(3, 27);

    return 0;
}