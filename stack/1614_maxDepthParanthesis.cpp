/*using stack
tc- O(n)
sc - O(n)*/
class Solution {
public:
    int maxDepth(string s) {

        stack<char>st;
        int i = 0;
        int maxDepth = 0;
        while(i<s.size())
        {
            if(s[i] == '(')
            {
                st.push(s[i]);
            }
            else if(s[i] == ')')
            {
                st.pop();
            }
            i++;
            maxDepth = max(maxDepth,(int)st.size());
        }

        return maxDepth;
    }
};

/*tc- O(n)
sc - O(1)*/
class Solution {
public:
    int maxDepth(string s) {

        stack<char>st;
        int i = 0;
        int maxDepth = 0;
        int count = 0;

        while(i<s.size())
        {
            if(s[i] == '(')
            {
                count++;
                maxDepth  = max(maxDepth, count);
            }
            else if(s[i] == ')')
            {
                count--;

            }
            i++;
        }

        return maxDepth;
    }
};