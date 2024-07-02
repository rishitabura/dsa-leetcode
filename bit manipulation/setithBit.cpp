// set ith bit

#include<bits/stdc++.h>
#include<vector>
using namespace std;

int setBit(int n, int i)
{
    return (n | (1 << i));
}

int main()
{
    int n = 9;
    int i = 2;
    cout << setBit(n,i);
    
    return 0;
}