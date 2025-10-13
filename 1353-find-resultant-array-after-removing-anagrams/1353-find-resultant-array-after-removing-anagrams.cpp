class Solution {
    bool anag(string s1,string s2)
    {
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());

        return s1==s2;
    }
public:
    vector<string> removeAnagrams(vector<string>& words) {
        int n=words.size();
        int left=0;
        int i=1;
        int k=1;
        vector<string>ans(n," ");
        ans[0]=words[0];
        while(i<n)
        {
            if(anag(words[i],words[left]))
            {
                i++;
            }
            else
            {
                ans[k++]=words[i];
                left=i;
                i++;
            }
        }
        ans.resize(k);
        return ans;
    }
};