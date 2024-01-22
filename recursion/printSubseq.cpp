#include<bits/stdc++.h>
#include<vector>
using namespace std;

void printSubseq(int ind, vector<int>&ans, vector<int>&nums)
{
    int n = nums.size();
    
    if (ind >= n )
    {
        if (ans.size() == 0)
        {
            cout << "Null";
        }
        
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i]  << " ";
        }
        cout << endl;
        return;
    }

    ans.push_back(nums[ind]);
    printSubseq(ind+1,ans,nums);
    ans.pop_back();
    printSubseq(ind+1,ans,nums);
    
}

int main()
{
    vector<int>nums = {3,1,2};
    vector<int>ans;
    printSubseq(0,ans,nums);
    return 0;
}