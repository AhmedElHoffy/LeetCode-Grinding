class Solution {
public:
    int longestOnes(vector<int>& Nums, int k) {
        int n = Nums.size();
        int Left_Ptr=0,Max_Ones=0;
        for(int Right_Ptr=0 ; Right_Ptr<n ; Right_Ptr++){

            if(Nums[Right_Ptr]==0){
                k--;
            }

            while(k<0){
                if(Nums[Left_Ptr]==0){
                    k++;
                }
                Left_Ptr++;
            }
            
            Max_Ones = max(Max_Ones, Right_Ptr - Left_Ptr + 1);
        }
        return Max_Ones;
    }
};












/*
 int Max_Num(int a, int b){
        return (a>=b) ? a:b;
    }
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int Start_Seq = 0, End_Seq=0;
        int Zeros_Count=0,Max_Length=0;

        while(End_Seq < n){

            if(nums[End_Seq]==0){
                Zeros_Count++;
            }

            while(Zeros_Count > k){
                if(nums[Start_Seq]==0){
                    Zeros_Count--;
                }
                Start_Seq++;
            }
            Max_Length = Max_Num(Max_Length, End_Seq - Start_Seq + 1);
            End_Seq++;
        }       
        return Max_Length;
    }
*/
























/*

 int n = nums.size();
        int l=0, Max_Length=0;
        for(int i=0; i < n ; i ++){
            k-= (1-nums[i]);

            if(k < 0){
                k+=(1 - nums[l]);
                l++;
            }else{
                Max_Length = Max_Num(Max_Length,i-l+1);
            }
        }
        return Max_Length;
*/


















/*

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int Start_Sequence = 0; // Left pointer of the sliding window
        int End_Sequence = 0; // Right pointer of the sliding window
        int max_length = 0; // To store the maximum length of the subarray
        int zero_count = 0; // To track the number of zeros in the current window

        // Iterate through the array using the right pointer
        while (End_Sequence < nums.size()) {
            // If we encounter a zero, increment the zero_count
            if (nums[End_Sequence] == 0) {
                zero_count++;
            }

            // If the number of zeros exceeds k, shrink the window from the left
            while (zero_count > k) {
                if (nums[Start_Sequence] == 0) {
                    zero_count--;
                }
                Start_Sequence++; // Move the left pointer to shrink the window
            }

            // Calculate the current window size and update max_length
            max_length = max(max_length, End_Sequence - Start_Sequence + 1);

            // Move the right pointer to expand the window
            End_Sequence++;
        }

        return max_length;
    }
};

*/