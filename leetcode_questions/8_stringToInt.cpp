class Solution
{
public:
    int myAtoi(string s)
    {
        long ans = 0;
        int n = s.length();
        int i = 0;
        int sign = 1;
        while (s[i] == ' ' && i < n)
        {
            i++;
        }
        if (s[i] == '-' && i < n)
        {
            sign = -1;
            i++;
        }
        else if (s[i] == '+' && i < n)
        {
            i++;
        }
        while (i < n)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                ans = ans * 10 + (s[i] - '0');
                if (ans > INT_MAX && sign == -1)
                    return INT_MIN;
                else if (ans > INT_MAX && sign == 1)
                    return INT_MAX;
                i++;
            }
            else
            {
                return (ans * sign);
            }
        }
        return (ans * sign);

        return ans;
    }
};