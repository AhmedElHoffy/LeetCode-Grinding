class Solution {
public:
    void swap_nums(int &a, int &b){
        int temp = a;
        a = b;
        b = temp;
    }
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