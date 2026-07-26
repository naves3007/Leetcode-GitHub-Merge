class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(auto it : stones)pq.push(it);

        while(pq.size() > 1){
            int first = pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();

            // if(first != second){
                int diff = max(first, second) - min(first, second);
                pq.push(diff); // for the second round's pick
            // }
        }

        return pq.top();
    }
};