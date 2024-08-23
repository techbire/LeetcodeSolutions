class Solution {
public:
    bool isIsomorphic(string s, string t) {
      if(s.length()!=t.length()) return false;
        vector<int> v(150,1000);
        for(int i=0;i<s.length();i++){
           int index=(int)s[i]; //ascii
            if(v[index]==1000) v[index]= s[i]-t[i];
            else if (v[index]!=(s[i]-t[i])) return false;
        }
        //remove all element in vector
        for(int i=0;i<150;i++)
            v[i]=1000;
            for(int i=0;i<s.length();i++){
                int index=(int)t[i];
                if(v[index]==1000) v[index]=t[i]-s[i];
                else if(v[index]!=(t[i]-s[i])) return false;
            
        }
        return true;
    }
};