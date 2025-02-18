class Solution {
private: 
    double Max_Num (int x, int y){
        if(x>=y){
            return x;
        }else{
            return y;
        }
    }

public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double Curr_Sum=0;
        double Max_Sum;
        // Get the First Sum
        for(int i=0 ; i < k ; i++){
            Curr_Sum+=nums[i];
        }
        Max_Sum = Curr_Sum ;

        int End_Ptr= k;
        int Start_Ptr = 0;

        while(End_Ptr < n){
            Curr_Sum+=nums[End_Ptr++];
            Curr_Sum-=nums[Start_Ptr++];
            Max_Sum = Max_Num(Max_Sum,Curr_Sum);
        }
        return Max_Sum/k;
    }
};































/*
class Solution {
public:
    int Max_num(int x, int y){
        if(x>= y ){
            return x;
        }else{
            return y;
        }
    }
    double findMaxAverage(vector<int>& nums, int k) {
        double Max_Sum=0;
        double Curr_Sum=0;

        // Get the first window sum
        for(int i=0; i < k ; i++){
            Curr_Sum+=nums[i];
        }
        Max_Sum = Curr_Sum;

        // Moving the Sliding Window one by one
        for(int j=k ; j<nums.size() ; j++ ){
            Curr_Sum = Curr_Sum + nums[j] - nums[j-k];
            Max_Sum = Max_num(Curr_Sum,Max_Sum);
        }
        return Max_Sum / k;
    }
};
*/