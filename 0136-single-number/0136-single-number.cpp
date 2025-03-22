class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int Result =0;
        for(int x : nums){
            Result ^=x;
        }
        return Result;
    }
        
    
};