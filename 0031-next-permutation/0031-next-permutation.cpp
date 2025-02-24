class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int num1_Idx=-1,num2_Idx;
        for(int i = n-2 ; i>=0 ; i--){
            if(nums[i]<nums[i+1]){
                num1_Idx=i;
                break;
            }
        }
        if(num1_Idx==-1){
            reverse(nums.begin(),nums.end());
            return;
        }

        for(int j=n-1 ; j >num1_Idx ; j--){
            if(nums[j]> nums[num1_Idx]){
                num2_Idx = j;
                break;
            }
        }
        swap(nums[num1_Idx],nums[num2_Idx]);

        reverse(nums.begin()+num1_Idx+1,nums.end());
    }
};
















/*

class Solution {

public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int pivot=-1, pivot_idx=n-1;

        // Step 1: Find Pivot ---> nums[i] < nums[i+1] . start at n-2
        for(int i=n-2 ; i>=0 ; i--){
            if(nums[i] <nums[i+1]){
                pivot_idx=i;
                pivot=nums[i];
                break;
            }
        }

        // if pivot not found
        if(pivot==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        //Step 2: Find Successor; Start from n-1, find nums[j] > pivot
        for(int j=n-1 ; j> pivot_idx ; j--){
            if(nums[j] > pivot){
                swap(nums[pivot_idx],nums[j]);
                break;
            }
        }

        // Step 3: reverse from pivot_idx+1  till end
        reverse(nums.begin()+pivot_idx+1,nums.end());
        return;
        }
        
};
*/