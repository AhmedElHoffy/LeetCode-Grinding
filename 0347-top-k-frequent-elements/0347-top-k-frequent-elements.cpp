class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>FreqMap;
        vector<int>Result;
        for(int num : nums){
            FreqMap[num]++;
        }

        /*
        // Approach 1: Priorit Queue of Pairs
        priority_queue<pair<int,int>>PQ;

        for(const auto& it : FreqMap){
            PQ.push({it.second,it.first});
        }
        
        while(k--){
            Result.push_back(PQ.top().second);
            PQ.pop();
        }
        */

        //Approach 2: Modified Bucket Sort --> Time: O(n)
        vector<vector<int>>Buckets(n+1);
        int n2 = Buckets.size();

        for(const auto& it : FreqMap){
            Buckets[it.second].push_back(it.first);
        }

        for(int j=n2-1 ; j>=0 && Result.size() < k ; j--){
            for(int num : Buckets[j]){
                Result.push_back(num);
                if (Result.size() == k) break; // Stop if we have collected k elements
            }
        }

        return Result;
    }
};

















/*
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>FreqMap;
        int n = nums.size();
        for(int num : nums){
            FreqMap[num]++;
        }


        // Approach,1 Vector of pairs

        /*vector<pair<int,int>> FreqVec(FreqMap.begin(),FreqMap.end());

        sort(FreqVec.begin(),FreqVec.end(),[] (const pair<int,int>&a , const pair<int,int>&b){
            return a.second > b.second; // Descending Freq;
        });
        
        vector<int>Result;
        for(int i = 0 ; i < k ; i++){
            Result.push_back(FreqVec[i].first);
        }
        */

        // Approach 2 : Priority Queue of Pairs

        /*
        priority_queue<pair<int,int>>PQ_Freq;

        for( auto it: FreqMap){
            PQ_Freq.push({it.second,it.first}); // Inserted based on Freq 
                                                // (Ascernding order where top is the highest freq)
        }
        vector<int>Result;
        for(int i=0 ; i < k ; i++){
            Result.push_back(PQ_Freq.top().second);
            PQ_Freq.pop();
        }
        return Result;
        */

        // Approach 3: Bucket Sort
/*
        // Creatign Bucket Vector 
        vector<vector<int>>Buckets(n+1); // size will original vector size + 1 (to take in consideration that 
                                         // vector statrs at Idx 0 and reach max most probable Freq occorunce)
        for( const auto it : FreqMap){
            Buckets[it.second].push_back(it.first);
        }

        // Collect Top K Freq Elements from Bucket
        vector<int>Result;
        for(int j=Buckets.size()-1 ; j>=0 && Result.size() < k ; j--){
            for (int num : Buckets[j]){ // Only execute if Bucket[i] is non-empty
                Result.push_back(num);
                if (Result.size() == k) break; // Stop if we have collected k elements
            }
        }
        return Result;
    }
};

*/