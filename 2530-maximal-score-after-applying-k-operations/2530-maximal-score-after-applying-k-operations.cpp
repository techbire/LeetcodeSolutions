class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> maxHeap(nums.begin(), nums.end());
        long long sum=0; 
        for(int i=0;i<k;i++){
            int largest = maxHeap.top();
            maxHeap.pop();
            sum += largest;
            maxHeap.push(ceil(largest / 3.0));         

        }
        return sum;
        
        
        
        
    }
};