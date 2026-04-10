class Solution {
public:
    int minimumDistance(vector<int>& nums) {
   unordered_map<int, vector<int>> num_indices;
    int min_distance=INT_MAX;
    bool found_triplet=false;
    for(int i=0;i<nums.size();++i){
        int current_num=nums[i];
    
    if(num_indices.count(current_num)&&num_indices[current_num].size()>=2){
        found_triplet=true;
        int idx2=num_indices[current_num][num_indices[current_num].size()-1];
        int idx1=num_indices[current_num][num_indices[current_num].size()-2];
        int current_distance=(idx2-idx1)+(i-idx2)+(i-idx1);
        min_distance=min(min_distance,current_distance);
    }
    num_indices[current_num].push_back(i);
    }
    return found_triplet ? min_distance : -1;
    }
};