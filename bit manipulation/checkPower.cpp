// check if number is power of 2 or not

#include<bits/stdc++.h>
#include<vector>
using namespace std;

bool checkPower(int n)
{
    return ((n & (n-1)) == 0);
}

int main()
{
    int n = 4;
    cout << checkPower(n);
    return 0;
}