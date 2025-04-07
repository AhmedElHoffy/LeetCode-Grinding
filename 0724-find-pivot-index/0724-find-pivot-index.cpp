class Solution {
public:
    int pivotIndex(vector<int>& Nums) {
        int n=Nums.size();

        int Prefix_Sum=0, Total_Sum=0;

        for(int Num:Nums){
            Total_Sum += Num;
        }

        for(int i=0 ; i<n ; i++){
            if(Prefix_Sum == Total_Sum - Prefix_Sum -Nums[i]){
                return i;
            }
            Prefix_Sum+=Nums[i];
        }
        return -1;
    }
};


/*

int pivotIndex(vector<int>& Nums) {
        int n=Nums.size();
        vector<int> Prefix_Vec(n,0);
        vector<int> Postfix_Vec(n,0);
        int Curr_Sum=0;
        for(int i=0; i<n ;i++){
            Prefix_Vec[i]=Curr_Sum;
            Curr_Sum+=Nums[i];
        }
        Curr_Sum=0;
        for(int j=n-1; j>=0 ; j--){
            Postfix_Vec[j]=Curr_Sum;
            Curr_Sum+=Nums[j];
        }

        for(int k=0 ; k<n ;k++){
            if(Prefix_Vec[k] == Postfix_Vec[k]){
                return k;
            }
        }
        return -1;
    }

*/



























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