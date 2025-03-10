class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int Peak_Idx = -1;
        int Left = 0, Right = n-1, Mid;
        while(Left < Right){
            Mid = Left + (Right - Left) / 2;
            if(Mid > 0 &&  nums[Mid] < nums[Mid-1]){
                Right = Mid-1;
            }else if(Mid < n-1 && nums[Mid] < nums[Mid+1]){
                Left = Mid+1;
            }else {
                return  Mid;
            }
        }
        Peak_Idx = Left;
        return Peak_Idx;

    }
};











/*

class Solution {
public:

    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int Max = INT_MIN;
        int Peak_Idx;

        // Iterative Approach ; Time Complexity: O(n)
        
        //for(int i=0 ; i < n ; i++){
          //  if(nums[i] > Max){
            //    Max = nums[i];
                Peak_Idx = i;
            //}
        //}
        

        //Binary Search Approach; Time Complexity: O(logn)
        int Left=0,Right=n-1;
        int Mid;
        while(Left < Right){
            Mid = Left + (Right-Left)/2;
            //Check If Left Neighbor is greter than Mid
            if(Mid>0 && nums[Mid] < nums[Mid-1]){
                Right = Mid-1;
            }else if(Mid<n-1 && nums[Mid]< nums[Mid+1]){
                Left = Mid+1;
            }else{
                return Mid;
            }
        }
        Peak_Idx= Left;

        return Peak_Idx;
    }
};
*/