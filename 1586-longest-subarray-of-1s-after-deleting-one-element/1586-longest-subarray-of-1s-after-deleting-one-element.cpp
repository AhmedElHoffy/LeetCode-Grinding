class Solution {
public:
    int longestSubarray(vector<int>& Nums) {
     int n=Nums.size();
     int Left_Idx=0, Right_Idx=0, Zeros_Count=0;
     int Max_Len=0;
     while(Right_Idx < n){
        if(Nums[Right_Idx]==0) Zeros_Count++;
        while(Zeros_Count>1){
            if(Nums[Left_Idx]==0){
                Zeros_Count--;
            }
            Left_Idx++;
        }
        Max_Len = max(Max_Len , Right_Idx-Left_Idx);
        Right_Idx++;
     }
     return Max_Len;
    }
};










/*

  int longestSubarray(vector<int>& Nums) {
      int n = Nums.size();
      int Left=0,Right=0,Zeros_Count=0;
      int Max_Len=0;
      while(Right<n){
        if(Nums[Right]==0)Zeros_Count++;
        while(Zeros_Count>1){
            if(Nums[Left]==0){
                Zeros_Count--;
            }
            Left++;
        }
        Max_Len = max(Max_Len, Right  - Left);
        Right++;
      }
      return Max_Len;
    }

*/




















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