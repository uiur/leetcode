#include<vector>
#include<string>
#include<map>
#include<unordered_map>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<set>
using namespace std;

// Runtime: 12 ms, faster than 98.35% of C++ online submissions for Merge Intervals.
// Memory Usage: 14.1 MB, less than 82.34% of C++ online submissions for Merge Intervals.

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
      sort(intervals.begin(), intervals.end(), [](const vector<int> &left, const vector<int> &right) {
        return left[0] < right[0];
      });

      vector<vector<int>> result;
      for (int i = 0; i < intervals.size(); i++) {
        int j = 0;
        for (j = 0; j < result.size(); j++) {
          if (intervals[i][0] <= result[j][1]) {
            result[j][1] = max(result[j][1], intervals[i][1]);
            break;
          }
        }

        if (j == result.size()) {
          result.push_back(intervals[i]);
        }
      }

      return result;
    }
};

int main(){}
