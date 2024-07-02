#include<bits/stdc++.h>
#include<vector>
using namespace std;



int main()
{
    int a = 12;
    int b = 15;

    a = a^b;
    b = a^b;
    a = a^b;

    cout << a << " " << b;
    return 0;
}