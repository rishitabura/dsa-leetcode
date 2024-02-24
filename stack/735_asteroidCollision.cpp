    class Solution {
    public:
        vector<int> asteroidCollision(vector<int>& asteroids) {
            int n = asteroids.size();
            stack<int> st;
            for (int i = 0; i < n; i++) {
                if (st.empty() || asteroids[i] > 0) {
                    st.push(asteroids[i]);
                }
                else
                {
                    while (!st.empty() && st.top() > 0 && st.top() < abs(asteroids[i]))
                    {
                        st.pop();
                    }
                    if(st.empty() || st.top() < 0)
                    {
                        st.push(asteroids[i]);
                    }
                    else if(st.top() == abs(asteroids[i]))
                    {
                        st.pop();
                    }
                }
            }
            int size = st.size();
            vector<int> ans(size);
            while (!st.empty()) {
                ans[size - 1] = st.top();
                size--;
                st.pop();
            }
            return ans;
        }
    };