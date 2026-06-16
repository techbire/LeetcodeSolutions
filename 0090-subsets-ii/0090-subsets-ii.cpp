class Solution {
public:
    vector<vector<int>> res;

    void generate(vector<int>& nums, vector<int>& curr, int index) {
        res.push_back(curr);

        for (int i = index; i < nums.size(); i++) {
            if (i > index && nums[i] == nums[i - 1])
                continue;

            curr.push_back(nums[i]);
            generate(nums, curr, i + 1);
            curr.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> curr;
        generate(nums, curr, 0);

        return res;
    }
};