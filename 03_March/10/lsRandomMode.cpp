/*
----------------------------------------------------------------
Question -> 382. Linked List Random Node
link -> https://leetcode.com/problems/linked-list-random-node/
 Time:
      Solution: O(1)
      getRandom: O(N)
 Space: O(1)
-----------------------------------------------------------------
*/

class Solution {
    ListNode *head;
public:
    Solution(ListNode* head) : head(head) {}
    int getRandom() {
        int base = 1;
        auto p = head, ans = head;
        while (p) {
            int r = rand() % base;
            if (r == 0) ans = p;
            base++;
            p = p->next;
        }
        return ans->val;
    }
};
