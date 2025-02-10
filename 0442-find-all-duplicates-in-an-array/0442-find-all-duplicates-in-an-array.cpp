class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
    int n=nums.size();
    int i=0;
    while(i<n){
        int correctindex=nums[i]-1;
        if (correctindex >= 0 && correctindex < n && nums[i] != nums[correctindex])  
        swap(nums[i], nums[correctindex]);  
    else  
        i++;  
    }
         vector<int> duplicates;
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) 
                duplicates.push_back(nums[i]);
        }
        
        return duplicates;
    }
};