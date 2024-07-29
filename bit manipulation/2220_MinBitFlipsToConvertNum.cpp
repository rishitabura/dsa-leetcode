class Solution {
private:
    int countSetBits(int n)
    {
        int count = 0;
        while (n>1)
        {
            count += n & 1;
            n = n >> 1;
        }
        if (n == 1)
        {
            count++;
        }
        return count;
        
    }
public:
    int minBitFlips(int start, int goal) {

        int n = (start ^ goal);
        int count = countSetBits(n);
        return count;
    }
};