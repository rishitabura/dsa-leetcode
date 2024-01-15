class Solution {
public:
    int mySqrt(int x) {

        int l = 0;
        int h = x;
        while (l <= h) {
            long long mid = (l + h) / 2;

            if ((long long)mid * mid > x) {
                h = mid - 1;
            } else if ((long long)mid * mid <= x) {
                l = mid + 1;
            }
        }

        return h;
    }
    bool isPerfectSquare(int num) {
        int ans = mySqrt(num);
        if(ans*ans == num) return true;
        return false;
    }
};