class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        // If 1 already exists
        int ones = 0;
        for (int x : nums) {
            if (x == 1) ones++;
        }

        if (ones > 0)
            return n - ones;

        // Find the shortest subarray whose gcd is 1
        int minLen = n + 1;

        for (int i = 0; i < n; i++) {
            int g = 0;

            for (int j = i; j < n; j++) {
                g = gcd(g, nums[j]);

                if (g == 1) {
                    minLen = min(minLen, j - i + 1);
                    break;
                }
            }
        }

        if (minLen == n + 1)
            return -1;

        // minLen - 1 operations to create one 1
        // n - 1 more operations to spread it to all elements
        return (minLen - 1) + (n - 1);
    }
};