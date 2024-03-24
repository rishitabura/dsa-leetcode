class Solution {
public:
    int maxVowels(string s, int k) {

        int l = 0, r = k;
        int count = 0;
        for(int i = 0; i<k; i++)
        {
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
            {
                count++;
            }
        }

        int maxi = count;
        while(r < s.size())
        {
            if(s[l]=='a' || s[l]=='e' || s[l]=='i' || s[l]=='o' || s[l]=='u')
            {
                count--;
            }
            l++;
            if(s[r]=='a' || s[r]=='e' || s[r]=='i' || s[r]=='o' || s[r]=='u')
            {
                count++;
            }
            r++;

            maxi = max(maxi, count);
        }
        return maxi;
    }
};