class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        map<int, int>mpp;
        for(auto it : nums)mpp[it]++;
        int first = nums[0];
        for(auto it : nums){
            if(mpp[it] != mpp[first] and it != first){
                return {first, it};
            }
        }
        return {-1,-1};
    }
};