class Solution {
public:

    struct cmp {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;

        // Put first node of every list into heap
        for (ListNode* node : lists) {
            if (node != NULL) {
                pq.push(node);
            }
        }

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (!pq.empty()) {

            ListNode* node = pq.top();
            pq.pop();

            tail->next = node;
            tail = node;

            // Add next node from the same list
            if (node->next != NULL) {
                pq.push(node->next);
            }
        }

        return dummy.next;
    }
};