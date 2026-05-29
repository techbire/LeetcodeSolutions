class Solution {
public:
    void splitAdder(vector<int>& nums, vector<int>& newNums) {

        for (int num : nums) {

            string s = to_string(num);
            int sum = 0;

            for (char c : s) {
                sum += c - '0';
            }

            newNums.push_back(sum);
        }
    }

    int minElement(vector<int>& nums) {

        vector<int> newNums;

        splitAdder(nums, newNums);

        return *min_element(newNums.begin(), newNums.end());
    }
};