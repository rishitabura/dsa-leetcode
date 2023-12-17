#include<bits/stdc++.h>
#include<vector>
using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int a = 0;
    int x = 0;
    int k = 0;
    int size = nums1.size() - n;

    vector<int> res(m + n);

    while (a<size && x < n)
    {
        if (nums1[a] <= nums2[x])
        {
            res[k] = nums1[a];
            k++;
            a++;
        }
        if (nums1[a] > nums2[x])
        {
            res[k] = nums2[x];
            k++;
            x++;
        }
    }
    while (a < m)
    {
        res[k] = nums1[a];
        k++;
        a++;
    }
    while (x < n)
    {
        res[k] = nums2[x];
        k++;
        x++;
    }
    for (int i = 0; i < m + n; i++)
    {
        nums1[i] = res[i];
    }
}


int main()
{
    vector<int> nums1 ={-1,0,0,3,3,3,0,0,0};
    int m = 6;
    vector<int> nums2= {1,2,2};
    int n = 3;
    merge(nums1,m,nums2,n);

    for (int i = 0; i < nums1.size(); i++)
    {
        cout << nums1[i] << " ";
    }
    
    
    return 0;
}
