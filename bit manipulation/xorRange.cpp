#include<bits/stdc++.h>
#include<vector>
using namespace std;

int xorNnums(int n)
{
    if (n%4 == 1)
    {
        return 1;
    }
    if (n%4 == 2)
    {
        return n+1;
    }
    if (n%4 == 3)
    {
        return 0;
    }
    if (n%4 == 0)
    {
        return n;
    }
        
}

int xorRange(int l, int r)
{
    return (xorNnums(l-1) ^ xorNnums(r));
}
int main()
{
    int n = 5;
    // cout << xorNnums(n);
    int l = 4;
    int r = 7;   
    cout << xorRange(l,r);

    return 0;
}