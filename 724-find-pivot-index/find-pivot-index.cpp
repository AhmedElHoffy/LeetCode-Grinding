class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int>Prefix_Sum(n,0);
        vector<int>Postfix_Sum(n,0);

        int Curr_Sum=0;
        int Index=-1;
        for(int i=0 ; i < n ; i++){
            Prefix_Sum[i] = Curr_Sum;
            Curr_Sum+=nums[i];
        }

        Curr_Sum=0;

        for(int j = n-1 ; j >=0 ; j--){
            Postfix_Sum[j] = Curr_Sum;
            Curr_Sum+=nums[j];
        }

        for(int k=0 ; k < n ; k++){
            if(Prefix_Sum[k] == Postfix_Sum[k]){
                Index = k;
                break;
            }
        }
        return Index;
        
    }
};






























/*

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        // nums = [] ; 
        int n = nums.size();
        vector<int> Prefix_Sum(n,0);
        int Prefix_Curr_Sum=0;
        vector<int>Postfix_Sum(n,0);
        int Postfix_Curr_Sum=0;
        
        for(int i=0; i < n ; i++){
            Prefix_Sum[i]+=Prefix_Curr_Sum;
            Prefix_Curr_Sum+=nums[i];
        }

        for(int j = n-1 ; j>=0 ; j--){
            Postfix_Sum[j] +=Postfix_Curr_Sum;
            Postfix_Curr_Sum+= nums[j];
        }

        for(int k = 0 ; k < n ; k++){
            if(Prefix_Sum[k] ==Postfix_Sum[k] ){
                return k;
            }
        }
        return-1;
    }
};
*/