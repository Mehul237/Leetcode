/*
-----------------------------------------------------------------------------------
2187. Minimum Time to Complete Trips

link -> https://leetcode.com/problems/minimum-time-to-complete-trips/description/
----------------------------------------------------------------------------------
*/



// Time: O(NlogM) where M is the maximum possible answer
// Space: O(1)
class Solution {
public:
    long long minimumTime(vector<int>& A, int totalTrips) {
        long long L = 1, R = LONG_MAX;
        auto valid = [&](long long time) { // returns true if we can finish `totalTrips` trips given `time`
            long long sum = 0;
            for (long long n : A) {
                sum += time / n;
                if (sum >= totalTrips) return true; 
            }
            return false;
        };
        while (L <= R) {
            long long M = L + (R - L) / 2;
            if (valid(M)) R = M - 1;
            else L = M + 1;
        }
        return L;
    }
};
