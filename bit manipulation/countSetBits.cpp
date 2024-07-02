// count the number of set bits

#include<bits/stdc++.h>
#include<vector>
using namespace std;

int countSetBits(int n)
{
    int count = 0;
    while (n>1)
    {
        // if(n%2 == 1)
        // {
        //     count++;
        // }
        // n = n/2;

        count += n & 1;
        n = n >> 1;
    }
    if (n == 1)
    {
        count++;
    }
    return count;
    
}
int main()
{
    int n = 13;
    cout << countSetBits(n);     

    return 0;
}