class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        double avg = 0;
        int i = 0;
        for(i = 0; i<k; i++)
        {
            avg += nums[i];
        }
        double marks = avg/k;
        for(int x = i; x<nums.size(); x++)
        {
            avg -= nums[x-i];
            avg += nums[x];
            marks = max(marks, avg/k);
        }
        return marks;
        
    }
};