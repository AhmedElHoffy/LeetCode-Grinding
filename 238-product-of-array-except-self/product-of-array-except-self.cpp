class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int nums_Size=  nums.size();
        vector<int>Result(nums_Size,1);
        int Curr_Product=1;
        
        // Compute Prefix+Product First
        for(int i = 0 ; i<nums_Size ; i++){
            Result[i]*=Curr_Product;
            Curr_Product*=nums[i];;
        }

        Curr_Product=1;
        for(int j = nums_Size-1 ; j>=0 ; j--){
            Result[j]*=Curr_Product;
            Curr_Product*=nums[j];
        }
        return Result;

       // Slow approach as it uses space complexity O(N)
        /*int nums_Size=  nums.size();
        vector<int>Prefix_Product(nums_Size,1);
        vector<int>Postfix_Product(nums_Size,1);

        int Curr_Product=1;
        for(int i=1 ; i<nums_Size ; i++){
            Curr_Product*=nums[i-1];
            Prefix_Product[i] = Curr_Product;
        }

        cout<<"Prefix Product Vector Elements are = [ ";
        for(int x: Prefix_Product){
            cout<<x <<" ";
        }
        cout<<"]"<<endl;

        Curr_Product=1;
        for(int j=nums_Size-2 ; j>=0 ; j--){
            Curr_Product*=nums[j+1];
            Postfix_Product[j] = Curr_Product;
        }

        cout<<"Post Product Vector Elements are = [ ";
        for(int x: Postfix_Product){
            cout<<x <<" ";
        }
        cout<<"]"<<endl;
        
        vector<int>Result(nums_Size,1);
        for(int i=0 ; i<nums_Size ; i++){
            Result[i]=Prefix_Product[i] * Postfix_Product[i];
        }
        return Result;
        */
    }
};
















/*
// O(N^2) Not sufficient
    int ProductIdx_ExceptSelf(vector<int> nums, int CurrIdx){
        int product=1;
        for(int j=0 ; j <nums.size() ;j++){
            if(j!=CurrIdx){
                product*=nums[j];
            }
        }
        return product;

    }
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>Answer(nums);
        for(int i=0 ; i < nums.size() ; i++){
            Answer[i] = ProductIdx_ExceptSelf(nums,i);
        }
        return Answer;
    }

    // Use Prefix and Postfix to do it in O(N)
    vector<int> productExceptSelf(vector<int>& nums){
        
        vector<int>Prefix_Array(nums.size(),1);
        vector<int>Postfix_Array(nums.size(),1);

        int Prefix_product=1;
        for(int i=0; i <nums.size();i++){
            Prefix_Array[i] = Prefix_product;
            Prefix_product*=nums[i];
        }

        int Postfix_product=1;
        for(int j=nums.size() - 1; j >=0 ; j--){
            Postfix_Array[j] = Postfix_product;
            Postfix_product*=nums[j];
        }
        vector<int>Result(nums.size(),1);
        for(int k = 0 ; k < nums.size() ; k++){
            Result[k] = Prefix_Array[k] *  Postfix_Array[k];
        }
        return Result;
    }
};
*/