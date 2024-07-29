class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        if(strs.empty()) return "";

        string prefix = "";

        for(int i = 0; i< strs[0].length(); i++)
        {
            // 1st string traversing
            char ch = strs[0][i];
            bool match = true;

            for(int j = 1; j<strs.size(); j++)
            {
                if(ch != strs[j][i])
                {
                    match = false;
                    break;
                }
            }

            if(match == false)
            {
                break;
            }
            else
            {
                prefix.push_back(ch);
            }
        }


        return prefix;

        
    }
};