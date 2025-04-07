class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& Nums1, vector<int>& Nums2) {
        vector<vector<int>>Result(2);
        unordered_set<int>Set_Nums1;
        unordered_set<int>Set_Nums2;
        int n1=Nums1.size(), n2=Nums2.size();

        for(int i=0; i<n1 ; i++){
            Set_Nums1.insert(Nums1[i]);
        }

        for(int j=0; j<n2 ; j++){
            Set_Nums2.insert(Nums2[j]);
        }

        for(int Num1: Set_Nums1){
            if(!Set_Nums2.count(Num1)){
                Result[0].push_back(Num1);
            }
        }

        for(int Num2: Set_Nums2){
            if(!Set_Nums1.count(Num2)){
                Result[1].push_back(Num2);
            }
        }
        return Result;
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