class Solution {
public:
    string intToRoman(int num) {
      string roman;
      while (num >= 1000) {
        roman += 'M';
        num -= 1000;
      }

      vector<pair <int, string> > hundred_chars;
      hundred_chars.push_back(pair<int, string>(900, "CM"));
      hundred_chars.push_back(pair<int, string>(500, "D"));
      hundred_chars.push_back(pair<int, string>(400, "CD"));
      for (auto c : hundred_chars) {
        if (num >= c.first) {
          roman += c.second;
          num -= c.first;
        }
      }

      while (num >= 100) {
        roman += 'C';
        num -= 100;
      }

      vector<pair <int, string> > ten_chars;
      ten_chars.push_back(pair<int, string>(90, "XC"));
      ten_chars.push_back(pair<int, string>(50, "L"));
      ten_chars.push_back(pair<int, string>(40, "XL"));

      for (auto c : ten_chars) {
        if (num >= c.first) {
          roman += c.second;
          num -= c.first;
        }
      }


      while (num >= 10) {
        roman += 'X';
        num -= 10;
      }

      vector<pair <int, string> > one_chars;
      one_chars.push_back(pair<int, string>(9, "IX"));
      one_chars.push_back(pair<int, string>(5, "V"));
      one_chars.push_back(pair<int, string>(4, "IV"));

      for (auto c : one_chars) {
        if (num >= c.first) {
          roman += c.second;
          num -= c.first;
        }
      }

      while (num > 0) {
        roman += 'I';
        num -= 1;
      }

      return roman;
    }
};
