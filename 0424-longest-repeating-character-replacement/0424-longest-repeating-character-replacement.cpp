class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0, n = s.size(), maxi = 0, freq = 0;
        unordered_map<int, int>mpp;
        while(r < n){
            mpp[s[r]]++;
            freq = max(freq, mpp[s[r]]);
            if((r - l + 1) - freq > k){ // doesn't statisfy
                mpp[s[l]]--; // reduce the freq
                l++; // move
            }
            maxi = max(maxi, (r - l + 1));
            r++;
        }
        return maxi;
    }
};