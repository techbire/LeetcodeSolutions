class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int mintime = INT_MAX;
        int l = landStartTime.size(), w = waterStartTime.size();
        auto finish = [](int end1, int start2, int dur2) {
            return max(end1, start2) + dur2;  
        };
        for (int i = 0; i < l; i++) {
            int landEnd = landStartTime[i] + landDuration[i];
            for (int j = 0; j < w; j++) {
                int waterEnd = waterStartTime[j] + waterDuration[j];     
                mintime = min(mintime, finish(landEnd, waterStartTime[j], waterDuration[j]));  
                mintime = min(mintime, finish(waterEnd, landStartTime[i], landDuration[i]));  
            }
        }

        return mintime;
    }
};