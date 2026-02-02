class Solution {
public:
    typedef long long ll;
    typedef pair<ll , ll> p;  

    long long minimumCost(vector<int>& nums, int k, int dist) {
        ll n = nums.size(); 

        set<p> m;
        set<p> r;

        ll sum = 0; 

        int i = 1; 
        while (i <= dist + 1 && i < n) {
            m.insert({nums[i], i}); 
            sum += nums[i]; 

            if (m.size() > k-1) {
                p temp = *m.rbegin(); 
                sum -= temp.first; 
                r.insert(temp); 
                m.erase(temp); 
            }
            i++; 
        }

        ll result = sum;

        while (i < n) {
            p remove = {nums[i-dist-1] , i-dist-1}; 

            if (m.count(remove)) {
                m.erase(remove); 
                sum -= remove.first; 

                if (!r.empty()) {
                    p temp = *r.begin(); 
                    m.insert(temp); 
                    sum += temp.first; 
                    r.erase(temp); 
                }
            } else {
                r.erase(remove); 
            }

            m.insert({nums[i], i}); 
            sum += nums[i]; 

            if (m.size() > k-1) {
                p temp = *m.rbegin(); 
                sum -= temp.first;
                r.insert(temp); 
                m.erase(temp);  
            }

            result = min(result , sum); 
            i++; 
        }

        return nums[0] + result; 
    }
};