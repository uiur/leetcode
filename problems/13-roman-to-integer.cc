class Solution {
public:
    map<char, int> table = {
      {'I', 1},
      {'V', 5},
      {'X', 10},
      {'L', 50},
      {'C', 100},
      {'D', 500},
      {'M', 1000}
    };

    int romanToInt(string s) {
      int result = 0;
      s += ' ';

      int i = 0;
      while (i < s.size()) {
        if (
          (s[i] == 'C' && (s[i+1] == 'D' || s[i+1] == 'M')) ||
          (s[i] == 'X' && (s[i+1] == 'L' || s[i+1] == 'C')) ||
          (s[i] == 'I' && (s[i+1] == 'V' || s[i+1] == 'X'))
        ) {
            result += romanCharToInt(s[i+1]) - romanCharToInt(s[i]);
            i += 2;
            continue;
        }


        result += romanCharToInt(s[i]);
        i++;
      }

      return result;
    }

    int romanCharToInt(char c) {
      return table[c];
    }
};
