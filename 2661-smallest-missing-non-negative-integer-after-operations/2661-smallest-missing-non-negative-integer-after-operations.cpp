class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
    int n=nums.size();
    vector<int> mod(value,0);
    for(auto i:nums){
        long long ele=(value+i%value)%value;
        mod[ele%value]++;
    }
        for (int i = 0; i <= n + 1; i++) {
            int elem = i % value;

            if (mod[elem]) {
                mod[elem]--;
            } else {
                return i;
            }
        }

        return n + 1;
    }
};