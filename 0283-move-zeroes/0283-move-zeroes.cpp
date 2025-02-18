class Solution {
private: 
    void Swap_Nums(int &a, int &b){
        int temp = a;
            a = b;
            b = temp;
    }
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int Last_Non_Zero_Element_Idx=0;
        for(int i=0 ; i <n ; i++){
            if(nums[i]!=0){
                Swap_Nums(nums[i],nums[Last_Non_Zero_Element_Idx]);
                Last_Non_Zero_Element_Idx++;
            }
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