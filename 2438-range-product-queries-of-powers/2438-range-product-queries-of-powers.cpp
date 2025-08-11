class Solution {
public:
int m=1e9+7;
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int>ans;
        vector<int>powers;
        for(int i=0;i<32;i++)
        {
           if((n & (1<<i))!=0)
           {
            powers.push_back(pow(2,i));
           }
        }
        for(int i=0;i<queries.size();i++)
        {
            int p=queries[i][0];
            int q=queries[i][1];
            long product=1;
            for(int j=p;j<=p;j++)
            {
                product=(product*powers[j])%m;
            }
            ans.push_back(product);
        }
        return ans;
    }
};