class Solution {
public:
    string largestOddNumber(string num) {
        string largest;
        int len = num.length();
        for(int i = len-1; i>=0 ; i--)
        {
            if((num[i] - '0')  % 2 != 0)
            {
                return num.substr(0,i+1);
            }
        }
        return largest;
    }
};