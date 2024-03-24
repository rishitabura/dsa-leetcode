//Apply Operations to Make Sum of Array Greater Than or Equal to k


class Solution {
public:
    int minOperations(int k) {
        int ans = std::numeric_limits<int>::max();
        int x = 1;
        int ops = 0;
        while (true) {
            int temp = ops;
            temp += k / x;
            if (k % x != 0) {
                temp += 1;
            }
            if (temp > ans) {
                break;
            }
            ans = std::min(ans, temp);
            x++;
            ops++;
        }
        return ans - 1;
    
}

};