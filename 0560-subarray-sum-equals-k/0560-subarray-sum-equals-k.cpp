class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int Curr_Sum=0;
        int counter=0;
        int temp;
        unordered_map<int,int>Prefix_SumFreq;
        Prefix_SumFreq[0]++;

        for(int num : nums){
            Curr_Sum+=num;
            temp = Curr_Sum - k;
            if(Prefix_SumFreq.find(temp)!=Prefix_SumFreq.end()){
                counter+=Prefix_SumFreq[temp];
            }
                Prefix_SumFreq[Curr_Sum]++;
        }
        return counter;
    }
};

//Prefix_Sum = [1,2,3] , k = 2; 















/*
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // Sliding window will work for +ve values not for -ve Values
        // Since the range of values are -ve to +ve (Hash Table is our best option rather than using 
        // Sliding Window)
        int n = nums.size();
        int counter = 0, Curr_Sum=0;
        unordered_map<int,int>Curr_Sum_HashFreq; //Hash Table for (Nums,Freq) Pairs
        Curr_Sum_HashFreq[0] = 1;  // Initialize to handle subarrays starting at index 0
        for(int num : nums){
            Curr_Sum+=num;

            // Check if (prefixSum - k) exists in the map
            if(Curr_Sum_HashFreq.find(Curr_Sum - k) != Curr_Sum_HashFreq.end()){
                counter+=Curr_Sum_HashFreq[Curr_Sum - k];
            }

            // Store the current prefix sum in the hash map
            Curr_Sum_HashFreq[Curr_Sum]++;
        }
        return counter;
  }
};


*/