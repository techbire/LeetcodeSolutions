class Solution {
public:
    bool isHappy(int n) {
    //fast n slow approach
    int slow=square(n);    
    int fast=square(square(n));    
    while(fast!=slow){
        slow=square(slow);
        fast=square(square(fast));
    }
    return slow==1;
    }

    int square(int n){
        int ans=0;
        while(n){
            int r=n%10;
            ans+=r*r;
            n=n/10;
        }
        return ans;
    }
};