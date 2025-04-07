class Solution {

public:
    double findMaxAverage(vector<int>& Nums, int k) {
      int n = Nums.size();
      double Max_Avg=-1e9;
      double Curr_Sum=0;
      for(int i=0 ; i<k ; i++){
        Curr_Sum+=Nums[i];
      }
      Max_Avg = Curr_Sum/k;
      
      for(int j=k; j<n ; j++){
        Curr_Sum+=Nums[j];
        Curr_Sum-=Nums[j-k];
        if((Curr_Sum/k) > Max_Avg){
            Max_Avg= Curr_Sum/k;
        }
      }
      return Max_Avg;
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