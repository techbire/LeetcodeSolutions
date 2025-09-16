class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<int>st;
        for(int i=0;i<nums.size();i++){
            if(st.empty()){
                st.push(nums[i]);
            } else {
                int a = st.top();
                if(__gcd(a,nums[i]) > 1){
                    st.pop();
                    int topElement = lcm(nums[i],a);
                    if(!st.empty()) {
                    int secondElement = st.top();
                    while(!st.empty() && __gcd(topElement, secondElement) > 1){
                        topElement = lcm(topElement, secondElement);
                        st.pop();
                        if(!st.empty()) {
                        secondElement = st.top();
                        }
                    }

                    }
                    st.push(topElement);
                } else {
                    st.push(nums[i]);
                }
            }
        }

        vector<int>res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};