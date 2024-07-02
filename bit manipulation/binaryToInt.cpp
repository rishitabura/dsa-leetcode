#include<bits/stdc++.h>
#include<vector>
using namespace std;

int binaryToInt(string x)
{
    int len = x.size();
    int p2 = 1;
    int num = 0;
    for (int i = len-1; i>=0 ; i--)
    {
        if (x[i] == '1')
        {
            num  = num + p2;
        }
        p2 = p2 * 2;
        cout << num << " " << p2 << endl;
    }
    return num;
    
}
int main()
{
    string x = "1001";
    cout << binaryToInt(x);
    return 0;
}