class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(auto it : stones)pq.push(it);

        while(pq.size() > 1){ // <2,2>
            int first = pq.top(); // 2
            pq.pop(); // <2>
            int second = pq.top(); // 2
            pq.pop(); // <>

            if(first != second){
                int diff = max(first, second) - min(first, second);
                pq.push(diff); // for the second round's pick
            }
        }
        if(pq.size() == 0)return 0;
        return pq.top();
    }
};