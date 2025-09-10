class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m=languages.size();
        vector<unordered_set<int>> knows(m+1);
        for(int i=0;i<languages.size();i++){
            for(int j=0;j<languages[i].size();j++)
            knows[i+1].insert(languages[i][j]);
        }
         unordered_set<int> s;
        for(auto it:friendships){
            int friend1=it[0];
            int friend2=it[1];
            bool found=false;
            for(auto lang:languages[friend1-1]){
                  if(knows[friend2].find(lang)!=knows[friend2].end()){
                    found=true;
                    break;
                  }
            }
            if(!found){
                s.insert(friend1);
                s.insert(friend2);
            }
        }
        int ans=INT_MAX;
        for(int lang=1;lang<=n;lang++){
            int count=0;
            for(auto num:s){
                if(knows[num].find(lang)==knows[num].end())count++;
            }
            ans=min(ans,count);
        }
        return ans;
    }
};