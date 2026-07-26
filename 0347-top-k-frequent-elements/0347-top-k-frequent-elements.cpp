class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        priority_queue<pair<int,int>>pq;

        // 1. create a freqency map
        for(auto it : nums)mpp[it]++;

        // 2. Sort based on frequency (want top k freq elements). 
        // <Frequency, Number>
        for(auto it : mpp){
            pq.push({it.second, it.first});
        }

        vector<int>ans;
        while(k > 0){
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return ans;
    }
};