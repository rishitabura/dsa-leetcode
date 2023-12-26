class Solution {
public:
    vector<int>generateRow(int r)
    {
        int ans = 1;
        vector<int> temp;
        temp.push_back(ans);
        for(int c = 1; c<r; c++)
        {
            ans = ans* (r-c);
            ans = ans/c;
            temp.push_back(ans);
        }
        return temp;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int r = 1; r<=numRows; r++)
        {
            ans.push_back(generateRow(r));
        }
        return ans;
    }
};