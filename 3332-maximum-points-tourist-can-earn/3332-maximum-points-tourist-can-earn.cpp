class Solution {
public:
    int maxScore(int n, int k, vector<vector<int>>& stayScore,
                 vector<vector<int>>& travelScore) {
        
        vector<int> dp(n, 0);

        for (int day = 0; day < k; day++) {
            vector<int> next(n, 0);

            for (int curr = 0; curr < n; curr++) {
                // Stay in the same city
                next[curr] = max(next[curr],
                                 dp[curr] + stayScore[day][curr]);

                // Travel to another city
                for (int dest = 0; dest < n; dest++) {
                    if (curr != dest) {
                        next[dest] = max(next[dest],
                                         dp[curr] + travelScore[curr][dest]);
                    }
                }
            }

            dp = next;
        }

        return *max_element(dp.begin(), dp.end());
    }
};