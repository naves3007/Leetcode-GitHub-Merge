class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>pq;
        for(auto it : nums)pq.push(it);

        // k - 1 spaces below. 
        k--;
        while(k > 0){
            pq.pop();
            k--;
        }
        return pq.top();
    }
};