/*
------------------------------------------------------
1345. Jump Game IV

link -> https://leetcode.com/problems/jump-game-iv/
-----------------------------------------------------
*/



// Time: O(N)
// Space: O(N)
class Solution {
public:
    int minJumps(vector<int>& A) {
        unordered_map<int, vector<int>> m;
        int N = A.size(), step = 0;
        for (int i = 0; i < N; ++i) m[A[i]].push_back(i);
        vector<bool> seen(N);
        seen[0] = true;
        queue<int> q{{0}};
        while (q.size()) {
            int cnt = q.size();
            while (cnt--) {
                int u = q.front();
                q.pop();
                if (u == N - 1) return step;
                if (u - 1 >= 0 && !seen[u - 1]) {
                    q.push(u - 1);
                    seen[u - 1] = true;
                }
                if (u + 1 < N && !seen[u + 1]) {
                    q.push(u + 1);
                    seen[u + 1] = true;
                }
                if (m.count(A[u])) {
                    for (int v : m[A[u]]) {
                        if (seen[v]) continue;
                        seen[v] = true;
                        q.push(v);
                    }
                    m.erase(A[u]);
                }
            }
            ++step;
        }
        return -1;
    }
};
