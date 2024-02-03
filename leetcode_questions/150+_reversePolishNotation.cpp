// reverse polish notation - postfix

long operate(long op1, long op2, char t)
{
    if (t == '+')
        return op2 + op1;
    else if (t == '-')
        return op2 - op1;
    else if (t == '*')
        return op2 * op1;
    return op2 / op1;
}

int solve(vector<string> &tokens)
{
    stack<long> st;
    for (int i = 0; i < tokens.size(); i++)
    {
        if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
        {
            long op1 = st.top();
            st.pop();
            long op2 = st.top();
            st.pop();
            string Operator = tokens[i];
            long res = operate(op1, op2, Operator[0]);
            st.push(res);
        }
        else
        {
            st.push(stol(tokens[i]));
        }
    }
    return st.top();
}
int evalRPN(vector<string> &tokens)
{
    return solve(tokens);
}
