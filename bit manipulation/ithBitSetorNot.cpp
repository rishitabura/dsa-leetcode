// check if ith bit is set or not

#include<bits/stdc++.h>
#include<vector>
using namespace std;

bool check(int n, int i)
{
    // using left shift
    if(( n & (1<<i)) == 1)
    {
        return true;
    }
    return false;

    // using right shift
    if( ((n>>i) & 1 ) == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int n = 13;
    int  i =2;
    cout << check(n,i);
    
    return 0;
}