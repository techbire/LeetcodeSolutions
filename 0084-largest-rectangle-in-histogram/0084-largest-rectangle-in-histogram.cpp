class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
         int n=heights.size(),ans=0;

   stack<int>s;

   for(int i=0;i<=n;i++){

     while(!s.empty() and (i==n or heights[s.top()]>=heights[i])){

            int height=heights[s.top()];

            s.pop();

            int width=s.empty()?i:i-s.top()-1;

            ans=max(ans,height*width);

     }

     s.push(i);

   }

   return ans;

 }  
};