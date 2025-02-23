/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        // Queue for BFS: pair of nested list and current depth
        queue<pair<vector<NestedInteger>, int>> BFS_Q_Reverse;
        vector<vector<int>> Result_Vec;
        int Total_Sum = 0;

        // Start with the root nested list at depth 1
        BFS_Q_Reverse.push({nestedList, 1});

        // Perform BFS
        while (!BFS_Q_Reverse.empty()) {
            auto [currentList, depth] = BFS_Q_Reverse.front();
            BFS_Q_Reverse.pop();

            // Ensure Result_Vec can hold this depth
            if (Result_Vec.size() < depth) {
                Result_Vec.resize(depth);
            }

            // Process each element in the current list
            for (auto& x : currentList) {
                if (x.isInteger()) {
                    Result_Vec[depth - 1].push_back(x.getInteger());
                } else {
                    BFS_Q_Reverse.push({x.getList(), depth + 1});
                }
            }
        }

        int maxDepth = Result_Vec.size();

        for (int depth = 0; depth < maxDepth; ++depth) {
            for (int val : Result_Vec[depth]) {
                Total_Sum += val * (maxDepth - depth);
            }
        }

        return Total_Sum;
        
    }
};