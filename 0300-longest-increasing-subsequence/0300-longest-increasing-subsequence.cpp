class Solution {

    int Max_Num(int a, int b){
        if( a>=b){
            return a;
        }else{
            return b;
        }
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>LIS(n,1);
        for(int i=n-2; i >=0 ; i--){
            for(int j=i+1 ; j<n ; j++){
                if(nums[i] < nums[j]){
                    LIS[i] = Max_Num( LIS[i],1+ LIS[j]);
                }
            }
        }
        int Max_LIS=LIS[0];
        for(int x : LIS){
            if(x > Max_LIS){
                Max_LIS = x;
            }
        }
        return Max_LIS;
    }
};