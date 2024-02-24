class Solution {
public:
    string mergeAlternately(string word1, string word2) {

        int n = word1.size();
        int m = word2.size();
        int t = n + m;
        vector<char>s (t);
       
        string ans = "";
        int i = 0, j = 0;
        int k = 0;
        while(i < n && j < m)
        {   
            s[k++] = word1[i++];
            s[k++] = word2[j++];  
        }
        while(i < n)
        {
            s[k++] = word1[i++];
        }
         while(j < m)
        {
            s[k++] = word2[j++];
        }
        for(int z = 0; z < t; z++)
        {
            ans += s[z];
        }
        return ans;
        
    }
};