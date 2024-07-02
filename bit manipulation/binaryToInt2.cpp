#include<bits/stdc++.h>
using namespace std;

int fun(int n)
{
    int base = 1;
    int temp = n;
    int ans = 0;

    while (temp)
    {
        int last = temp % 10;
        temp = temp/10;

        ans += last * base;

        base = base * 2;
    }
    return ans;
    
}
int main()
{
    int num = 1001;
    cout << fun(num);
    
    return 0;
}