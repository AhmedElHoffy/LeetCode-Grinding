class Solution {
    
public:
    int maxArea(vector<int>& Heights) {
        int n = Heights.size();
        int Max_Area=0;
        int Left_Ptr=0, Right_Ptr=n-1;
        int Curr_Area;
        while(Left_Ptr < Right_Ptr){
            Curr_Area = (Right_Ptr - Left_Ptr) * (min(Heights[Left_Ptr],Heights[Right_Ptr]));
            Max_Area = max(Max_Area,Curr_Area);
            if(Heights[Left_Ptr] <= Heights[Right_Ptr]){
                Left_Ptr++;
            }else{
                Right_Ptr--;
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