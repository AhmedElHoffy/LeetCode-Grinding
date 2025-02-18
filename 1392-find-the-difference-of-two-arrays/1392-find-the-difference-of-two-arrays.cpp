class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        
        // Unique Elements in Vector nums1
        unordered_set<int>nums1_Set(nums1.begin(),nums1.end()); 

        // Unique Elements in Vector nums2
        unordered_set<int>nums2_Set(nums2.begin(),nums2.end());
        
        vector<vector<int>>Distinct_Arrays(2);

        for(int num : nums1_Set){
            if(nums2_Set.find(num)==nums2_Set.end()){
                Distinct_Arrays[0].push_back(num);
            }
        }

        for(int num : nums2_Set){
            if(nums1_Set.find(num)==nums1_Set.end()){
                Distinct_Arrays[1].push_back(num);
            }
        }
        return Distinct_Arrays;
    }
};

































/*

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> Distinct_Array(2);

        /*
        unordered_set<int> Set_Nums1;
        unordered_set<int> Set_Nums2;
        for(int i=0; i <nums1.size() ; i++){
            if(!Set_Nums1.count(nums1[i])){
                cout<<"Number "<<nums1[i]<< " is Entered in Hash Map 1"<<endl;
                 Set_Nums1.insert(nums1[i]);
            }
        }

        for (int j =0; j < nums2.size() ; j++){
            if(!Set_Nums2.count(nums2[j])){
                cout<<"Number "<<nums2[j]<< " is Entered in Hash Map 2"<<endl;
                Set_Nums2.insert(nums2[j]);
            }
        }


        unordered_set<int> Set_Nums1(nums1.begin(), nums1.end()); // Unique elements from nums1
        unordered_set<int> Set_Nums2(nums2.begin(), nums2.end()); // Unique elements from nums2
        for (int Curr1: Set_Nums1){
            if(!Set_Nums2.count(Curr1)){
                Distinct_Array[0].push_back(Curr1);
            }
        }

        for (int Curr2: Set_Nums2){
            if(!Set_Nums1.count(Curr2)){
                Distinct_Array[1].push_back(Curr2);
            }
        }

        return Distinct_Array;

    }
};
*/