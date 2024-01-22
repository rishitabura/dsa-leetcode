#include<bits/stdc++.h>
#include<vector>
using namespace std;

int fibonacci(int n)
{
    if (n<=1)
    {
        return n;
    }

    return fibonacci(n-1) + fibonacci(n-2);
    
}

int main()
{
    int n = 3;
    cout << fibonacci(n);
    return 0;
}