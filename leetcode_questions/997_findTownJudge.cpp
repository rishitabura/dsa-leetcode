// using map
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {

        unordered_map<int, int> mp;
        for(auto it: trust)
        {
            mp[it[0]]--;
            mp[it[1]]++;
        }

        for(int i = 1; i<=n ; i++)
        {
            if(mp[i] == n-1 )
            {
                return i;
            }
        }
        return -1;
        
    }
};


// using arr
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {

        // unordered_map<int, int> mp;
        // for(auto it: trust)
        // {
        //     mp[it[0]]--;
        //     mp[it[1]]++;
        // }

        // for(int i = 1; i<=n ; i++)
        // {
        //     if(mp[i] == n-1 )
        //     {
        //         return i;
        //     }
        // }

        vector<int>arr(n+1, 0);
        for(auto it : trust)
        {
            arr[it[0]]--;
            arr[it[1]]++;
        }
        for(int i = 1; i<=n ; i++)
        {
            if(arr[i] == n-1 )
            {
                return i;
            }
        }
        return -1;
        
    }
};