class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        sort(begin(events),end(events));
        int maxVal = 0;
        int ans = 0;
        for(auto& event : events){
            int start = event[0];
            int end = event[1];
            int val = event[2];
            while(!pq.empty() && pq.top().first < start){
                maxVal = max(maxVal,pq.top().second);
                pq.pop();
            }
            ans = max(ans, maxVal + val);
            pq.push({end,val});
        }
        return ans;
    }
};