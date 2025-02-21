class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        long long Result = 0;

        // w Min heap for candidates from left and right side
        priority_queue< pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>> >Left_MinHeap,Right_MinHeap;

        int Left_Ptr=0, Right_Ptr = n-1;

        for(int i=0; i < candidates && Left_Ptr<=Right_Ptr ;i++,Left_Ptr++){
            Left_MinHeap.push({costs[Left_Ptr],Left_Ptr});
        }

        for(int i=0; i < candidates && Left_Ptr<=Right_Ptr ;i++,Right_Ptr--){
            Right_MinHeap.push({costs[Right_Ptr],Right_Ptr});
        }

        while (k>0){
            pair<int,int>Worker;

            if( (!Left_MinHeap.empty() && (Right_MinHeap.empty() || Left_MinHeap.top().first <=Right_MinHeap.top().first)) ){
                Worker = Left_MinHeap.top();
                Left_MinHeap.pop();
                if(Left_Ptr<=Right_Ptr){
                    Left_MinHeap.push({costs[Left_Ptr],Left_Ptr});
                    Left_Ptr++;
                }

            }else{
                 Worker = Right_MinHeap.top();
                Right_MinHeap.pop();
                if(Left_Ptr<=Right_Ptr){
                    Right_MinHeap.push({costs[Right_Ptr],Right_Ptr});
                    Right_Ptr--;
                }
            }
            Result+=Worker.first;
            k--;
        }
        return  Result;
    }
};

















/*

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        long long total_costs = 0;

        // Indices for moving inward
        int LeftIdx = candidates;
        int RightIdx = n - candidates - 1;

        // Min-heap to store {cost, side ('L' or 'R')}
        priority_queue<pair<long long, char>, vector<pair<long long, char>>, greater<pair<long long, char>>> Min_Heap;

        // Add the first `candidates` workers from the left
        for (int i = 0; i < candidates; i++) {
            Min_Heap.push({costs[i], 'L'});
        }

        // Add the last `candidates` workers from the right
        for (int j = n - 1; j >= n - candidates && j >= candidates; j--) {
            Min_Heap.push({costs[j], 'R'});
        }

        // Perform k hiring rounds
        while (k > 0) {
            // Get the worker with the lowest cost
            auto MinCost = Min_Heap.top();
            Min_Heap.pop();

            // Add the cost to the total
            total_costs += MinCost.first;

            // If the worker came from the left side
            if (MinCost.second == 'L' && LeftIdx <= RightIdx) {
                Min_Heap.push({costs[LeftIdx], 'L'});
                LeftIdx++;
            }
            // If the worker came from the right side
            else if (MinCost.second == 'R' && LeftIdx <= RightIdx) {
                Min_Heap.push({costs[RightIdx], 'R'});
                RightIdx--;
            }

            k--;
        }

        return total_costs;
    }
};

*/