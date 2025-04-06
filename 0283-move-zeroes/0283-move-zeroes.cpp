class Solution {
private: 
    void Swap_Nums(int &a, int &b){
        int temp=a;
        a = b;
        b = temp;
    }

public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int Write_Idx=0;
        for(int i=0; i < n ; i++){
            if(nums[i]!=0){
                nums[Write_Idx++] = nums[i];
            }
        }
        for(int j=Write_Idx ; j < n ; j++){
            nums[j]=0;
        }
    }
};





























/*
class Solution {
public:

void swap_nums(int &x, int &y){
    int temp = x;
    x = y;
    y = temp;

}
    void moveZeroes(vector<int>& nums) {
        int lastNonZeroFoundAt = 0; // Pointer for the position of the next non-zero element

        // Move all non-zero elements to the beginning of the array
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[lastNonZeroFoundAt++] = nums[i];
            }
        }

        // Fill the rest of the array with zeroes
        for (int i = lastNonZeroFoundAt; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
    
};
*/