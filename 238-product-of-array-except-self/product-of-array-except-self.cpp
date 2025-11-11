class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>Res(n,1);

        int Prefix = 1;
        for(int i=0; i<n ; i++){
            Res[i]=Prefix;
            Prefix*=nums[i];
        }

        int Postfix = 1;
        for(int j=n-1; j>=0 ; j--){
            Res[j]*=Postfix;
            Postfix*=nums[j];
        }
        return Res;
    }
};


/*
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>PreFix_Prod(n,1),PostFix_Prod(n,1);
        int Curr_Total=1;
        for(int i=0 ; i<n ; i++){
            PreFix_Prod[i]=Curr_Total;
            Curr_Total*=nums[i];
        }
        Curr_Total=1;

        for(int j=n-1; j>=0 ; j--){
            PostFix_Prod[j]=Curr_Total;
            Curr_Total*=nums[j];
        }
        vector<int>Result(n,1);
        for(int k=0 ; k<n ; k++){
            Result[k] = PreFix_Prod[k] * PostFix_Prod[k];
        }
        return Result;
    }
*/