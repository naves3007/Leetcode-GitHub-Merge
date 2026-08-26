class Solution {
public:
    int daysWhichMTakesFinder(vector<int>& v, int mid){
        int days = 1, load = 0;
        for(int i = 0; i < v.size(); i++){
            if(v[i] + load > mid){
                days += 1; // increase the days for the prev
                load = v[i]; // reassigning the current weight
            }
            else{
                load += v[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& v, int days) {
        int l = *max_element(v.begin(), v.end());
        int r = accumulate(v.begin(), v.end(), 0); // begin end start
        int ans = -1;
        while(l <= r){
            int m = (l + r) / 2;
            int daysWhichMTakes = daysWhichMTakesFinder(v, m);
            if(daysWhichMTakes <= days){
                ans = m;
                r = m - 1;
            }
            else{
                l = m + 1;
            }
        }
        return ans;
    }
};