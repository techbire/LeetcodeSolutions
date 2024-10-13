class ComparePairs {
public:
    bool operator()(const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b) {
        return a.first > b.first;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, ComparePairs> minHeap;
        int maxInHeap = INT_MIN;
        
        // initialize the priority queue with the first element of each list
        for (int i = 0; i < nums.size(); i++) {
            pair<int, pair<int, int>> current = {nums[i][0], {i, 0}};
            minHeap.push(current);
            maxInHeap = max(maxInHeap, current.first);
        }
        
        // tracking small range
        int rangeStart = minHeap.top().first;
        int rangeEnd = maxInHeap;
        
        // expanding the range
        while (!minHeap.empty()) {
            int currentValue = minHeap.top().first;
            pair<int, int> pos = minHeap.top().second;
            int row = pos.first;
            int col = pos.second;
            minHeap.pop();

            // Update the range if the current range is smaller
            if ((maxInHeap - currentValue) < (rangeEnd - rangeStart)) {
                rangeStart = currentValue;
                rangeEnd = maxInHeap;
            }
            
            // If there are more elements in the current list, add them to the heap
            if (col + 1 < nums[row].size()) {
                pair<int, pair<int, int>> nextElement = {nums[row][col + 1], {row, col + 1}};
                minHeap.push(nextElement);
                maxInHeap = max(maxInHeap, nextElement.first);
            } else {
                break;  // If one of the lists is fully traversed, stop the process
            }
        }
        
    return {rangeStart, rangeEnd};
    }
};
