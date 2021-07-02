class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> stack;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+") {
                int one = stack.back();
                stack.pop_back();
                int two = stack.back();
                stack.pop_back();
                stack.push_back(two + one);
            } else if (tokens[i] == "-") {
                int one = stack.back();
                stack.pop_back();
                int two = stack.back();
                stack.pop_back();
                stack.push_back(two - one);
            } else if (tokens[i] == "*") {
                int one = stack.back();
                stack.pop_back();
                int two = stack.back();
                stack.pop_back();
                stack.push_back(two * one);
            } else if (tokens[i] == "/") {
                int one = stack.back();
                stack.pop_back();
                int two = stack.back();
                stack.pop_back();
                stack.push_back(two / one);
            } else {
                int n = std::stoi(tokens[i]);
                stack.push_back(n);
            }
        }
        
        return stack[0];
    }
};
