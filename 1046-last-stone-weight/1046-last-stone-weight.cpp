class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());

        while (pq.size() > 1) {
            int x = pq.top();
            pq.pop();

            int y = pq.top();
            pq.pop();

            if (x != y)
                pq.push(x - y);
        }

        if (pq.empty())
            return 0;

        return pq.top();
    }
};
/*1. priority_queue stores stones in descending order, so the heaviest stone comes first.
2. Remove the two heaviest stones.
3. If their weights differ, insert their difference back into the heap.
4. Repeat until at most one stone remains.
5. Return the remaining stone's weight, or 0 if none remain.
Time Complexity: \(O(n \log n)\)
Space Complexity: \(O(n)\)*/