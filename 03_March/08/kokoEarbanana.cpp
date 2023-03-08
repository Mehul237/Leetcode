
/*
-------------------------------------------------------------------------
875. Koko Eating Bananas

link -> https://leetcode.com/problems/koko-eating-bananas/description/
------------------------------------------------------------------------
*/


// Time: O(P*log(P_max)) where P is count of piles, P_max is max pile size.
// Space: O(K)
class Solution {
public:
    int minEatingSpeed(vector<int>& A, int h) {
        long L = 1, R = *max_element(begin(A), end(A)), N = A.size();
        auto valid = [&](long k) {
            int i = 0, tmp = h; 
            for (; i < N && h > 0; ++i) {
                tmp -= (A[i] + k - 1) / k;
            }
            return i == N && tmp >= 0;
        };
        while (L <= R) {
            long M = (L + R) / 2;
            if (valid(M)) R = M - 1;
            else L = M + 1;
        }
        return L;
    }
};
