class Solution {
public:
    int number(string &s, int& p) {
        string num = "";
        while (s[p] >= '0' && s[p] <= '9') {
            num += s[p];
            p++;
        }
        return stoi(num);
    }
    
    
    int expression2(string &s, int &p) {
        int n1 = number(s, p);

        while (s[p] == '/' || s[p] == '*') {
            char op = s[p];
            p++;
            int n2 = number(s, p);
            if (op == '/') n1 /= n2;
            if (op == '*') n1 *= n2;
        }
        
        return n1;
    }
    
    int expression(string &s, int& p) {
        int n1 = expression2(s, p);
        
        while (s[p] == '+' || s[p] == '-') {
            char op = s[p];
            p++;
            int n2 = expression2(s, p);
            if (op == '+') n1 += n2;
            if (op == '-') n1 -= n2;
        }
        
        return n1;
    }
    
    string trim(string &s) {
        string input = "";
        for (char c : s) {
            if (c != ' ') input += c;
        }
        return input;
    }
    int calculate(string s) {
        int p = 0;
        string input = trim(s);
        return expression(input, p);
    }
};
