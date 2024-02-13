/*recursion - time - O(n^n)*/

/*memoization - O(n*n)*/
class Solution {
public:
bool solve(vector<int>&nums, int ind, vector<int>&dp)
{
    if(dp[ind] != -1){
        return dp[ind];
    }
    if(ind == nums.size()-1){
        return true;
    }
    if(nums[ind] == 0){
        return 0;
    }

    int reach = ind + nums[ind];
    for(int i = ind+1; i<= reach; i++)
    {
        if(i < nums.size() && solve(nums, i,dp)){
            return dp[ind] = true;
        }
    }
    return dp[ind] =  false;
}
    bool canJump(vector<int>& nums) {

        vector<int>dp(nums.size()+1, -1);
        return solve(nums, 0,dp);
        
    }
};


/*greddy approch
time - O(n)*/
class Solution {
public:
    bool canJump(vector<int>& nums) {

        int reach = 0;

        for (int i = 0; i < nums.size(); i++) {

            if(reach < i)
            {
                return false;
            }
            reach = max(reach, i + nums[i]);
        }
        return true;
    }
};