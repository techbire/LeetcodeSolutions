class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double ans=0.0;
        int n=points.size();
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                for(int k=j+1;k<n;k++){
                    double a=len(points[i],points[k]);
                    double b=len(points[i],points[j]);
                    double c=len(points[j],points[k]);
                    double area=f(a,b,c);
                    ans=max(ans,area);
                }
            }
        }
        return ans;
    }
    double len(vector<int> &p1,vector<int> &p2){
        int x1=p1[0];
        int y1=p1[1];
        int x2=p2[0];
        int y2=p2[1];
        double dis=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        return dis;
    }
    double f(double a,double b,double c){
        double s=(a+b+c)/2;
        double area=sqrt(s*(s-a)*(s-b)*(s-c));
        return area;
    }
};