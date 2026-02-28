class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int>track;
        for(int i = 0; i < nums.size(); i++){
            track[nums[i]] = i;
        }
        for(int i = 0; i < nums.size(); i++){
            int first = nums[i];
            int second = 0;
            if(track.find(target - nums[i]) != track.end() and track[target - nums[i]] != i){
                return {i, track[target - nums[i]]};
            }
        }
        return {0,0};
    }
};