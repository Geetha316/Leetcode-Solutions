class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x = 0;
        for (int n : nums)
            x ^= n;

        unsigned int bit = (unsigned int)x & -(unsigned int)x;

        int a = 0, b = 0;
        for (int n : nums) {
            if ((unsigned int)n & bit)
                a ^= n;
            else
                b ^= n;
        }

        return {a, b};
    }
};