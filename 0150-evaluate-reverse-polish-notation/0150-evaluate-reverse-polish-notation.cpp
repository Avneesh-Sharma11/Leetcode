class Solution {
public:
    int operation(int a, int b, string s) {
        char op = s[0];

        if (op == '+')
            return a + b;
        else if (op == '-')
            return a - b;
        else if (op == '*')
            return a * b;
        else if (op == '/') {
            if (b == 0)
                return -1;
            return a / b;
        }

        return 0;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (int i = 0; i < tokens.size(); i++) {
            string s = tokens[i];
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                int op2 = st.top();
                st.pop();
                int op1 = st.top();
                st.pop();
                st.push(operation(op1, op2, s));
            } else {
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};