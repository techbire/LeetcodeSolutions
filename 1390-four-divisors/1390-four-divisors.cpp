class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int sum = 0;

        for(int n : nums){
            vector<int> d;
            for(int i = 1; i * i <= n; i++){
                if(n % i == 0){
                    d.push_back(i);
                    if(i != n / i) d.push_back(n / i);
                }
            }
            if(d.size() == 4){
                for(int x : d) sum += x;
            }
        }
        return sum;
    }
};
