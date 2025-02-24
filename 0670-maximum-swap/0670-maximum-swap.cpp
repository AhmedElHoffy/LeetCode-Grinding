class Solution {
    vector<int> Convert_Num_to_Digits(int num){
        vector<int> Result={};
        while(num>0){
            Result.push_back(num%10);
            num/=10;
        }
        reverse(Result.begin(),Result.end());
        return Result;
    }

    
    
public:
    int maximumSwap(int num) {
        vector<int> nums = Convert_Num_to_Digits(num);
        int n = nums.size();

        // Step 1: Track the rightmost max digit from right to left
        int maxIdx = n - 1;  // Rightmost max digit index
        int Pivot = -1, SwapIdx = -1;  // Positions to swap

        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] > nums[maxIdx]) {
                maxIdx = i;  // Update max index
            } else if (nums[i] < nums[maxIdx]) {
                // First smaller digit found, mark swap positions
                Pivot = i;
                SwapIdx = maxIdx;
            }
        }

        // Step 2: Swap the identified digits (if valid swap exists)
        if (Pivot != -1) {
            swap(nums[Pivot], nums[SwapIdx]);
        }

        // Step 3: Convert back to integer
        int NewNum = 0;
        for (int digit : nums){
            NewNum = NewNum * 10 + digit;
        }

        return NewNum;
    }
};