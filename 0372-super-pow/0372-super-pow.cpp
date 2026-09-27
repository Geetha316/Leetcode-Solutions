class Solution {
public:
    int superPow(int a, vector<int>& b) {
        int result = 1;
        a %= 1337;

        for (int digit : b) {
            result = powmod(result, 10);
            result = (result * powmod(a, digit)) % 1337;
        }

        return result;
    }

    int powmod(int a, int b) {
        int result = 1;

        while (b > 0) {
            if (b % 2 == 1)
                result = (result * a) % 1337;

            a = (a * a) % 1337;
            b /= 2;
        }

        return result;
    }
};