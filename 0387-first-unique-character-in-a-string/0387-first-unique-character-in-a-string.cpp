class Solution {
public:
    int firstUniqChar(string s) {
        map<char, int>mpp;
        for(auto it : s){
            mpp[it]++;
        }
        int idx = 0;
        for(auto it : s){
            if(mpp[it] == 1){
                return idx; 
            }
            idx++;
        }
        return -1;
    }
};