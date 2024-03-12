// topic array, pointers
/*usnig brute force
tc - O(n) + O(nlongn)
sc - O(n)*/
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

        int n = nums.size();
        vector<int>ans(n);

        for(int i = 0; i<n; i++)
        {
            ans[i] = nums[i]*nums[i];
        }
        sort(ans.begin(), ans.end());

        return ans;
        
    }
};

/*using pointers
tc - O(n)
sc- O(n)*/
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

        int n = nums.size();
        vector<int>ans(n);

        int i = 0;
        int j = n-1;
        int k = n-1;
        while(i<=j)
        {
            int a = nums[i]*nums[i];
            int b = nums[j]*nums[j];

            if(a>b)
            {
                ans[k] = a;
                i++;
            }
            else
            {
                ans[k] = b;
                j--;
            }
            k--;
        }
        return ans;
        
    }
};