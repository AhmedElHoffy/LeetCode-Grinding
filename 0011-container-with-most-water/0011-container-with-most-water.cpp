class Solution {
    int Min_Height(int a, int b){
        if(a <= b){
            return a;
        }else{
            return b;
        }
    }
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int Max_Area = INT_MIN;

        int left = 0, right=n-1;
        int Curr_Area=0;
        while( left < right){
            Curr_Area = (right - left) * Min_Height(height[left],height[right]);
            if(Curr_Area > Max_Area){
                Max_Area=Curr_Area;
            }
            if(height[left] > height[right] ){
                right--;
            }else if(height[left] <= height[right]){
                left++;
            }
        }
        return Max_Area;
    }
};



























/*
class Solution {
public:
    int Min_Height(int x, int y){
        if(x<=y){
            return x;
        }else{
            return y;
        }

    }
    int maxArea(vector<int>& height) {
        
        int left = 0; // Start pointer
        int right = height.size() - 1; // End pointer
        int Max_Area = 0; // Initialize max area
        
        while (left < right) {
            // Calculate the area
            int Calc_Area = min(height[left], height[right]) * (right - left);
            
            // Update the max area if the calculated area is larger
            Max_Area = max(Max_Area, Calc_Area);
            
            // Move the pointer pointing to the smaller height inward
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return Max_Area;      
    }
};

*/