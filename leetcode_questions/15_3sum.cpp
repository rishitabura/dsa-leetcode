/*unique triplets whose sum is 0
1. brute force - 
time - O(n^3)*log(no of unique triplets)
space - O(2* no of triplets)

2. better
time - O(n^2)*log(m)
space - O(n)+O(no of triplets)

3. optimal
time - O(nlogn) + O(n^2)
space - O(no of unique) - approx constant
*/


#include <bits/stdc++.h>
#include<vector>
using namespace std;

// brute force
// vector<vector<int>> threeSum(vector<int> &nums)
// {
//     set<vector<int>> st;
    
//     int n  = nums.size();
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i+1; j < n; j++)
//         {
//             for (int k = j+1; k < n; k++)
//             {
//                 if (nums[i]+nums[j]+nums[k] == 0)
//                 {
//                     vector<int>temp = {nums[i],nums[j],nums[k]};
//                     sort(temp.begin(),temp.end());
//                     st.insert(temp);
//                 }
                
//             }
            
//         }
        
//     }
//     vector<vector<int>> ans (st.begin(), st.end());
//     return ans;
// }

//better
// vector<vector<int>> threeSum(vector<int> &nums)
// {
//     set<vector<int>> st;
    
//     int n  = nums.size();
//     for (int i = 0; i < n; i++)
//     {
//         set<int> hashSet;
//         for (int j = i+1; j < n; j++)
//         {
//             int thirdEl = -(nums[i]+nums[j]);
//             if(hashSet.find(thirdEl)!=hashSet.end())
//             {
//                 vector<int> temp = {nums[i],nums[j], thirdEl};
//                 sort(temp.begin(),temp.end());
//                 st.insert(temp);
//             }
//             hashSet.insert(nums[j]);
//         }
        
//     }
//     vector<vector<int>> ans (st.begin(), st.end());
//     return ans;
// }

//optimal
vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    int n  = nums.size();

    if(n<3) return ans;

    for (int i = 0; i < n; i++)
    {
        if(i!=0 && nums[i] == nums[i-1]){
            continue;
        }
        int j = i+1;
        int k = n-1;
        while (j<k)
        {
            int sum = nums[i]+nums[j]+nums[k];
            if (sum <0)
            {
                j++;
            }
            else if(sum>0)
            {
                k--;
            }
            else
            {
                vector<int> temp = {nums[i], nums[j], nums[k]};
                ans.push_back(temp);
                j++;
                k--;
                while(j<k && nums[j] == nums[j-1]) j++;
                while(j<k && nums[k] == nums[k+1]) k--;
            }
            
            
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {-1,0,1,2,-1,-4};

    vector<vector<int>> ans = threeSum(nums);
    for (auto it : ans) {
        cout << "[";
        for (auto i : it) {
            cout << i << " ";
        }
        cout << "] ";
    }
    cout << "\n";
 

    return 0;
}