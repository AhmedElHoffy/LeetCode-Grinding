class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int NonZero_idx=0;

        for(int i=0 ; i<n ; i++){
            if(nums[i]!=0){
                nums[NonZero_idx++]=nums[i];
            }
        }
        while(NonZero_idx < n) nums[NonZero_idx++]=0;   
    }
};