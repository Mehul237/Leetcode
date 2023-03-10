
/*

Question -> 142. Linked List Cycle II
Link -> https://leetcode.com/problems/linked-list-cycle-ii/
Time: O(N)
Space: O(1)

*/

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head) return nullptr;
        auto p = head, q = head;
        while (p && p->next) {
            p = p->next->next;
            q = q->next;
            if (p == q) break;
        }
        if (!p || !p->next) return nullptr; // The list is finite
        p = head;
        for (; p != q; p = p->next, q = q->next);
        return p;
    }
};
