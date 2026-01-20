class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();

        for(int i=0; i<n; i++) {
            int num = nums[i];
            int temp = -1;
            while(num > 0) {
                if((num | (num - 1)) == nums[i]) {
                    temp = num - 1;
                }
                num--;
            }
            ans.push_back(temp);
        }

        return ans;
    }
};