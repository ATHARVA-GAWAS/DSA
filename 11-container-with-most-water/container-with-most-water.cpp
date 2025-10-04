class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();

        int l=0,r=n-1;
        int max_area=0;

        while(l<r){
            int h=min(height[l],height[r]);
            int w=r-l;

            int area=h*w;

            max_area=max(max_area,area);

            if(height[l]<height[r]){
                l++;
            }
            else if(height[l]>height[r]){
                r--;
            }
            else{
                l++;
                r--;
            }
        }
        return max_area;
    }
};