/*
-------------------------------------------------------
912: Sort an Array

link -> https://leetcode.com/problems/sort-an-array/
-------------------------------------------------------
*/

 class Solution {
 public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i : nums)
            pq.push(i);
        for(int i=0;i<nums.size();i++){
            nums[i] = pq.top();
            pq.pop();
        }
        return nums;
    }
};
