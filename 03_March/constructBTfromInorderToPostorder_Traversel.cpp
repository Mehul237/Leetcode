/*
 Time: O(N)
 Space: O(N)
*/


 class Solution {
 public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> m;
      
        for (int i = 0; i < inorder.size(); ++i) m[inorder[i]] = i;
      
        function<TreeNode*(int, int, int, int)> build = [&](int is, int ie, int ps, int pe) -> TreeNode* {
          
            if (is == ie) return NULL;
            auto n = new TreeNode(postorder[pe - 1]);
            int mid = m[n->val];
            n->left = build(is, mid, ps, ps + mid - is);
            n->right = build(mid + 1, ie, ps + mid - is, pe - 1);
          
            return n;
        };
        return build(0, inorder.size(), 0, postorder.size());
    }
 };
