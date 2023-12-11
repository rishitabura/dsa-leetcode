#include <bits/stdc++.h>
#include <vector>
using namespace std;

int missingNumber(int &nums[])
{
    int n = sizeof(nums)/sizeof(nums[0]);
    cout << n;
    // int s1 = n(n + 1) / 2;
    // int s2 = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     s2 = s2 + nums[i];
    // }
    // return s1 - s2;
}

int main()
{
    int nums[] = {0,2,1};
    cout << missingNumber(nums);

    return 0;
}