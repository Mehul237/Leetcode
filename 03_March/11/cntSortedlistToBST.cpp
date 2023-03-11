/*
----------------------------------------------------------------------------------
Q -> 109. Convert Sorted List to Binary Search Tree
Link -> https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/

Time: O(N)
Space: O(logN)
----------------------------------------------------------------------------------
*/
class Solution {
    ListNode *head;
    int getLength(ListNode *head) {
        int ans = 0;
        for (; head; head = head->next, ++ans);
        return ans;
    }
    TreeNode *dfs(int begin, int end) {
        if (begin == end) return NULL;
        int mid = (begin + end) / 2;
        auto left = dfs(begin, mid);
        auto root = new TreeNode(head->val);
        head = head->next;
        root->left = left;
        root->right = dfs(mid + 1, end);
        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        this->head = head;
        return dfs(0, getLength(head));
    }
};
