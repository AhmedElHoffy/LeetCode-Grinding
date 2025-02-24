class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>HashMap;
        int n = nums.size();
        int complement;
        for(int i=0; i<n ; i++){
            complement = target - nums[i];
            if(HashMap.find(complement)!=HashMap.end()){
                return {i,HashMap[complement]};
            }
            HashMap[nums[i]] = i;
        }
        return {};

    }
};













/*
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>Nums_Map;
        int n = nums.size();
        int comp;
        for(int i=0; i < n ; i++){
            comp = target - nums[i];
            if(Nums_Map.find(comp)!=Nums_Map.end()){
                return {i,Nums_Map[comp]};
            }
            // Store the key,val pair 
            Nums_Map[nums[i]]=i;
        }
        return {};
    }
};
*/