class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        int num_i=INT_MAX,num_j=INT_MAX;

        for(int num : nums){
            if(num <= num_i){
                num_i=num;
            }else if(num <= num_j){
                num_j=num;
            }else{
                return true;
            }
        }
        return false;

        
    }
};




























/*

 bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        bool found = false;
        if (n<3){
            return found;
        }else{
            
            vector<int>Left_MinArray(n);
            int min=nums[0];
            vector<int>Right_MaxArray(n);
            int max = nums[n-1];
            
            for(int i=0 ; i < n ; i++){
                if(nums[i] < min) min = nums[i];
                Left_MinArray[i]= min;
            }

            for( int j = n-1 ; j>=0 ; j--){
                if(nums[j] > max) max = nums[j];
                Right_MaxArray[j] = max;
            }
            for(int x = 0; x<n ; x++){
                if(Left_MinArray[x] < nums[x] && nums[x] < Right_MaxArray[x] ){
                    found = true;
                    return found;
                }
            }
            

            // O(1) Space Complexity solution

            int First_num = INT_MAX;
            int Second_num = INT_MAX;
            for(int Last_num = 0 ; Last_num < n ; Last_num++){
                if(First_num >=nums[Last_num]){
                    First_num = nums[Last_num];
                }else if(Second_num >= nums[Last_num]){
                    Second_num = nums[Last_num];
                }else{
                    found = true;
                    return found;
                }
            }
            }
            return found;
        }

        */