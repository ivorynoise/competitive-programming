#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int trap(vector<int>& height) {
        int N = height.size();
        if (N == 0) {
            return 0;
        }
        stack<pair<int, int>> s;
        long long int answer = 0;
        for (int i = 0; i < N; i++) {
            int mx = 0;
            while (!s.empty() and s.top().first < height[i]) {
                mx = max(mx, s.top().first);
                s.pop();
            }
            if (!s.empty()) {
                answer += (height[i] - mx) * (i - s.top().second - 1);
            }
            s.push({height[i], i});
        }
        while (!s.empty()) {
            s.pop();
        }
        for (int i = N - 1; i >= 0; i--) {
            int mx = 0;
            while (!s.empty() and s.top().first <= height[i]) {
                mx = max(mx, s.top().first);
                s.pop();
            }
            if (!s.empty()) {
                answer += (height[i] - mx) * (s.top().second - i - 1);
            }
            s.push({height[i], i});
        }
        return answer;
    }
};

int main() {
    Solution s = Solution();
    vector<int> heights = {4, 2, 0, 3, 2, 5};
    cout << s.trap(heights) << endl;
    return 0;
}
