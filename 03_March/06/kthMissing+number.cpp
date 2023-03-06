/*
---------------------------------------------------------------------
1539. Kth Missing Positive Number

link -> https://leetcode.com/problems/kth-missing-positive-number/
---------------------------------------------------------------------
*/



// Time: O(N)
// Space: O(1)

class Solution {
public:
    int findKthPositive(vector<int>& A, int k) {
        for (int i = 1, j = 0; i <= 1000; ++i) {
            if (j < A.size() && A[j] == i) ++j;
            else if (--k == 0) return i;
        }
        return 1000 + k;
    }
};
