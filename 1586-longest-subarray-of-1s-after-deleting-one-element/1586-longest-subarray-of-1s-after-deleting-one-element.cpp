class Solution {

private: 
    int Max_Num(int a, int b){
        return (a>=b) ? a:b;
    }
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int Start_Seq=0,End_Seq=0,Zeros_Count=0;
        int Max_Length=0;

        while(End_Seq < n ){

            if(nums[End_Seq]==0){
                Zeros_Count++;
            }

            while(Zeros_Count > 1){
                if(nums[Start_Seq]==0){
                    Zeros_Count--;
                }
                Start_Seq++;
            }

             Max_Length = Max_Num(Max_Length, End_Seq - Start_Seq);
             End_Seq++;
        }
        return Max_Length;
    }
};































/*

class Solution {
public:
        int longestSubarray(vector<int>& nums) {
        int Start_Seq = 0;
        int End_Seq = 0;
        int Max_Length_Ones = 0;
        int Curr_Length_Ones = 0;
        int Zeros_count = 0;

        while (End_Seq < nums.size()) {
            // Expand the window
            if (nums[End_Seq] == 1) {
                Curr_Length_Ones++;
            } else {
                Zeros_count++;
            }
            End_Seq++;

            // Shrink the window if there are more than 1 zero
            while (Zeros_count > 1) {
                if (nums[Start_Seq] == 1) {
                    Curr_Length_Ones--;
                } else {
                    Zeros_count--;
                }
                Start_Seq++;
            }

            // Update the maximum length (subtract 1 because one element must be deleted)
            Max_Length_Ones = max(Max_Length_Ones, Curr_Length_Ones);
        }

        // Ensure we account for the required deletion of one element
        return (Max_Length_Ones == nums.size()) ? Max_Length_Ones - 1 : Max_Length_Ones;
    }
};
*/