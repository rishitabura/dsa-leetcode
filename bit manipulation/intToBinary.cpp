#include<bits/stdc++.h>
#include<vector>
using namespace std;

string intToBinary(int n)
{
    string res = "";
    while (n >=1)
    {
        if (n%2 == 1)
        {
            res += '1';
        }
        else
        {
            res += '0';
        }
        n = n /2;
    }
    reverse(res.begin(), res.end());
    return res;
    
}
int main()
{
    int n  = 13;
    cout << intToBinary(n);
    return 0;
}