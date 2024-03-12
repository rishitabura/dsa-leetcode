#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> maxContiguous(vector<int>& nums, int k) {
    vector<int> result;
    deque<int> deque;

    for (int i = 0; i < nums.size(); i++) {
            
        // Remove elements outside the window
        while (!deque.empty() && deque.front() < i - k + 1) {
            deque.pop_front();
        }

        // Remove smaller elements from the back of the deque
        while (!deque.empty() && nums[deque.back()] < nums[i]) {
            deque.pop_back();
        }

        // Add current element's index to deque
        deque.push_back(i);

        // Add maximum element in the window to result list
        if (i >= k - 1) {
            result.push_back(nums[deque.front()]);
        }
    }

    return result;
}

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> result = maxContiguous(nums, k);
    for (int num : result) {
        cout << num << " ";
    }
    // Output: 3 3 5 5 6 7
    return 0;
}