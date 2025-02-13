class Solution {
public:
    int minOperations(vector<int>& nums, int k) {

//bruteforce approach


        // sort(nums.begin(), nums.end());
        // int counter = 0;
        
        // while (nums.size() > 1 && nums[0] < k) {
        //     long long x = nums[0], y = nums[1];
        //     long long z = min(x, y) * 2 + max(x, y);
        //     nums.erase(nums.begin());
        //     nums.erase(nums.begin());
        //     nums.push_back(z);
        //     sort(nums.begin(), nums.end());
        //     counter++;
        // }
        
        // return counter;
        

    priority_queue<long,vector<long>,greater<long>>pq(begin(nums),end(nums));  //heapify long
    int counter=0;
    while(!pq.empty()&&pq.top()<k){
        long smallest=pq.top();
        pq.pop();
        long secondsmallest=pq.top();
        pq.pop();
        pq.push(smallest*2+secondsmallest);
        count++;
    }
    return count;

    
    }
};