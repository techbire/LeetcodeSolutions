#define ll long long int

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return 0;

        vector<ll> a(nums.begin(), nums.end());
        vector<int> l(n), r(n);
        vector<bool> del(n, false);

        for(int i = 0; i < n; i++) {
            l[i] = i - 1;
            r[i] = i + 1;
        }

        priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;

        int good = 0;
        for(int i = 0; i < n - 1; i++) {
            if(a[i] <= a[i + 1]) good++;
            pq.push({a[i] + a[i + 1], i});
        }

        if(good == n - 1) return 0;

        int rem = n;

        while(rem > 1) {
            auto [sum, i] = pq.top();
            pq.pop();

            int j = r[i];
            if(j >= n || del[i] || del[j] || a[i] + a[j] != sum) continue;

            int pl = l[i];
            int nr = r[j];

            if(a[i] <= a[j]) good--;
            if(pl != -1 && a[pl] <= a[i]) good--;
            if(nr != n && a[j] <= a[nr]) good--;

            a[i] += a[j];
            del[j] = true;
            rem--;

            r[i] = nr;
            if(nr != n) l[nr] = i;

            if(pl != -1) {
                pq.push({a[pl] + a[i], pl});
                if(a[pl] <= a[i]) good++;
            }

            if(nr != n) {
                pq.push({a[i] + a[nr], i});
                if(a[i] <= a[nr]) good++;
            }

            if(good == rem - 1)
                return n - rem;
        }

        return n;
    }
};
