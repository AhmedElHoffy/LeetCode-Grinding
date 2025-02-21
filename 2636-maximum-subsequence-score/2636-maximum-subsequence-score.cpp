class Solution {
public:
long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
    int n = nums1.size();
    priority_queue<pair<int, int>> PQ; // Max-heap sorted by nums2 values
    priority_queue<int, vector<int>, greater<int>> minHeap; // Min-heap to track k largest nums1 values

    // Push all nums2 values with their corresponding index into PQ
    for (int i = 0; i < n; i++) {
        PQ.push({nums2[i], i});
    }

    long long Curr_Sum_Nums1 = 0, Max_Score = 0;

    // Extract the top k elements based on nums2 values
    for (int count = 0; count < k; count++) {
        auto [Num2, Index] = PQ.top();
        PQ.pop();
        
        Curr_Sum_Nums1 += nums1[Index];
        minHeap.push(nums1[Index]); // Track the k largest nums1 values
        
        if (count == k - 1) { // Only compute score when we have k elements
            Max_Score = Curr_Sum_Nums1 * Num2;
        }
    }

    // Now process the rest of the elements to optimize the score
    while (!PQ.empty()) {
        auto [Num2, Index] = PQ.top();
        PQ.pop();
        
        if (nums1[Index] > minHeap.top()) { // Only update if we get a better element
            Curr_Sum_Nums1 += nums1[Index] - minHeap.top();
            minHeap.pop();
            minHeap.push(nums1[Index]);
        }

        Max_Score = max(Max_Score, Curr_Sum_Nums1 * Num2);
    }

    return Max_Score;
}
};

/*

nums1 = [4,2,3,1,1];  nums2 = [7,5,10,9,6] ; 

*/
















/*

class Solution {
private:

public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        // Based on the index
        vector<pair<int,int>>pairs_Array;
        int n = nums1.size();
        // push the pairs of nums1 array and nums2 array in a vector pair array (based on nums2 array);
        for(int i = 0 ; i < n ; i++){
            auto pair = make_pair(nums2[i],nums1[i]);
            pairs_Array.emplace_back(pair);
        }

        // sort based on nums 2 in descending order
        sort(pairs_Array.rbegin(),pairs_Array.rend());

        //Min_Heap to maintain the top k Largest Values from nums1
        priority_queue<int,vector<int>,greater<int>>Min_Heap;
        long long SumNums1 = 0; 
        long long MaxScore = 0;

        //Iterate through sorted pairs
        for(auto & [nums2,nums1] : pairs_Array){
            Min_Heap.push(nums1);
            SumNums1+=nums1;

            // if the Heap size exceeds k, remove the smalles element
            if(Min_Heap.size() > k){
                SumNums1-=Min_Heap.top();
                Min_Heap.pop();
            }

            // If the Heap has exactly K elements , calcualte the Score
            if(Min_Heap.size() == k){
                MaxScore = max(MaxScore, SumNums1 * nums2);
            }
        }
        return MaxScore;
        
    }
};
*/