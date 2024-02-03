/*brute force
time - O(n^2)
space - O(1)*/
vector<int> dailyTemperatures(vector<int> &temperatures)
{
    int n = temperatures.size();
    vector<int> answer(n, -1);

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (temperatures[j] > temperatures[i])
            {
                answer[i] = j - i;
                break;
            }
        }
        if (answer[i] == -1)
        {
            answer[i] = 0;
        }
    }
    return answer;
}

/*using monotonic stack
time - O(n*2) coz for each else there is push and pop
space - O(n)*/
vector<int> dailyTemperatures(vector<int>& temperatures) {

        int n = temperatures.size();
        vector<int> answer(n, -1);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && temperatures[st.top()] <= temperatures[i]) {
                st.pop();
            }

            if (st.empty()) {
                answer[i] = 0;
                st.push(i);
            } else {
                answer[i] = st.top() - i;
                st.push(i);
            }
        }
        return answer;
    }