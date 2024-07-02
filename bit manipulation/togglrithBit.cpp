// toggle ith bit - 0 to 1 and 1 to 0

#include<bits/stdc++.h>
#include<vector>
using namespace std;

int toggleBit(int n, int i)
{
    return (n ^ (1<< i));
}

int main()
{
    int n = 13;
    int i = 2;
    cout << toggleBit(n,i);
    
    return 0;
}