class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int count1 = 0;
        int count0 = 0;
        for(int i = 0; i< s.size(); i++)
        {
            if(s[i] == '1')
            {
                count1++;
            }
            else if(s[i] == '0')
            {
                count0++; 
            }
        }
        string ans = "";
        ans.append(count1-1, '1');
        ans.append(count0, '0');
        ans += '1';

        return ans;
        
    }
};