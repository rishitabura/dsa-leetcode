#include<bits/stdc++.h>
#include<vector>
#include<unordered_set>
using namespace std;

bool linerSearch(vector<int>nums, int x)
{
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == x)
        {
            return true;
        }
    }
    return false;
    
}
/*
brute force 
time - O(n^2)
space - O(1)*/
int BRUTElongestConsecutive(vector<int>& nums) {
    int n = nums.size();
    int len = 1;
    for (int i = 0; i < n; i++)
    {
        int x = nums[i];
        int count = 1;

        for (int j = 0; j < n; j++)
        {
            while (linerSearch(nums,x+1) ==  true)
            {
                x = x+1;
                count++;
            }
            len = max(len,count);
            
        }
        
    }
    return len;
}


/*Sorting
time - O(nlogn)
space - O(1)*/
int SORTINGlongestConsecutive(vector<int>& nums) {
    int n = nums.size();
    int len = 1;
    int lastSmallest = INT_MIN;
    int count = 0;
    sort(nums.begin(),nums.end());
    for (int i = 0; i < n; i++)
    {
        if(nums[i]-1== lastSmallest)
        {
            count++;
            lastSmallest = nums[i];
        }
        else if (nums[i]!=lastSmallest)
        {
            count = 1;
            lastSmallest = nums[i];
        }
        len = max(len,count);
    }
    return len;
}


/*using set */

int SETlongestConsecutive(vector<int>& nums) {

    int n = nums.size();
    unordered_set<int> s;
    int len = 1;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        s.insert(nums[i]);
    }
    int x = 0;
    for(auto a: s)
    {
        if(s.find(a-1) == s.end())
        {   
            count=1;
            x = a;
            while (s.find(x+1) != s.end())
            {
                count++;
                x = x+1;
            }
            
        }
        len = max(len,count);

    }
    return len;
}

int main()
{
    vector<int>nums = {100,4,200,1,2,3,201};
    cout << SETlongestConsecutive(nums);

    return 0;
}