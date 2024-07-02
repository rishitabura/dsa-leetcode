// remove last set bit(rightmost)

#include<bits/stdc++.h>
#include<vector>
using namespace std;

int removeLastsetBit(int n)
{
    return (n & (n-1));
}
int main()
{
    int n = 12;
    cout << removeLastsetBit(n);
    return 0;
}