class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int l = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        for(int cSize: s){
            if(cSize >= g[l]){
                l++;
                if(l == g.size()) break;
            }
        }
        return l;
    }
};