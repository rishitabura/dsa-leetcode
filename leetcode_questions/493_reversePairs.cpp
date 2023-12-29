/*Optimal 
time - O(2n log n)*/
#include <bits/stdc++.h>
#include <vector>
using namespace std;

void merge(vector<int> &nums, int mid, int l, int h)
{
    int i = l;
    int j = mid + 1;
    vector<int> temp;

    while (i <= mid && j <= h)
    {
        if (nums[i] <= nums[j])
        {
            temp.push_back(nums[i]);
            i++;
        }
        if (nums[i] > nums[j])
        {
            temp.push_back(nums[j]);

            j++;
        }
    }
    while (i <= mid)
    {
        temp.push_back(nums[i]);

        i++;
    }
    while (j <= h)
    {
        temp.push_back(nums[j]);

        j++;
    }

    for (int z = l; z <= h; z++)
    {
        nums[z] = temp[z - l];
    }
}

int countReversePairs(vector<int> &nums, int l, int mid, int h)
{
    int count = 0;
    int right = mid + 1;
    for (int i = l; i <= mid; i++)
    {
        while (right <= h && nums[i] > 2 * nums[right])
        {
            right++;
        }
        count += (right - (mid + 1));
    }
    return count;
}
int mergeSort(vector<int> &nums, int l, int h)
{
    int count = 0;
    if (l < h)
    {
        int mid = l + (h - l) / 2;
        count += mergeSort(nums, l, mid);
        count += mergeSort(nums, mid + 1, h);
        count += countReversePairs(nums, l, mid, h);
        merge(nums, mid, l, h);
    }
    return count;
}

int reversePairs(vector<int> &nums)
{
    int n = nums.size();
    return mergeSort(nums, 0, n - 1);
}


int main()
{
    vector<int> nums = {1,3,2,3,1};
    int n = nums.size();

    cout << reversePairs(nums);

    return 0;
}
